/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_expansion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmendez- <pmendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 13:56:59 by pmendez-          #+#    #+#             */
/*   Updated: 2025/03/23 00:21:50 by pmendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

static char	*case_space(char *line)
{
	char	*temp;
	char	*old_fusion;

	temp = ft_strdup(" ");
	if (temp == NULL)
		return (NULL);
	old_fusion = line;
	line = ft_strjoin(line, temp);
	if (old_fusion)
		free(old_fusion);
	free(temp);
	return (line);
}

static char	*treat_line(int var_not_found, char *line, char *fusion, int j)
{
	char	*old_fusion;
	char	*temp;

	temp = NULL;
	old_fusion = NULL;
	if (var_not_found == 1 && fusion != NULL)
		return (fusion);
	if (fusion && fusion[0] != '\0')
	{
		old_fusion = fusion;
		fusion = ft_strjoin(fusion, line + j);
		if (!fusion)
		{
			if (old_fusion)
				free(old_fusion);
			return (NULL);
		}
		if (old_fusion)
			free(old_fusion);
		temp = ft_strdup(fusion);
		if (fusion)
			free(fusion);
	}
	return (temp);
}

static char	*other_cases(char *line, int j, char *fusion)
{
	char	*temp;
	char	*old_fusion;

	temp = NULL;
	old_fusion = NULL;
	if (line[j] == ' ')
	{
		temp = ft_strdup(" ");
		if (temp == NULL)
			return (NULL);
	}
	else
	{
		temp = ft_substr(line, j, 1);
		if (temp == NULL)
			return (NULL);
	}
	old_fusion = fusion;
	fusion = ft_strjoin(fusion, temp);
	if (old_fusion)
		free(old_fusion);
	if (temp)
		free(temp);
	return (fusion);
}

char	*temp_null(char *line, int aux, int *j, char *line_original)
{
	char	*fusion;

	fusion = NULL;
	if (aux == 0)
	{
		fusion = ft_strdup(" ");
		if (fusion == NULL)
			return (NULL);
	}
	else
	{
		fusion = ft_substr(line, 0, aux);
		if (fusion == NULL)
			return (NULL);
	}
	while (line_original[*j] != '\0' && !is_delimiter(line_original[*j]))
		(*j)++;
	if (is_delimiter(line_original[*j]) && line_original[*j + 1] != '\0')
		(*j)--;
	return (fusion);
}

char	*process_line_with_expansion(t_minishell *shell, char *line)
{
	char	*fusion;
	int		j;

	fusion = ft_strdup("");
	j = 0;
	shell->exec->var_not_found = 0;
	while (line != NULL && line[j] != '\0')
	{
		if (line[j] == '$')
			fusion = treat_expansion(shell, line, fusion, &j);
		else if (line[j] == ' ')
			fusion = case_space(fusion);
		else
			fusion = other_cases(line, j, fusion);
		j++;
	}
	line = treat_line(shell->exec->var_not_found, line, fusion, j);
	return (line);
}
