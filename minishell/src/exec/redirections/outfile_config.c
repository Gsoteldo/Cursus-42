/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outfile_config.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 20:17:24 by gsoteldo          #+#    #+#             */
/*   Updated: 2025/03/29 19:34:05 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

//TODO: Comprobar archivos exec_utils de minishell de prueba.  

/**
 * *Importante, esto es lo que hacen las funciones de ee archivo
 * * 1ª Funcion: set_up_outfiles -> Va a buscar el archivo dentro de la carpeta 
 * * actual y va a guardar su file descriptor (fd)
 * * 2ª Funcion: set_up_ouptut -> Va a configurar a donde va a ir la salida del
 * * archivo (Tanto s es redireccion como si no)
 * * 3ª Funcion: init_outlst_loop -> Va a inicializar la configuración de
 * * entrada y salida para un comando.
 * 
 * *Importante para el futuro:
 * * Funcion save_last_exit_statue -> Guarda el estado de salida del último
 * * comando y 
 * * decide si continuar según operadores como && o ||.
 * 
 * * Funcion init_exec_cmd -> Prepara la ejecución de un comando, sea un comando
 * * del sistema o un binario.
 */

char	*path_redirection_file(char *actual_path, char *file)
{
	int		i;
	int		j;
	char	*path;

	i = 0;
	j = 0;
	path = ft_calloc(sizeof(char), (ft_strlen(actual_path) \
		+ (ft_strlen(file) + 2)));
	if (!path)
		return (NULL);
	while (actual_path[i])
	{
		path[i] = actual_path[i];
		i++;
	}
	path[i] = '/';
	i++;
	while (file[j])
	{
		path[i] = file[j];
		i++;
		j++;
	}
	path[i] = '\0';
	return (path);
}

static int	check_exists_outfile(char *outfile)
{
	if (access(outfile, W_OK) == -1)
	{
		print_no_exit(RED "Error\n" END "Permission Denied", outfile);
		return (0);
	}
	return (1);
}

static int	preparation_outfile(t_minishell *shell, t_outfile *tmp)
{
	char	*actual_path;
	char	*path;
	char	*outfile_name;
	int		previous_fd;

	outfile_name = tmp->outfile;
	path = NULL;
	if (!tmp->outfile)
		return (0);
	actual_path = ft_get_env(shell, "PWD");
	path = path_redirection_file(actual_path, outfile_name);
	if (!path)
		return (free(path), 0);
	previous_fd = shell->exec->output;
	if (tmp->type == WRITE_OUTFILE)
		shell->exec->output = open(path, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	else if (tmp->type == APPEND_OUTFILE)
		shell->exec->output = open(path, O_CREAT | O_WRONLY | O_APPEND, 0644);
	if (!check_exists_outfile(path))
	{
		free(path);
		if (previous_fd != -1)
			close_fd(&previous_fd, "previous_fd");
		return (0);
	}
	shell->command_list->outfile->type = tmp->type;
	if (previous_fd != -1)
		close_fd(&previous_fd, "previous_fd");
	free(path);
	return (1);
}

int	preparation_output(t_minishell *shell)
{
	t_outfile	*tmp;

	tmp = shell->command_list->outfile;
	if (shell->command_list->todo_next != 3)
	{
		if (tmp && tmp->outfile)
		{
			while (tmp)
			{
				if (!preparation_outfile(shell, tmp))
					return (0);
				tmp = tmp->next;
			}
		}
		else
			shell->exec->output = dup(shell->exec->tmp_out);
	}
	else
	{
		shell->exec->output = shell->exec->pipe_father[WRITE];
		shell->exec->input = shell->exec->pipe_father[READ];
	}
	return (1);
}

int	init_output(t_minishell *shell)
{
	int	num_cmds;

	num_cmds = shell->exec->num_cmds;
	if (shell->command_list->outfile)
	{
		if (ft_strcmp(shell->command_list->outfile->outfile, "\"\"") == 0 \
		|| ft_strcmp(shell->command_list->outfile->outfile, "''") == 0)
		{
			print_no_exit(RED "Error\n" END "No file or directory", "quotes");
			shell->code = 1;
			return (0);
		}
	}
	if (!preparation_output(shell))
	{
		shell->code = 1;
		return (0);
	}
	if (num_cmds == 1 && shell->exec->output != -1)
	{
		if (dup2(shell->exec->output, STDOUT_FILENO) < 0)
			error_no_cmd("Error: dup2 failed", 1, shell);
		close_fd(&shell->exec->output, "shell->exec->output");
	}
	return (1);
}
