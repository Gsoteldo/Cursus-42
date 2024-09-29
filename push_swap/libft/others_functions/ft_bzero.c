/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 11:18:02 by gsoteldo          #+#    #+#             */
/*   Updated: 2024/01/08 18:22:41 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * Escribe ceros en un bloque de memoria.
 * Llama a la función ft_memset con el puntero a un bloque de memoria, 
 * el valor 0 y el tamaño como argumentos.
 *
 * @param str: Bloque de memoria en el que escribir ceros.
 * @param n: Tamaño del bloque de memoria.
 */
void	ft_bzero(void *str, size_t n)
{
	ft_memset(str, 0, n);
}
