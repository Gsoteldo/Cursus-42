/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 18:50:50 by gsoteldo          #+#    #+#             */
/*   Updated: 2024/01/08 18:22:25 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * Copia un bloque de memoria de una ubicación a otra, manejando 
 * correctamente los casos en los que la ubicación de origen y destino 
 * se superponen.
 * Si la ubicación de origen es menor que la ubicación de destino, 
 * copia los datos desde la ubicación de origen hacia atrás hasta la 
 * ubicación de destino.
 * Si la ubicación de origen es mayor que o igual a la ubicación 
 * de destino, copia los datos desde la ubicación de origen hacia 
 * adelante hasta la ubicación de destino.
 * Cuando se hayan copiado todos los datos, retorna el puntero a 
 * la ubicación de destino.
 *
 * @param dst: Puntero a la ubicación de destino.
 * @param src: Puntero a la ubicación de origen.
 * @param len: Tamaño del bloque de memoria a copiar.
 * @return: Puntero a la ubicación de destino.
 */
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	i = 0;
	if (!dst && !src)
		return (NULL);
	if (src < dst)
	{
		i = len;
		while (i > 0)
		{
			i--;
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		}
	}
	else
	{
		i = 0;
		while (i < len)
		{
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	return (dst);
}
