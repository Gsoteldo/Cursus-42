/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_minishell.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmendez- <pmendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 19:43:30 by gsoteldo          #+#    #+#             */
/*   Updated: 2025/03/23 00:19:28 by pmendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*command_before_parse(t_minishell *shell, char *comand)
{
	shell->line = ft_strtrim(comand, " ");
	if (!shell->line)
		return (0);
	return (shell->line);
}

void	parsing_and_execution(t_minishell *shell, char *comand)
{
	if (shell->line)
		free(shell->line);
	shell->line = command_before_parse(shell, comand);
	if (!shell->line)
	{
		free(comand);
		comand = NULL;
		return ;
	}
	shell->command_list = parsing(shell);
	if (!shell->command_list)
	{
		free(comand);
		comand = NULL;
		return ;
	}
	save_command(shell->line);
	handle_exec_command(shell);
}

void	checking_start_shell(t_minishell *shell, char **line, char **comand)
{
	if (shell->command_list)
		free_command_list(shell);
	check_if_path_removed(shell);
	*line = get_prompt(shell);
	*comand = readline(*line);
	if (!(*comand))
	{
		close_all_fds(shell);
		free(*line);
		rl_clear_history();
		free_all_shell(shell);
		exec_exit(NULL);
	}
}

void	save_command(char *comand)
{
	int	fd;

	add_history(comand);
	if (access(".minishell_history", F_OK) == 0)
		fd = open(".minishell_history", O_RDWR | O_APPEND);
	else
		fd = open(".minishell_history", O_CREAT | O_RDWR, 0644);
	ft_putendl_fd(comand, fd);
	close(fd);
}
