/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_echo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 22:12:58 by pmendez-          #+#    #+#             */
/*   Updated: 2025/03/29 19:19:04 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void	process_line_in_quotes(t_minishell *shell, char *str, int i, int flag)
{
	int	j;

	j = 0;
	while (str[j] != '\0')
	{
		ft_printf("%c", str[j]);
		j++;
	}
	if (shell->command_list->args[i] != NULL && flag == 0)
		ft_printf(" ");
}

void	exec_echo(t_minishell *shell)
{
	char	**str;
	int		i;

	i = 1;
	str = shell->command_list->args;
	if (str != NULL)
	{
		while (str[i] != NULL)
		{
			process_line_in_quotes(shell, str[i], i, 0);
			i++;
		}
	}
	ft_printf("\n");
}
