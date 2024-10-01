/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstring.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 18:14:00 by gsoteldo          #+#    #+#             */
/*   Updated: 2024/01/08 18:19:42 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

/**
 * Imprime una cadena de caracteres en la salida estándar.
 * Si la cadena de caracteres es NULL, imprime "(null)" en la salida 
 * estándar y actualiza el contador de caracteres escritos.
 * Si la cadena de caracteres no es NULL, imprime la cadena de caracteres 
 * en la salida estándar y actualiza el contador de caracteres escritos.
 *
 * @param str: La cadena de caracteres a imprimir.
 * @param total: Un puntero a un entero que se actualizará con el 
 * número de caracteres escritos.
 */

void	ft_printstring(char *str, int *total)
{
	int	aux;

	aux = 0;
	if (str == NULL)
	{
		aux = write(1, "(null)", 6);
		if (aux == -1)
		{
			*total = -1;
			return ;
		}
		*total = *total + 6;
		return ;
	}
	aux = write(1, str, ft_strlen(str));
	if (aux == -1)
	{
		*total = -1;
		return ;
	}
	*total = *total + ft_strlen(str);
}
