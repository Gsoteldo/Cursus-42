/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 12:52:07 by gsoteldo          #+#    #+#             */
/*   Updated: 2024/01/08 18:22:10 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * Copia un bloque de memoria de una ubicación a otra.
 * Copia el byte en la posición del contador de la ubicación de origen a 
 * la ubicación de destino y luego incrementa el contador.
 * Cuando el contador sea igual al tamaño, retorna el puntero a la 
 * ubicación de destino.
 *
 * @param dst: Puntero a la ubicación de destino.
 * @param src: Puntero a la ubicación de origen.
 * @param n: Tamaño del bloque de memoria a copiar.
 * @return: Puntero a la ubicación de destino.
 */
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*ptr1;
	char		*ptr2;

	i = 0;
	ptr1 = (char *)src;
	ptr2 = (char *)dst;
	if (!dst && !src)
		return (0);
	while (i < n)
	{
		ptr2[i] = ptr1[i];
		i++;
	}
	return (dst);
}
