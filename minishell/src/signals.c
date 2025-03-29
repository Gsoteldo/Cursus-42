/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 18:47:27 by gsoteldo          #+#    #+#             */
/*   Updated: 2025/03/21 22:49:07 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <sys/ioctl.h>
#include "../include/minishell.h"

void	initialize_signals(void)
{
	struct sigaction	new_line;
	struct sigaction	quit;

	sigemptyset(&new_line.sa_mask);
	ft_memset(&new_line, 0, sizeof(new_line));
	new_line.sa_handler = &signal_handler;
	new_line.sa_flags = 0;
	sigaction(SIGINT, &new_line, NULL);
	sigemptyset(&quit.sa_mask);
	ft_memset(&quit, 0, sizeof(quit));
	quit.sa_handler = SIG_IGN;
	quit.sa_flags = 0;
	sigaction(SIGQUIT, &quit, NULL);
}

void	signal_handler(int signum)
{
	if (signum == SIGINT)
	{
		write(1, "\n", 1);
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
		g_signal = SIGINT;
	}
}

void	shellexception(void)
{
	struct sigaction	except;

	sigemptyset(&except.sa_mask);
	ft_memset(&except, 0, sizeof(except));
	except.sa_handler = SIG_IGN;
	except.sa_flags = 0;
	sigaction(SIGINT, &except, NULL);
	sigaction(SIGQUIT, &except, NULL);
}

void	increase_shlvl(t_minishell *shell)
{
	int		i;
	int		actual_shlvl;
	char	*new_shlvl;
	char	*tmp;

	i = -1;
	while (shell->envp[++i])
	{
		if (ft_strncmp(shell->envp[i], "SHLVL=", 6) == 0)
		{
			actual_shlvl = ft_atoi(shell->envp[i] + 6);
			actual_shlvl++;
			new_shlvl = ft_itoa(actual_shlvl);
			if (!new_shlvl)
				error_no_cmd("Error: malloc failed\n", 1, shell);
			tmp = ft_strjoin("SHLVL=", new_shlvl);
			if (!tmp)
				(free(new_shlvl), \
				error_no_cmd("Error: malloc failed\n", 1, shell));
			(free(new_shlvl), free(shell->envp[i]));
			shell->envp[i] = tmp;
			break ;
		}
	}
}

int	is_shellexception(char **args, t_minishell *shell)
{
	char	*command;
	int		i;

	i = 0;
	(void)shell;
	if (args)
	{
		while (args[i])
		{
			command = ft_strnstr(args[i], "/minishell", ft_strlen(args[i]));
			if (command)
			{
				shellexception();
				return (1);
			}
			i++;
		}
	}
	return (0);
}
