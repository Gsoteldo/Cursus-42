/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 12:15:18 by gabo              #+#    #+#             */
/*   Updated: 2025/03/22 18:37:17 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	clear_command_quotes(t_command_list *new)
{
	char	*trimmed;

	trimmed = NULL;
	if (new->command[0] == '\'')
	{
		trimmed = ft_strtrim(new->command, "\'");
		if (trimmed)
		{
			free(new->command);
			new->command = trimmed;
		}
	}
	else if (new->command[0] == '\"')
	{
		trimmed = ft_strtrim(new->command, "\"");
		if (trimmed)
		{
			free(new->command);
			new->command = trimmed;
		}
	}
}

static void	clear_args_quotes(t_command_list *new, int i)
{
	char	**splitted;
	int		quotes_type;

	quotes_type = comprobate_quotes(new->args[i]);
	splitted = NULL;
	if (quotes_type == 1)
	{
		splitted = ft_split(new->args[i], '\'');
		if (splitted)
		{
			add_args_quotes(&new->args, i, splitted);
			free_double_str(splitted);
		}
	}
	else if (quotes_type == 2)
	{
		splitted = ft_split(new->args[i], '\"');
		if (splitted)
		{
			add_args_quotes(&new->args, i, splitted);
			free_double_str(splitted);
		}
	}
}

void	clear_infile_quotes(t_command_list *new, int i)
{
	char	**splitted;
	int		quotes_type;

	quotes_type = comprobate_quotes(new->infile[i]);
	splitted = NULL;
	if (quotes_type == 1)
	{
		splitted = ft_split(new->infile[i], '\'');
		if (splitted)
		{
			add_args_quotes(&new->infile, i, splitted);
			free_double_str(splitted);
		}
	}
	else if (quotes_type == 2)
	{
		splitted = ft_split(new->infile[i], '\"');
		if (splitted)
		{
			add_args_quotes(&new->infile, i, splitted);
			free_double_str(splitted);
		}
	}
}

// void	add_args_outfile(char **outfile, char **splitted)
// {
// 	char	*tmp2;
// 	int		j;

// 	j = 0;
// 	if (!splitted || !splitted[0])
// 		return ;
// 	tmp2 = ft_strdup("");
// 	if (!tmp2)
// 		return ;
// 	if (size_array(splitted) == 1)
// 	{
// 		free(*outfile);
// 		*outfile = ft_strdup(splitted[0]);
// 	}
// 	else
// 	{
// 		join_args_quotes(&tmp2, splitted, j, 0);
// 		free(*outfile);
// 		*outfile = ft_strdup(tmp2);
// 	}
// 	free(tmp2);
// 	free_double_str(splitted);
// }

void	clear_outfile_quotes(t_command_list *new)
{
	t_outfile	*tmp;
	char		**splitted;
	int			quotes_type;

	tmp = new->outfile;
	while (tmp)
	{
		quotes_type = comprobate_quotes(tmp->outfile);
		if (quotes_type == 1)
		{
			if (ft_strcmp(tmp->outfile, "''") == 0)
				return ;
			splitted = ft_split(tmp->outfile, '\'');
			add_args_outfile(&tmp->outfile, splitted);
		}
		else if (quotes_type == 2)
		{
			if (ft_strcmp(tmp->outfile, "\"\"") == 0)
				return ;
			splitted = ft_split(tmp->outfile, '\"');
			add_args_outfile(&tmp->outfile, splitted);
		}
		tmp = tmp->next;
	}
}

void	clear_quotes(t_command_list *new)
{
	int	i;

	i = -1;
	if (!new->args || !new->command)
		return ;
	clear_command_quotes(new);
	while (new->args[++i])
	{
		if (new->args[i][0] == '\'' && new->args[i][0] != '-')
			new->quotes_type = 1;
		else if (new->args[i][0] == '\"')
			new->quotes_type = 2;
		clear_args_quotes(new, i);
	}
	i = -1;
	if (new->infile)
	{
		while (new->infile[++i])
			clear_infile_quotes(new, i);
	}
	if (new->outfile && new->outfile->outfile)
		clear_outfile_quotes(new);
}
