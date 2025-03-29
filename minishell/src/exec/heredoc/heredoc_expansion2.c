/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_expansion2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmendez- <pmendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 20:08:24 by pmendez-          #+#    #+#             */
/*   Updated: 2025/03/23 00:05:05 by pmendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

static void	temp_exists(char *line, int *j, char **fusion, char *temp)
{
	char	*old_fusion;

	old_fusion = *fusion;
	*fusion = ft_strjoin(*fusion, temp);
	if (old_fusion)
		free(old_fusion);
	if (temp)
		free(temp);
	while (line[*j] != '\0' && line[*j + 1] != '\0'
		&& !is_delimiter(line[*j + 1]))
		(*j)++;
}

char	*treat_expansion(t_minishell *shell, char *line, char *fusion, int *j)
{
	char	*old_fusion;
	char	*temp;
	char	*new_fusion;

	old_fusion = NULL;
	temp = expansion_heredoc(shell, j, line);
	if (temp != NULL && shell->exec->var_not_found == 0)
		temp_exists(line, j, &fusion, temp);
	else
	{
		if (ft_strlen(fusion) == 0)
			new_fusion = temp_null(line, ft_strlen(fusion), j, line);
		else
			new_fusion = temp_null(fusion, ft_strlen(fusion), j, line);
		shell->exec->var_not_found = 1;
		if (fusion)
			free(fusion);
		fusion = ft_strdup(new_fusion);
		if (new_fusion)
			free(new_fusion);
		if (temp)
			free(temp);
	}
	return (fusion);
}
