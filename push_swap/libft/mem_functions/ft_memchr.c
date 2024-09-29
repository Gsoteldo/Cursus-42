/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 18:09:29 by gsoteldo          #+#    #+#             */
/*   Updated: 2024/01/08 18:21:55 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * Busca un carácter específico en una cadena de caracteres.
 * Compara el carácter en la posición del contador con el carácter buscado.
 * Si son iguales, retorna un puntero al carácter.
 * Si el carácter buscado no se encuentra en la cadena de caracteres dentro 
 * del tamaño especificado, retorna nulo.
 *
 * @param str: Cadena de caracteres en la que buscar.
 * @param c: Carácter a buscar.
 * @param n: Número máximo de bytes a considerar en la cadena de caracteres.
 * @return: Un puntero al primer carácter encontrado en la cadena de 
 * caracteres, o nulo si el carácter no se encuentra.
 */

void	*ft_memchr(const void *str, int c, size_t n)
{
	char	*p;
	size_t	i;

	p = (char *)str;
	i = 0;
	while (i < n)
	{
		if ((unsigned char)p[i] == (unsigned char)c)
		{
			return ((void *)p + i);
		}
		i++;
	}
	return (0);
}
