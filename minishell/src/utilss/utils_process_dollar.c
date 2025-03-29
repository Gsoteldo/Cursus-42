/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_process_dollar.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 15:19:05 by pmendez-          #+#    #+#             */
/*   Updated: 2025/03/21 21:55:17 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static char	*get_aux2_substring(char *temp)
{
	char	*aux2;
	int		i;

	i = 0;
	while (temp[i] != '\0' && !ft_isalnum(temp[i]) && temp[i] != '$')
		i++;
	aux2 = ft_substr(temp, 0, i);
	return (aux2);
}

static char	*join_aux(char *line, char *temp, char *aux, char *str)
{
	char	*result;
	char	*aux2;

	result = NULL;
	aux2 = get_aux2_substring(temp);
	if (aux != NULL)
	{
		if ((aux[0] == temp[0] && line[ft_strlen(line)] != temp[0])
			|| (aux[ft_strlen(aux)] != temp[0]
				&& line[ft_strlen(line)] == temp[0]))
		{
			result = ft_strjoin(line, aux);
			if (result == NULL)
				return (NULL);
		}
		else
			result = ft_strjoin_variadica(3, line, aux2, aux);
		free(aux);
	}
	else
		result = ft_strjoin_variadica(3, line, aux2, temp + ft_strlen(str) + 2);
	free(aux2);
	return (result);
}

static char	*process_final_line(char *line, char *temp)
{
	char	*new_line;

	if (temp)
	{
		new_line = ft_strdup(temp);
		if (new_line == NULL)
			return (NULL);
		free(temp);
	}
	else
		new_line = ft_strdup(line);
	return (new_line);
}

char	*expansion_dollar(char *line, char *temp, char *aux, char *line_aux)
{
	char	*aux2;

	aux2 = NULL;
	if (line == NULL)
		return (NULL);
	temp = join_aux(line, temp, aux, line_aux);
	free(aux2);
	line = process_final_line(line, temp);
	return (line);
}
