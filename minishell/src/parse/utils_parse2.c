/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parse2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 23:59:59 by gsoteldo          #+#    #+#             */
/*   Updated: 2025/03/22 18:37:10 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	find_end(char *line, int *i)
{
	int	end;

	end = 0;
	if (is_separators(line + *i))
		end = end_comand(line + *i, -1);
	else
		end = end_comand(line + *i, end_args(line + *i, 0));
	return (end);
}

void	free_error_splitting(t_minishell *shell, char *comand)
{
	if (comand)
		free(comand);
	free_double_str(shell->args);
	shell->args = NULL;
}

void	adding_double_args(t_minishell *shell, char *command)
{
	char	**old_args;

	old_args = shell->args;
	shell->args = add_str_double_pointer(shell->args, command);
	if (old_args)
		free_double_str(old_args);
}

void	add_args_outfile(char **outfile, char **splitted)
{
	char	*tmp2;
	int		j;

	j = 0;
	if (!splitted || !splitted[0])
		return ;
	tmp2 = ft_strdup("");
	if (!tmp2)
		return ;
	if (size_array(splitted) == 1)
	{
		free(*outfile);
		*outfile = ft_strdup(splitted[0]);
	}
	else
	{
		join_args_quotes(&tmp2, splitted, j, 0);
		free(*outfile);
		*outfile = ft_strdup(tmp2);
	}
	free(tmp2);
	free_double_str(splitted);
}
