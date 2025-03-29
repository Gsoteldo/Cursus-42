/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_add_array_str.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmendez- <pmendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 20:22:48 by pmendez-          #+#    #+#             */
/*   Updated: 2025/03/23 00:23:10 by pmendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

static char	*create_line(t_minishell *shell, char **temp, char **existing_value)
{
	char	*aux;
	char	*first_join;

	aux = NULL;
	*existing_value = get_whole_env_line(shell, temp[0]);
	first_join = ft_strjoin(temp[0], "=");
	if (first_join == NULL)
		return (NULL);
	if (temp[1] != NULL)
	{
		aux = ft_strjoin(first_join, temp[1]);
		free(first_join);
		if (aux == NULL)
			return (NULL);
	}
	else
		aux = first_join;
	return (aux);
}

char	**other_func(t_minishell *shell, char **temp, char **aux, char **value)
{
	char	**new_envp;
	int		size;

	shell->exec->flag = 0;
	*value = get_whole_env_line(shell, temp[0]);
	*aux = create_line(shell, temp, value);
	size = size_array(shell->envp);
	new_envp = ft_calloc(size + 2, sizeof(char *));
	if (!new_envp)
	{
		free(aux);
		return (shell->envp);
	}
	return (new_envp);
}

static char	**found_flag(t_minishell *shell, char **new_envp, char *aux)
{
	if (!shell->exec->flag)
	{
		new_envp[size_array(shell->envp)] = aux;
		new_envp[size_array(shell->envp) + 1] = NULL;
	}
	else
		free(aux);
	free_double_str(shell->envp);
	return (new_envp);
}

static char	**not_found_line(char **new_envp, char *aux, char **envp)
{
	free_double_str(new_envp);
	free(aux);
	return (envp);
}

char	**add_array_str(t_minishell *shell, char **envp, char **temp, int size)
{
	char	*aux;
	char	*existing_value;
	int		i;
	char	**new_envp;

	i = -1;
	aux = NULL;
	existing_value = NULL;
	size = ft_strlen(temp[0]);
	new_envp = other_func(shell, temp, &aux, &existing_value);
	while (++i < size_array(envp))
	{
		if (existing_value != NULL && ft_strcmp(envp[i], temp[0]) == 0
			&& (envp[i][size] == '=' || envp[i][size] == '\0'))
		{
			free(new_envp[i]);
			new_envp[i] = ft_strdup(aux);
			shell->exec->flag = 1;
		}
		else
			new_envp[i] = ft_strdup(envp[i]);
		if (!new_envp[i])
			return (not_found_line(new_envp, aux, envp));
	}
	return (found_flag(shell, new_envp, aux));
}
