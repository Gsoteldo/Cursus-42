/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 10:54:45 by gsoteldo          #+#    #+#             */
/*   Updated: 2024/01/08 18:22:32 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * Escribe un valor dado en un bloque de memoria.
 * Escribe el valor en la posición del contador del bloque de memoria y 
 * luego incrementa el contador.
 * Cuando el contador sea igual al tamaño, retorna el puntero al bloque 
 * de memoria.
 *
 * @param str: Bloque de memoria en el que escribir.
 * @param c: Valor a escribir.
 * @param len: Tamaño del bloque de memoria.
 * @return: Puntero al bloque de memoria.
 */

void	*ft_memset(void *str, int c, size_t len)
{
	size_t		n;
	char		*p;

	p = (char *)str;
	n = 0;
	while (n < len)
	{
		p[n] = c;
		n++;
	}
	return (str);
}
