/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 22:13:12 by pmendez-          #+#    #+#             */
/*   Updated: 2025/03/10 17:29:22 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void	exec_env(t_minishell *shell)
{
	int	i;

	i = 0;
	if (size_array(shell->command_list->args) > 1)
	{
		ft_printf("env: %s: Too many arguments\n", \
			shell->command_list->args[1]);
		shell->code = 1;
		return ;
	}
	while (shell->envp[i] != NULL)
	{
		if (ft_strchr(shell->envp[i], '='))
			ft_printf("%s\n", shell->envp[i]);
		i++;
	}
}
