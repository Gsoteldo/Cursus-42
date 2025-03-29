/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_one_command.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 19:00:42 by pmendez-          #+#    #+#             */
/*   Updated: 2025/03/29 19:16:03 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	check_builtins(t_minishell *shell)
{
	shell->code = 0;
	printf("type_command: %d\n", shell->type_command);
	if (shell->type_command == 0)
		exec_echo(shell);
	else if (shell->type_command == 1)
		exec_echo_n(shell);
	else if (shell->type_command == 2)
		exec_pwd();
	else if (shell->type_command == 3)
		exec_env(shell);
	else if (shell->type_command == 4)
		exec_cd(shell);
	else if (shell->type_command == 5)
		exec_export(shell);
	else if (shell->type_command == 6)
		exec_unset(shell);
	else if (shell->type_command == 7)
		exec_exit(shell);
}

void	child_one_execution(t_minishell *shell, int shceptions)
{
	signal(SIGQUIT, SIG_DFL);
	if (!g_signal)
	{
		if (shceptions == 1)
			increase_shlvl(shell);
		execute(shell, NULL);
	}
	signal(SIGQUIT, SIG_IGN);
	exit(shell->code);
}

void	father_one_execution(t_minishell *shell, int shceptions, \
int status, pid_t pid)
{
	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		shell->code = WEXITSTATUS(status);
	if ((shell->code == 10 || shell->code == 3) && shceptions == 0)
		exit(0);
	if (g_signal)
	{
		shell->code = 130;
		if (g_signal == 3)
			shell->code = 131;
		g_signal = 0;
		return ;
	}
}

void	execute_no_builtin(t_minishell *shell, int shceptions, \
int status, pid_t pid)
{
	pid = fork();
	if (pid == -1)
		error_no_cmd(RED "Error\n" END "Error creating child\n", 1, shell);
	else if (pid == 0)
		child_one_execution(shell, shceptions);
	else
		father_one_execution(shell, shceptions, status, pid);
}

void	exec_command_alone(t_minishell *shell)
{
	int		status;
	pid_t	pid;
	char	*line;
	int		shceptions;

	status = 0;
	pid = 0;
	if (!init_output(shell))
		return ;
	signal_infunction();
	shceptions = is_shellexception(shell->command_list->args, shell);
	if (!shell->command_list->args || !shell->command_list->args[0])
		return ;
	line = shell->command_list->args[0];
	shell->type_command = is_builtin(shell, NULL, line);
	printf("type_command 111: %d\n", shell->type_command);
	if (shell->type_command == 14)
		execute_no_builtin(shell, shceptions, status, pid);
	else
	{
		if (!g_signal)
			check_builtins(shell);
	}
}
