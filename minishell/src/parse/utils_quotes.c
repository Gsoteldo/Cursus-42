/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_quotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 23:14:47 by gsoteldo          #+#    #+#             */
/*   Updated: 2025/03/22 18:29:40 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	quote_index(char *comand, size_t quote_pos, int end, char *quote)
{
	int	end_index;

	end_index = 0;
	if (comand[0] == quote[0])
	{
		quote_pos = index_of(comand + 1, quote, 1);
		if (quote_pos < ft_strlen(comand + 1))
			end_index = end_args(comand, quote_pos + 2);
		else
			end_index = ft_strlen(comand);
	}
	else if (end > -1 && index_of(comand, quote, 1) < end)
	{
		quote_pos = index_of(comand + 1, quote, 2);
		if (quote_pos < ft_strlen(comand + 1))
			end_index = end_args(comand, quote_pos + 2);
		else
			end_index = ft_strlen(comand);
	}
	return (end_index);
}

int	get_close_quote(char *comand, int end)
{
	int		end_index;
	size_t	quote_pos;

	end_index = -2;
	quote_pos = 0;
	if (quote_index(comand, quote_pos, end, "\'"))
		end_index = quote_index(comand, quote_pos, end, "\'");
	else if (quote_index(comand, quote_pos, end, "\""))
		end_index = quote_index(comand, quote_pos, end, "\"");
	else
		end_index = -2;
	return (end_index);
}

/**
 * @brief Verifica si las comillas en un comando están correctamente cerradas.
 *
 * @param comand La cadena de comando a verificar.
 * @return int Devuelve 1 si todas las comillas están correctamente cerradas, 
 * de lo contrario devuelve 0 y muestra un mensaje de error.
 *
 * @details La función recorre la cadena de comando y cambia el estado de las
 * comillas según se encuentren abiertas o cerradas. Si al final de la cadena
 * alguna comilla permanece abierta, se muestra un mensaje de error
 * y se devuelve 0.
 */
int	checking_quotes(char *comand)
{
	int	i;
	int	in_quotes;

	i = 0;
	in_quotes = 0;
	while (comand[i])
	{
		if (comand[i] == '\'' && in_quotes == 0)
			in_quotes = 1;
		else if (comand[i] == '\'' && in_quotes == 1)
			in_quotes = 0;
		if (comand[i] == '\"' && in_quotes == 0)
			in_quotes = 2;
		else if (comand[i] == '\"' && in_quotes == 2)
			in_quotes = 0;
		i++;
	}
	if (in_quotes != 0)
	{
		ft_printf("Error: quotes not closed\n");
		return (0);
	}
	return (1);
}

void	join_args_quotes(char **tmp2, char **splitted, int j, int type)
{
	char	*tmp_free;

	tmp_free = NULL;
	if (!type)
		j = -1;
	while (splitted[j + 1])
	{
		if (!splitted[j + 1])
			break ;
		tmp_free = *tmp2;
		*tmp2 = ft_strjoin(*tmp2, splitted[j + 1]);
		if (!*tmp2)
			return ;
		free(tmp_free);
		j++;
	}
}

void	add_args_quotes(char ***new, int i, char **splitted)
{
	char	**tmp;
	char	*tmp2;
	int		j;

	j = 0;
	tmp = *new;
	if (!splitted || !splitted[0])
		return ;
	tmp2 = ft_strdup(splitted[0]);
	if (!tmp2)
		return ;
	if (size_array(splitted) > 1)
		join_args_quotes(&tmp2, splitted, j, 1);
	if (!tmp || !tmp[i])
	{
		free(tmp2);
		return ;
	}
	free(tmp[i]);
	tmp[i] = ft_strdup(tmp2);
	if (!tmp[i])
		return ;
	free(tmp2);
	new = &tmp;
}
