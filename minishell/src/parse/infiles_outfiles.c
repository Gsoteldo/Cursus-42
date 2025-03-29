/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infiles_outfiles.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 15:57:49 by gabo              #+#    #+#             */
/*   Updated: 2025/03/22 17:42:30 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	append_heredoc(char ***args, t_command_list *new, char *redirect, \
t_minishell *shell)
{
	if (!(**args) || !(*args) || !args)
		return (1);
	if (ft_strcmp(redirect, "<<") == 0)
	{
		(*args)++;
		new->heredoc_delimiter = ft_strdup(**args);
		if (!new->heredoc_delimiter)
			return (0);
		open_here_doc(shell, new->heredoc_delimiter, new);
		if (*args && **args)
		{
			if (!new->heredoc_delimiter)
			{
				return (0);
			}
			(*args)++;
		}
	}
	return (1);
}

static int	append_infiles(char ***args, char ***new, char *redirect)
{
	char	**temp;

	if (!(**args) || !(*args) || !args)
		return (1);
	if (ft_strlen(redirect) == ft_strlen(**args)
		&& !ft_strncmp(redirect, **args, ft_strlen(redirect)))
	{
		(*args)++;
		if (*args && **args)
		{
			temp = *new;
			*new = add_str_double_pointer(*new, **args);
			if (temp)
				free_double_str(temp);
			if (!(*new))
				return (0);
			(*args)++;
		}
	}
	return (1);
}

static t_outfile	*add_outfile(t_outfile **outfile, char *file, char *type)
{
	t_outfile	*new;
	t_outfile	*temp;
	int			action;

	new = NULL;
	action = WRITE_OUTFILE;
	if (ft_strncmp(">>", type, 2) == 0 && ft_strlen(type) == 2)
		action = APPEND_OUTFILE;
	new = new_outfile(file, action);
	if (!new)
		return (NULL);
	if (*outfile)
	{
		temp = *outfile;
		while (temp->next)
			temp = temp->next;
		temp->next = new;
	}
	else
		*outfile = new;
	return (new);
}

static int	append_outfiles(char ***args, t_outfile **new, char *redirect)
{
	t_outfile	*new_out;

	if (!args || !(*args) || !(**args))
		return (1);
	if (ft_strlen(redirect) == ft_strlen(**args)
		&& !ft_strncmp(redirect, **args, ft_strlen(redirect)))
	{
		(*args)++;
		new_out = add_outfile(new, **args, redirect);
		if (*args && **args && !new_out)
		{
			free_outfile_list(*new);
			return (0);
		}
		(*args)++;
	}
	return (1);
}

int	append_redirections(char ***args, t_command_list *new, t_minishell *shell)
{
	char	*redirect;

	redirect = **args;
	if (ft_strcmp(redirect, "<") == 0)
	{
		if (!append_infiles(args, &(new->infile), redirect))
			return (0);
	}
	else if (ft_strcmp(redirect, "<<") == 0)
	{
		if (!append_heredoc(args, new, redirect, shell))
			return (0);
		new->is_heredoc = 1;
	}
	else if (ft_strcmp(redirect, ">") == 0 || ft_strcmp(redirect, ">>") == 0)
	{
		if (!append_outfiles(args, &(new->outfile), redirect))
			return (0);
	}
	return (1);
}
