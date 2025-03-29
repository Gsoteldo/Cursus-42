/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 16:04:22 by pmendez-          #+#    #+#             */
/*   Updated: 2025/03/22 17:44:09 by pmendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/**
 * @brief Cierra un descriptor de archivo y muestra un mensaje de error si
 * ocurre.
 *
 * @param fd Puntero al descriptor de archivo a cerrar.
 * @param name Nombre del archivo asociado al descriptor.
 */
void	close_fd(int *fd, char *name)
{
	char	*str;

	str = NULL;
	if (close(*fd) == -1)
	{
		str = ft_strjoin(RED "Error\n" END "Error closing ", name);
		if (str != NULL)
		{
			ft_printf("%s\n", str);
			free(str);
		}
		else
		{
			ft_printf(RED "Error\n" END "Memory allocation failed");
			free(str);
		}
	}
	*fd = -1;
}

/**
 * @brief Cierra todos los descriptores de archivo de la estructura shell.
 *
 * @param shell Estructura principal del programa.
 */
void	close_all_fds(t_minishell *shell)
{
	if (is_fd_open(shell->exec->fd[READ], "fd[READ]"))
		close_fd(&shell->exec->fd[READ], "fd[READ]");
	if (is_fd_open(shell->exec->fd[WRITE], "fd[WRITE]"))
		close_fd(&shell->exec->fd[WRITE], "fd[WRITE]");
	if (is_fd_open(shell->exec->fd_temporal[READ], "fd_temporal[READ]"))
		close_fd(&shell->exec->fd_temporal[READ], "fd_temporal[READ]");
	if (is_fd_open(shell->exec->fd_temporal[WRITE], "fd_temporal[WRITE]"))
		close_fd(&shell->exec->fd_temporal[WRITE], "fd_temporal[WRITE]");
	if (is_fd_open(shell->exec->pipe_father[READ], "pipe_father[READ]"))
		close_fd(&shell->exec->pipe_father[READ], "pipe_father[READ]");
	if (is_fd_open(shell->exec->pipe_father[WRITE], "pipe_father[WRITE]"))
		close_fd(&shell->exec->pipe_father[WRITE], "pipe_father[WRITE]");
	if (is_fd_open(shell->exec->pipe_aux[READ], "pipe_aux[READ]"))
		close_fd(&shell->exec->pipe_aux[READ], "pipe_aux[READ]");
	if (is_fd_open(shell->exec->pipe_aux[WRITE], "pipe_aux[WRITE]"))
		close_fd(&shell->exec->pipe_aux[WRITE], "pipe_aux[WRITE]");
	if (is_fd_open(shell->exec->tmp_in, "tmp_in"))
		close_fd(&shell->exec->tmp_in, "tmp_in");
	if (is_fd_open(shell->exec->tmp_out, "tmp_out"))
		close_fd(&shell->exec->tmp_out, "tmp_out");
}

/**
 * @brief Imprime un mensaje de error que le pasan por parametros
 * fusionado con el comando que se ha intentado ejecutar
 * y ha salido mal. Y finalmente, sale del programa.
 * 
 * No solo eso, sino que antes de hacer un strjoin,
 * comprueba si el comando es NULL, en cuyo caso no hace nada.
 * 
 * Y liberamos la memoria de la cadena que se crea con ft_strjoin.
 * 
 * @param error_message Mensaje de error a imprimir.
 * @param cmd Comando que ha salido mal.
 * @param exitCode Codigo de salida del programa.
 * @return void
 */
void	print_error(char *error_message, char *cmd, int exitCode)
{
	char	*str;

	if (cmd == NULL)
		return ;
	str = ft_strjoin(error_message, cmd);
	ft_putendl_fd(str, 2);
	free(str);
	exit(exitCode);
}

/**
 * @brief Imprime un mensaje de error que le pasan por parametros
 * fusionado con el comando que se ha intentado ejecutar
 * y ha salido mal.
 *
 * No solo eso, sino que antes de hacer un strjoin,
 * comprueba si el comando es NULL, en cuyo caso no hace nada.
 *
 * Y liberamos la memoria de la cadena que se crea con ft_strjoin.
 *
 * @param error_message Mensaje de error a imprimir.
 * @param cmd Comando que ha salido mal.
 * @return void
 */
void	print_no_exit(char *error_message, char *cmd)
{
	char	*str;

	if (cmd == NULL)
		return ;
	str = ft_strjoin_variadica(3, error_message, ": ", cmd);
	if (str == NULL)
	{
		ft_printf(RED "Error\n" END "Memory allocation failed");
		return ;
	}
	ft_putendl_fd(str, 2);
	free(str);
}

/**
 * @brief Imprime un mensaje de error que le pasan por parametros
 * en la salida de error, cierra los pipes y libera la memoria de
 * la estructura shell y finalmente, sale del programa.
 * 
 * @param error_message Mensaje de error a imprimir.
 * @param code Codigo de salida del programa.
 * @param shell Estructura principal del programa.
 * @return void
 */
void	error_no_cmd(char *error_message, int code, t_minishell *shell)
{
	shell->code = code;
	ft_putendl_fd(error_message, 2);
	close_all_fds(shell);
	free_all_shell(shell);
	exit(code);
}
