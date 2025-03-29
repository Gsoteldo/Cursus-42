/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_execution.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 19:01:02 by pmendez-          #+#    #+#             */
/*   Updated: 2025/03/22 18:53:42 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	free_strings(char **str, char **path, char *cmd)
{
	char	**temp;

	temp = (char *[]){"command not found: ", cmd, NULL};
	if (execve("/usr/lib/command-not-found", temp, NULL) == -1)
	{
		if (str != NULL)
			free_double_str(str);
		if (path != NULL)
			free_double_str(path);
		exit(127);
	}
}

void	do_exec(t_minishell *shell, char **str, char *cmd)
{
	char	*temp;

	temp = NULL;
	if (*str == NULL)
		free_strings(str, shell->path, cmd);
	if ((access(cmd, F_OK | X_OK) == 0) && ft_strnstr(cmd, "./", 2))
	{
		if (execve(cmd, str, shell->envp) == -1)
			free_strings(str, shell->path, cmd);
	}
	else if ((access(str[0], F_OK | X_OK) != 0) && ft_strchr(str[0], '/'))
		free_strings(str, shell->path, cmd);
	else if ((access(str[0], F_OK | X_OK) == 0) && ft_strchr(str[0], '/'))
	{
		if (execve(str[0], str, shell->envp) == -1)
			free_strings(str, shell->path, cmd);
	}
	else
	{
		temp = search_path(shell, str);
		if (temp == NULL || execve(temp, str, shell->envp) == -1)
			free_strings(str, shell->path, cmd);
	}
}

void	execute(t_minishell *shell, t_command_list *aux)
{
	char	**args;
	char	*command_argv;

	if (aux)
	{
		command_argv = aux->command;
		args = aux->args;
	}
	else
	{
		command_argv = shell->command_list->command;
		args = shell->command_list->args;
	}
	if (command_argv != NULL && ft_strcmp(command_argv, ".") == 0)
		print_error("minishell: filename argument required", " [ . ] ", 2);
	if (command_argv == NULL)
		free_strings(args, shell->path, args[0]);
	do_exec(shell, args, args[0]);
}
