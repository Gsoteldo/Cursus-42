/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_functions_needed.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabo <gabo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 02:22:24 by gabo              #+#    #+#             */
/*   Updated: 2025/03/22 02:31:30 by gabo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/**
 * Esta función imprime un array de strings.
 * 
 * @param str: El array de strings.
 * @return void.
*/
void	print_str(char **str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return ;
	while (str[i] != NULL )
	{
		ft_printf("%s\n", str[i]);
		i++;
	}
}

/**
 * Esta funcion se encarga de recorrerse cada una de las lineas de un array de
 * strings, para saber cuantas lineas tiene. Si la cadena esta vacia, que
 * devuelva 0.
 * 
 * @param str: El array de strings.
 * @return El tamaño del array de strings.
*/
int	size_array(char **str)
{
	int	size;

	size = 0;
	if (str == NULL || str[0] == NULL)
		return (0);
	while (str[size] != NULL)
		size++;
	return (size);
}

/**
 * Libera la memoria asignada a un array de strings.
 * La función `free_double_str` libera la memoria asignada a un array de strings
 * 
 * @param str: Un puntero a un array de strings que se va a liberar.
 * @return void
 */
void	free_double_str(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
	{
		free(str[i]);
		str[i] = NULL;
		i++;
	}
	free(str);
}
