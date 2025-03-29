/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_needed.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabo <gabo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 18:01:06 by pmendez-          #+#    #+#             */
/*   Updated: 2025/03/22 02:28:52 by gabo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static char	**new_double_ptr(char *s)
{
	char	**new_str;

	new_str = ft_calloc(2, sizeof(char *));
	if (new_str == NULL)
		return (NULL);
	new_str[1] = NULL;
	new_str[0] = ft_strdup(s);
	if (new_str[0] == NULL)
	{
		free_double_str(new_str);
		return (NULL);
	}
	return (new_str);
}

static int	copy_str(char **new_str, char **str, int *i, char *s)
{
	*i = 0;
	while (str[*i] != NULL)
	{
		new_str[*i] = ft_strdup(str[*i]);
		if (new_str[*i] == NULL)
		{
			free_double_str(new_str);
			return (0);
		}
		(*i)++;
	}
	new_str[*i] = ft_strdup(s);
	if (new_str[*i] == NULL)
	{
		free_double_str(new_str);
		return (0);
	}
	return (1);
}

/**
 * Esta funcion recibe una array de strings y una string, y se encarga de añadir
 * la string al final del array de strings.
 * 
 * Cuando ya ha creado el nuevo array doble, libera el array de strings anterior
 * para no perder memoria.
 * 
 * @param str: El array de strings, el puntero doble.
 * @param s: La string que se añadira al final del array de strings.
 * @return El nuevo array de strings.
 */
char	**add_str_double_pointer(char **str, char *s)
{
	char	**new_str;
	int		i;
	int		size;
	int		copy_result;

	new_str = NULL;
	if (s == NULL)
		return (NULL);
	if (str == NULL)
	{
		new_str = new_double_ptr(s);
		return (new_str);
	}
	size = size_array(str);
	new_str = ft_calloc(size + 2, sizeof(char *));
	if (new_str == NULL)
		return (NULL);
	copy_result = copy_str(new_str, str, &i, s);
	if (!copy_result)
	{
		free_double_str(new_str);
		return (NULL);
	}
	new_str[i + 1] = NULL;
	return (new_str);
}

/**
 * Esta funcion se encarga de recorrerse el array de caracteres, buscando
 * la posicion de un caracter especifico desde un start especifico.
 * 
 * @param str: El array de caracteres.
 * @param c: El caracter que se busca.
 * @param start: La posicion desde donde se empieza a buscar.
 * @return La posicion del caracter en el array de caracteres.
*/
int	find_char_pos(char *str, char c, int start)
{
	int	len;
	int	i;

	i = 0;
	len = ft_strlen(str);
	if (start < 0 || str == NULL || len == 0)
		return (-1);
	i = start - 1;
	while (++i < len && str[i] != '\0')
	{
		if (str[i] == c)
			return (i);
	}
	return (-1);
}
