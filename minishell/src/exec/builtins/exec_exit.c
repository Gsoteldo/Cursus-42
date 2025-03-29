/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 22:13:20 by pmendez-          #+#    #+#             */
/*   Updated: 2025/03/21 16:17:43 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

static int	check_if_number(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] != '-')
			return (0);
		i++;
	}
	return (1);
}

void	exec_exit(t_minishell *shell)
{
	char	*str;

	printf("exit\n");
	if (!shell)
		exit(3);
	if (size_array(shell->command_list->args) > 2)
	{
		printf(RED "Error\n" END "exit: too many arguments\n");
		shell->code = 127;
		return ;
	}
	if (!shell->command_list->args[1])
		shell->code = 0;
	else if ((check_if_number(shell->command_list->args[1]) == 1))
		shell->code = ft_atoi(shell->command_list->args[1]);
	else
	{
		str = shell->command_list->args[1];
		printf(RED "Error\n" END "exit: %s: numeric argument required\n", str);
		shell->code = 2;
		return ;
	}
	close_all_fds(shell);
	free_all_shell(shell);
	exit(shell->code);
}
