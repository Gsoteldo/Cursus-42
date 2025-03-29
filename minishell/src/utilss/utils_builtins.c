/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_builtins.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 17:22:46 by pmendez-          #+#    #+#             */
/*   Updated: 2025/03/29 19:33:39 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	check_line(char *line)
{
	int	i;

	i = 0;
	if (line[0] == '-')
		i++;
	while (line[i] != '\0')
	{
		if (line[i] != 'n')
			return (0);
		i++;
	}
	return (1);
}

static int	is_echo_n(char **args)
{
	int	i;

	i = 1;
	while (args[i] != NULL)
	{
		if (check_line(args[i]) == 1)
			return (1);
		i++;
	}
	return (0);
}

int	is_builtin(t_minishell *shell, t_command_list *aux, char *line)
{
	int	i;

	i = -1;
	if (aux == NULL)
	{
		aux = shell->command_list;
		line = aux->args[0];
	}
	if (aux->args[0] == NULL)
		return (14);
	if (line[0] == '/' || line[0] == '.')
		return (14);
	if (ft_strstr(aux->args[0], "echo") != 0 && is_echo_n(aux->args) == 1)
		return (1);
	while (++i < size_array(shell->builtins))
	{
		if (ft_strnstr(aux->args[0], shell->builtins[i], \
			ft_strlen(shell->builtins[i])) != 0)
			return (i);
	}
	return (14);
}

void	builtins_init(t_minishell *shell)
{
	char	**builtins;
	char	**old_builtins;
	int		i;

	i = 0;
	shell->builtins = NULL;
	builtins = ft_split("echo:echo -n:pwd:env:cd:export:unset:exit", ':');
	while (builtins[i] != NULL)
	{
		old_builtins = shell->builtins;
		shell->builtins = add_str_double_pointer(shell->builtins, builtins[i]);
		if (old_builtins != NULL)
			free_double_str(old_builtins);
		i++;
	}
	free_double_str(builtins);
}
