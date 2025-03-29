/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_expansion_env.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmendez- <pmendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 15:18:23 by pmendez-          #+#    #+#             */
/*   Updated: 2025/03/23 00:20:57 by pmendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static char	*var_not_found(t_minishell *shell)
{
	shell->exec->var_not_found = 1;
	return (NULL);
}

static char	*safe_strdup(t_minishell *shell, char *temp, char *line, char *aux)
{
	char	*old_line;

	old_line = line;
	line = case_dollar(shell, temp, line, aux);
	if (old_line)
		free(old_line);
	return (line);
}

static char	*else_no_expansion(char *str, int *j, char *line, char *aux)
{
	char	*old_line;

	old_line = line;
	line = string_without_expansion(str, j, line, aux);
	if (line == NULL)
	{
		if (old_line)
			free(old_line);
		return (NULL);
	}
	while (str[*j + 1] != '\0' && !is_delimiter(str[*j]))
		(*j)++;
	return (line);
}

static char	*handle_env_var(t_minishell *shell, char *str, int *j, char *aux)
{
	char	*temp;
	char	*line;

	temp = ft_get_env(shell, aux);
	if (temp == NULL)
		return (var_not_found(shell));
	line = ft_strdup(temp);
	shell->exec->index_expansion = *j + 1 + ft_strlen(aux);
	if (!str || shell->exec->index_expansion >= (int)ft_strlen(str))
		return (safe_strdup_line(line));
	temp = str + shell->exec->index_expansion;
	shell->exec->var_not_found = 0;
	if (temp && *temp != ' ' && *temp != '\0')
	{
		if (ft_strstr(temp, "$") != 0)
			line = safe_strdup(shell, temp, line, aux);
		else
			line = else_no_expansion(str, j, line, aux);
	}
	else
		line = safe_strdup_line(line);
	return (line);
}

char	*env(t_minishell *shell, int *j, char *str)
{
	char	*line;
	char	*line_aux;

	line = NULL;
	line_aux = get_variable(str + *j);
	if (is_in_env(line_aux, shell) == 1)
	{
		if (shell->command_list->quotes_type == 2)
			*j = *j + 1;
		line = handle_env_var(shell, str, j, line_aux);
		if (line == NULL)
		{
			if (line_aux)
				free(line_aux);
			return (NULL);
		}
	}
	if (line_aux)
		free(line_aux);
	return (line);
}
