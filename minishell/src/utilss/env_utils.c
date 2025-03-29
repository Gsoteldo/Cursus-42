/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmendez- <pmendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 17:42:47 by pmendez-          #+#    #+#             */
/*   Updated: 2025/03/23 00:20:25 by pmendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*case_dollar(t_minishell *shell, char *temp, char *line, char *aux)
{
	char	*str;

	str = NULL;
	if (!ft_isalnum(temp[0]) && temp[0] != '$' && temp[0] != ' ')
	{
		str = process_line_with_expansion(shell, temp);
		line = expansion_dollar(line, temp, str, aux);
	}
	else if (temp[0] == '$')
	{
		str = process_line_with_expansion(shell, temp);
		temp = ft_strjoin(line, str);
		if (line != NULL)
			free(line);
		line = temp;
	}
	return (line);
}

char	*safe_strdup_line(char *line)
{
	char	*old_line;

	old_line = line;
	line = ft_strdup(line);
	if (old_line)
		free(old_line);
	return (line);
}

char	*string_without_expansion(char *str, int *j, char *line, char *aux)
{
	char	*temp;
	size_t	index;

	temp = NULL;
	index = *j + 1 + ft_strlen(aux);
	if (!str || !line)
		return (NULL);
	if (index > ft_strlen(str))
	{
		temp = ft_strdup(line);
		return (temp);
	}
	if (is_delimiter(str[*j + 1 + ft_strlen(aux)]))
		temp = safe_strdup_line(line);
	else
	{
		temp = ft_strjoin(line, str + *j + 1 + ft_strlen(aux));
		if (line)
			free(line);
		if (temp == NULL)
			return (NULL);
	}
	return (temp);
}
