/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmendez- <pmendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 19:29:54 by pmendez-          #+#    #+#             */
/*   Updated: 2025/03/22 19:30:46 by pmendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

static char	**fill_array(t_minishell *shell, char **line, char **aux)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (shell->envp[i] != NULL)
	{
		k = 0;
		while (line[k] != NULL)
		{
			if (ft_strcmp(shell->envp[i], line[k]) == 0)
				break ;
			k++;
		}
		if (line[k] == NULL)
		{
			aux[j] = ft_strdup(shell->envp[i]);
			j++;
		}
		i++;
	}
	aux[j] = NULL;
	return (aux);
}

void	delete_var_envp(t_minishell *shell, char **line)
{
	char	**aux;
	char	**envp;

	envp = shell->envp;
	aux = ft_calloc(size_array(envp) - size_array(line) + 1, sizeof(char *));
	if (!aux)
	{
		shell->code = 1;
		return ;
	}
	aux = fill_array(shell, line, aux);
	free_double_str(shell->envp);
	shell->envp = aux;
}
