/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 18:27:04 by gsoteldo          #+#    #+#             */
/*   Updated: 2025/03/21 23:02:56 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_outfile	*new_outfile(char *file, int type)
{
	t_outfile	*new;

	new = (t_outfile *)ft_calloc(1, sizeof(t_outfile));
	if (!new)
		return (NULL);
	new->outfile = ft_strdup(file);
	if (!new->outfile)
	{
		free(new);
		return (NULL);
	}
	new->type = type;
	new->next = NULL;
	return (new);
}

void	free_outfile_list(t_outfile *outfile)
{
	t_outfile	*tmp;

	while (outfile)
	{
		tmp = outfile;
		outfile = outfile->next;
		if (tmp->outfile)
			free(tmp->outfile);
		free(tmp);
	}
}

void	free_and_null(char **str)
{
	if (*str)
	{
		free(*str);
		*str = NULL;
	}
}

void	free_command_list(t_minishell *shell)
{
	t_command_list	*tmp;

	if (!shell->command_list)
		return ;
	while (shell->command_list)
	{
		tmp = shell->command_list;
		shell->command_list = shell->command_list->next;
		if (tmp->command)
			free_and_null(&tmp->command);
		if (tmp->args)
		{
			free_double_str(tmp->args);
			tmp->args = NULL;
		}
		if (tmp->infile)
			free_double_str(tmp->infile);
		if (tmp->heredoc_delimiter)
			free(tmp->heredoc_delimiter);
		if (tmp->outfile)
			free_outfile_list(tmp->outfile);
		free(tmp);
	}
}

int	comprobate_quotes(char *comand)
{
	int		simple_q;
	int		double_q;
	char	*quotes_simple;
	char	*quotes_double;
	int		result;

	simple_q = -1;
	double_q = -1;
	result = 0;
	quotes_simple = ft_strchr(comand, '\'');
	quotes_double = ft_strchr(comand, '\"');
	if (quotes_simple)
		simple_q = quotes_simple - comand;
	if (quotes_double)
		double_q = quotes_double - comand;
	if (simple_q != -1 && (simple_q < double_q || double_q == -1))
		result = 1;
	else if (double_q != -1 && (double_q < simple_q || simple_q == -1))
		result = 2;
	return (result);
}
