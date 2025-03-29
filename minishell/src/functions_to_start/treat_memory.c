/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 16:04:16 by pmendez-          #+#    #+#             */
/*   Updated: 2025/03/22 20:50:03 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/**
 * Inicializa la estructura `t_command_list` con valores predeterminados.
 * 
 * La función `initialize_command_list` asigna valores predeterminados a la
 * estructura `t_command_list` que se utiliza para gestionar la lista de
 * comandos. Inicializa los punteros `args`, `command`, `infile`,
 * `heredoc_delimiter` y `outfile` a NULL,
 * el entero `todo_next` a -1 y el puntero `next` a NULL.
 * 
 * @param command_list: Un puntero a la estructura `t_command_list` que se
 * inicializa.
 * @return void
 */
static int	initialize_command_list(t_command_list **command_list)
{
	(*command_list) = (t_command_list *)ft_calloc(1, sizeof(t_command_list));
	if ((*command_list) == NULL)
	{
		print_error("Error: malloc failed for command_list\n", NULL, 1);
		return (0);
	}
	(*command_list)->args = NULL;
	(*command_list)->command = NULL;
	(*command_list)->infile = NULL;
	(*command_list)->heredoc_delimiter = NULL;
	(*command_list)->fd_heredoc = -1;
	(*command_list)->is_heredoc = 0;
	(*command_list)->quotes_type = 0;
	(*command_list)->is_heredoc = 0;
	(*command_list)->outfile = (t_outfile *)ft_calloc(1, sizeof(t_outfile));
	(*command_list)->todo_next = -1;
	(*command_list)->next = NULL;
	return (1);
}

static void	initialize_exec_2(t_exec **exec)
{
	(*exec)->var_not_found = 0;
	(*exec)->infile = NULL;
	(*exec)->outfile = NULL;
	(*exec)->output_type = 0;
	(*exec)->index = 0;
	(*exec)->num_cmds = 0;
	(*exec)->input_redirection = 0;
	(*exec)->output_redirection = 0;
	(*exec)->there_is_heredoc = 0;
	(*exec)->index_expansion = 0;
}

/**
  * Inicializa la estructura `t_exec` con valores predeterminados.
  * 
  * La función `initialize_exec` asigna valores predeterminados a la
  * estructura `t_exec` que se utiliza para gestionar la ejecución de
  * comandos. Inicializa los punteros `cmd`, `args`, `infile`, `outfile`
  * y `heredoc_delimiter` a NULL,
  * el entero `type` a -1 y el puntero `next` a NULL.
  * 
  * @param exec: Un puntero a la estructura `t_exec` que se inicializa.
  * @return void
  */
static void	initialize_exec(t_exec **exec)
{
	(*exec) = (t_exec *)ft_calloc(1, sizeof(t_exec));
	if (exec == NULL)
	{
		print_error("Error: malloc failed for exec\n", NULL, 1);
		return ;
	}
	(*exec)->fd[WRITE] = -1;
	(*exec)->fd[READ] = -1;
	(*exec)->fd_temporal[WRITE] = -1;
	(*exec)->fd_temporal[READ] = -1;
	(*exec)->pipe_father[READ] = -1;
	(*exec)->pipe_father[WRITE] = -1;
	(*exec)->pipe_aux[READ] = -1;
	(*exec)->pipe_aux[WRITE] = -1;
	(*exec)->pid = -1;
	(*exec)->last_pid = -1;
	(*exec)->input = -1;
	(*exec)->output = -1;
	(*exec)->tmp_in = -1;
	(*exec)->tmp_out = -1;
	initialize_exec_2(exec);
}

static void	get_static_envp(t_minishell *shell)
{
	char	*pwd;

	pwd = getcwd(NULL, 0);
	shell->envp = (char **)ft_calloc(3, sizeof(char *));
	shell->envp[0] = ft_strjoin("PWD=", pwd);
	if (shell->envp[0] == NULL)
	{
		print_error("Error: malloc failed for envp[0]\n", NULL, 1);
		return ;
	}
	free(pwd);
	shell->envp[1] = ft_strdup("SHLVL=1");
	shell->envp[2] = NULL;
}

/**
 * Inicializa la estructura `t_minishell` con valores predeterminados.
 * 
 * La función `initialize_struct` asigna valores predeterminados a la estructura
 * `t_minishell` que se utiliza para gestionar el estado y el flujo del shell.
 * Inicializa el puntero de línea a NULL y el array de variables de entorno
 * con el valor pasado como argumento. Luego, llama a la función `get_path`
 * para obtener la lista de rutas de acceso y la asigna al puntero `path` de la
 * estructura `t_minishell`.
 * 
 * @param shell: Un puntero a la estructura `t_minishell` que se inicializa.
 * @param envp: Un puntero a un array de strings que contiene las variables de
 * entorno.
 */
void	initialize_struct(t_minishell *shell, char **envp)
{
	shell->code = 0;
	shell->line = NULL;
	shell->envp = obtain_env_to_envp_array(envp);
	shell->builtins = NULL;
	shell->id_hd = 0;
	shell->hd_files = NULL;
	if (shell->envp == NULL)
		get_static_envp(shell);
	shell->path = get_path(shell->envp);
	if (!initialize_command_list(&shell->command_list))
	{
		ft_printf("Error: failed to initialize command_list\n");
		(free_double_str(shell->envp), free_double_str(shell->path));
		return ;
	}
	initialize_exec(&shell->exec);
	builtins_init(shell);
	if (!shell->builtins)
	{
		ft_printf("Error: failed to initialize builtins\n");
		(free_double_str(shell->envp), free_double_str(shell->path));
		free_command_list(shell);
		return ;
	}
}
