/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_signals.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 22:21:02 by gsoteldo          #+#    #+#             */
/*   Updated: 2025/03/22 20:52:17 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <sys/ioctl.h>
#include "../../include/minishell.h"

void	here_doc(int signum)
{
	rl_on_new_line();
	ioctl(0, TIOCSTI, "\n");
	g_signal = signum;
}

void	signal_heredoc(void)
{
	struct sigaction	heredoc;

	sigemptyset(&heredoc.sa_mask);
	ft_memset(&heredoc, 0, sizeof(heredoc));
	heredoc.sa_handler = &here_doc;
	heredoc.sa_flags = 0;
	sigaction(SIGINT, &heredoc, NULL);
	signal(SIGQUIT, SIG_IGN);
}

void	infuncion(int signum)
{
	rl_on_new_line();
	if (signum == SIGQUIT)
		printf("Quit (core dumped)\n");
	g_signal = signum;
}

void	signal_infunction(void)
{
	struct sigaction	in_func;

	sigemptyset(&in_func.sa_mask);
	ft_memset(&in_func, 0, sizeof(in_func));
	in_func.sa_handler = &infuncion;
	in_func.sa_flags = 0;
	sigaction(SIGINT, &in_func, NULL);
	sigaction(SIGQUIT, &in_func, NULL);
}

int	check_signal(t_minishell *shell, char *line, t_command_list *new)
{
	if (g_signal)
	{
		shell->code = 130;
		close(new->fd_heredoc);
		new->fd_heredoc = -1;
		free(line);
		write(1, "\n", 1);
		return (0);
	}
	return (1);
}
