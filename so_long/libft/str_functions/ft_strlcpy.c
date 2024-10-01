/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 12:42:46 by gsoteldo          #+#    #+#             */
/*   Updated: 2024/01/08 18:25:43 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * Copia una cadena de caracteres a otra cadena de caracteres, pero con 
 * una limitación de tamaño en la cadena de destino.
 * Si el tamaño es 0, calcula la longitud de la cadena de origen 
 * utilizando la función ft_strlen, guarda la longitud en el contador 
 * y retorna la longitud.
 * Mientras el carácter en la posición del primer contador de la cadena 
 * de origen no sea el carácter nulo y el primer contador sea menor que 
 * el tamaño menos uno, copia el carácter de la cadena de origen a la 
 * cadena de destino y luego incrementa el primer contador.
 * Agrega un carácter nulo al final de la cadena de destino.
 * Calcula la longitud de la cadena de origen utilizando la función 
 * ft_strlen, guarda la longitud en el contador y retorna la longitud.
 *
 * @param dst: Cadena de caracteres de destino a la que copiar la
 * cadena de origen.
 * @param src: Cadena de caracteres de origen a copiar a la cadena de destino.
 * @param dstsize: Tamaño máximo de la cadena de destino.
 * @return: La longitud de la cadena de origen.
 */
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	contador;

	i = 0;
	contador = 0;
	if (dstsize == 0)
	{
		contador = ft_strlen(src);
		return (contador);
	}
	while ((src[i] != '\0') && (i < dstsize - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	contador = 0;
	while (src[contador] != '\0')
	{
		contador++;
	}
	return (contador);
}
