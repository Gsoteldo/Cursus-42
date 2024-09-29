/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 13:52:06 by gsoteldo          #+#    #+#             */
/*   Updated: 2024/01/08 18:24:19 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * Busca un carácter específico en una cadena de caracteres.
 * Verifica si el carácter en la posición del contador de la cadena de 
 * caracteres es igual al carácter buscado.
 * Si son iguales, retorna un puntero al carácter.
 * Después de recorrer toda la cadena de caracteres, verifica nuevamente 
 * si el último carácter es igual al carácter buscado.
 * Si el carácter buscado no se encuentra en la cadena de caracteres, 
 * retorna nulo.
 *
 * @param str: Cadena de caracteres en la que buscar.
 * @param c: Carácter a buscar.
 * @return: Un puntero al primer carácter encontrado en la cadena de 
 * caracteres, o nulo si el carácter no se encuentra.
 */

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
		{
			return ((char *)str + i);
		}
		i++;
	}
	if (str[i] == (char)c)
	{
		return ((char *)str + i);
	}
	return (0);
}
