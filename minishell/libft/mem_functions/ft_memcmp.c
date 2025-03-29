/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 19:47:22 by gsoteldo          #+#    #+#             */
/*   Updated: 2024/01/08 18:22:03 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * Compara dos bloques de memoria.
 * Compara los bytes en las posiciones del contador de los dos bloques de 
 * memoria.
 * Si los bytes son diferentes, retorna la diferencia entre los bytes.
 * Si todos los bytes son iguales dentro del tamaño especificado, retorna 0.
 *
 * @param s1: Primer bloque de memoria a comparar.
 * @param s2: Segundo bloque de memoria a comparar.
 * @param n: Número máximo de bytes a considerar en cada bloque de memoria.
 * @return: La diferencia entre los primeros bytes diferentes encontrados 
 * en los bloques de memoria, o 0 si todos los bytes son iguales.
 */
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char	*ptr1;
	char	*ptr2;
	size_t	i;

	ptr1 = (char *)s1;
	ptr2 = (char *)s2;
	i = 0;
	while (i < n)
	{
		if (ptr1[i] != ptr2[i])
			return ((unsigned char)ptr1[i] - (unsigned char)ptr2[i]);
		i++;
	}
	return (0);
}
