/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_execution2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmendez- <pmendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 19:27:27 by gsoteldo          #+#    #+#             */
/*   Updated: 2025/03/22 21:18:35 by pmendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	execution_multiple(t_minishell *shell, t_command_list *aux)
{
	if (shell->exec->index == 0)
		first_iteration(shell);
	else if (shell->exec->index == shell->exec->num_cmds - 1)
		last_iteration(shell);
	else
		other_iterations(shell);
	shell->type_command = is_builtin(shell, aux, aux->args[0]);
	if (shell->type_command != 14 && (shell->type_command >= 0 \
	&& shell->type_command <= 7))
		check_builtins(shell);
	else
		execute(shell, aux);
	exit(shell->code);
}

void	execution_process(t_minishell *shell, t_command_list *aux)
{
	handle_redirections(shell, aux);
	if (!init_output(shell))
		return ;
	signal_infunction();
	if (shell->exec->index != 0 && shell->exec->index \
	!= shell->exec->num_cmds - 1 && pipe(shell->exec->pipe_aux) == -1)
		error_no_cmd(RED "Error\n" END "Error create pipe\n", 1, shell);
	shell->exec->pid = fork();
	if (shell->exec->pid == -1)
		error_no_cmd(RED "Error\n" END "Error create child\n", 1, shell);
	else if (shell->exec->pid == 0)
		execution_multiple(shell, aux);
	if (shell->exec->index != 0 && shell->exec->index \
	!= shell->exec->num_cmds - 1)
	{
		close_fd(&shell->exec->pipe_father[READ], \
		"shell->exec->pipe_father[READ]");
		close_fd(&shell->exec->pipe_aux[WRITE], "shell->exec->pipe_aux[WRITE]");
		shell->exec->pipe_father[READ] = shell->exec->pipe_aux[READ];
	}
	shell->exec->index++;
}

void	close_pipe_father(t_minishell *shell)
{
	if (is_fd_open(shell->exec->pipe_father[READ], NULL))
		close_fd(&shell->exec->pipe_father[READ], \
		"shell->exec->pipe_father[READ]");
	if (is_fd_open(shell->exec->pipe_father[WRITE], NULL))
		close_fd(&shell->exec->pipe_father[WRITE], \
		"shell->exec->pipe_father[WRITE]");
}
