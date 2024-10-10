/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 19:53:14 by gsoteldo          #+#    #+#             */
/*   Updated: 2024/01/08 18:22:46 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * Asigna memoria dinámicamente y la inicializa a cero.
 * Asigna memoria dinámicamente para el número de elementos multiplicado 
 * por el tamaño de cada elemento.
 * Inicializa a cero el bloque de memoria asignado.
 * Retorna un puntero al bloque de memoria asignado.
 *
 * @param count: Número de elementos a asignar.
 * @param size: Tamaño de cada elemento.
 * @return: Puntero al bloque de memoria asignado, o nulo si la 
 * asignación falló.
 */

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = (void *)malloc(count * size);
	if (ptr == 0)
		return (0);
	ft_bzero(ptr, count * size);
	return (ptr);
}
