/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 03:27:35 by pmendez-          #+#    #+#             */
/*   Updated: 2025/03/22 23:14:43 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	check_number_of_commands(t_minishell *shell)
{
	t_command_list	*aux;

	shell->exec->num_cmds = 1;
	aux = shell->command_list;
	while (aux->next != NULL)
	{
		shell->exec->num_cmds++;
		aux = aux->next;
	}
}

void	expand_variables(t_minishell *shell)
{
	int		i;
	char	*temp;
	char	*aux;

	temp = NULL;
	aux = NULL;
	if (!shell || !shell->command_list || !shell->command_list->args)
		return ;
	i = 0;
	while (shell->command_list->args[i] != NULL)
	{
		temp = shell->command_list->args[i];
		if (ft_strstr(temp, "$") != NULL \
		&& shell->command_list->quotes_type != 1)
		{
			aux = process_line_with_expansion(shell, temp);
			free(shell->command_list->args[i]);
			shell->command_list->args[i] = aux;
		}
		i++;
	}
}

void	execute_multiple_commands(t_minishell *shell)
{
	int				status;
	int				pid;
	t_command_list	*aux;

	status = 0;
	pid = -1;
	aux = shell->command_list;
	shell->exec->index = 0;
	if (pipe(shell->exec->pipe_father) == -1)
		error_no_cmd(RED "Error\n" END "Error creating pipe\n", 1, shell);
	while (shell->exec->index < shell->exec->num_cmds)
	{
		execution_process(shell, aux);
		aux = aux->next;
	}
	close_pipe_father(shell);
	shell->exec->last_pid = shell->exec->pid;
	while (shell->exec->index > 0)
	{
		pid = waitpid(-1, &status, 0);
		if (pid == shell->exec->last_pid)
			shell->code = WEXITSTATUS(status);
		shell->exec->index--;
	}
}

void	free_heredoc_files(t_minishell *shell)
{
	int	i;

	i = 0;
	if (shell->id_hd == 0)
		return ;
	while (i < shell->id_hd)
	{
		if (shell->hd_files[i])
		{
			if (unlink(shell->hd_files[i]) != 0)
				print_no_exit("Error al borrar archivo\n", shell->hd_files[i]);
			free(shell->hd_files[i]);
			shell->hd_files[i] = NULL;
		}
		i++;
	}
	shell->id_hd = 0;
}

void	handle_exec_command(t_minishell *shell)
{
	check_number_of_commands(shell);
	expand_variables(shell);
	init_redirections(shell);
	if (shell->command_list == NULL)
	{
		free_command_list(shell);
		reset_execution(shell);
		return ;
	}
	if (g_signal == SIGINT)
	{
		g_signal = 0;
		reset_execution(shell);
		return ;
	}
	if (shell->exec->num_cmds == 1)
		exec_command_alone(shell);
	else
		execute_multiple_commands(shell);
	initialize_signals();
	free_heredoc_files(shell);
	reset_execution(shell);
}
