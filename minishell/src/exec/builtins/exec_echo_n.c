/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_echo_n.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmendez- <pmendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 01:36:57 by pmendez-          #+#    #+#             */
/*   Updated: 2025/03/14 23:31:24 by pmendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

static int	is_only_n(const char *str)
{
	int	i;

	i = 1;
	if (str[0] != '-')
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] != 'n')
			return (0);
		i++;
	}
	return (1);
}

static char	**skip_echo_n(char **args)
{
	int	i;

	i = 1;
	while (args[i] != NULL)
	{
		if (is_only_n(args[i]) == 1)
			i++;
		else
			break ;
	}
	return (args + i);
}

void	exec_echo_n(t_minishell *shell)
{
	char	**str;
	int		i;
	int		flag;

	i = 0;
	flag = 0;
	str = skip_echo_n(shell->command_list->args);
	if (str != NULL)
	{
		while (str[i] != NULL)
		{
			if (str[i + 1] == NULL)
				flag = 1;
			process_line_in_quotes(shell, str[i], i, flag);
			i++;
		}
	}
}
