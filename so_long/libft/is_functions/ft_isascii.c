/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 18:26:02 by gsoteldo          #+#    #+#             */
/*   Updated: 2024/01/06 20:07:38 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * Verifica si un carácter dado es un carácter ASCII válido.
 * En ASCII, los valores válidos van desde 0 hasta 127.
 * Si el valor del carácter está entre 0 y 127, retorna 1.
 * Si el valor del carácter no está entre 0 y 127, retorna 0.
 *
 * @param c: El carácter a verificar.
 * @return: 1 si el carácter es un carácter ASCII válido, 0 en caso contrario.
 */
int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
	{
		return (1);
	}
	return (0);
}
