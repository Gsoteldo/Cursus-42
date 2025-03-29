/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_export_word_only.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmendez- <pmendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 20:00:15 by pmendez-          #+#    #+#             */
/*   Updated: 2025/03/22 20:21:49 by pmendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

char	**ft_sort_array(char **envp)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	j = 0;
	while (envp[i] != NULL)
	{
		j = i + 1;
		while (envp[j] != NULL)
		{
			if (ft_strncmp(envp[i], envp[j], ft_strlen(envp[i])) > 0)
			{
				temp = envp[i];
				envp[i] = envp[j];
				envp[j] = temp;
			}
			j++;
		}
		i++;
	}
	return (envp);
}

void	exec_word_export_only(t_minishell *shell)
{
	char	**envp_sorted;
	char	**temp;
	int		i;

	i = 0;
	envp_sorted = ft_sort_array(shell->envp);
	while (envp_sorted[i] != NULL)
	{
		if (!ft_strstr(shell->envp[i], "_="))
		{
			if (ft_strchr(envp_sorted[i], '='))
			{
				temp = ft_split(envp_sorted[i], '=');
				if (temp[1] != NULL)
					ft_printf("declare -x %s=\"%s\"\n", temp[0], temp[1]);
				else
					ft_printf("declare -x %s=\"\"\n", temp[0]);
				free_double_str(temp);
			}
			else
				ft_printf("declare -x %s\n", envp_sorted[i]);
		}
		i++;
	}
}

int	is_valid_format(char **temp, char *str)
{
	int	i;

	i = 0;
	if (temp[0] != NULL && !ft_isalpha(temp[0][0]))
		return (0);
	else if (temp[0] != NULL && str[0] == '=')
		return (0);
	else if (ft_strcmp(str, "=") == 0)
		return (0);
	else if (temp[0] != NULL)
	{
		while (temp[0][i] != '\0')
		{
			if (!ft_isalnum(temp[0][i]) && temp[0][i] != '_')
				return (0);
			i++;
		}
	}
	return (1);
}
