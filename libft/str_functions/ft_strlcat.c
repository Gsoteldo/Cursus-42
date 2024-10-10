/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 13:21:12 by gsoteldo          #+#    #+#             */
/*   Updated: 2024/01/08 18:26:18 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * Concatena una cadena de caracteres a otra cadena de caracteres, pero con 
 * una limitación de tamaño en la cadena de destino.
 * Mientras el carácter en la posición del primer contador de la cadena de 
 * destino no sea el carácter nulo y el primer contador sea menor que el 
 * tamaño, incrementa el primer contador.
 * Mientras el carácter en la posición del segundo contador de la cadena 
 * de origen no sea el carácter nulo y la suma de los primeros contador y 
 * el segundo contador más uno sea menor que el tamaño, copia el carácter 
 * de la cadena de origen a la cadena de destino y luego incrementa el 
 * segundo contador.
 * Si el primer contador es menor que el tamaño, agrega un carácter nulo 
 * al final de la cadena de destino.
 * Retorna la suma del primer contador y la longitud de la cadena de origen.
 *
 * @param dst: Cadena de caracteres de destino a la que agregar la 
 * cadena de origen.
 * @param src: Cadena de caracteres de origen a agregar a la cadena de destino.
 * @param dstsize: Tamaño máximo de la cadena de destino.
 * @return: La suma del tamaño de la cadena de destino antes de la 
 * concatenación y la longitud de la cadena de origen.
 */
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (dst[i] != '\0' && i < dstsize)
	{
		i++;
	}
	while (src[j] != '\0' && (i + j + 1) < dstsize)
	{
		dst[i + j] = src[j];
		j++;
	}
	if (i < dstsize)
	{
		dst[i + j] = '\0';
	}
	return (i + ft_strlen(src));
}
