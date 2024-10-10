/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 10:33:54 by gsoteldo          #+#    #+#             */
/*   Updated: 2024/01/06 20:08:18 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Verifica si un carácter dado es imprimible.
 * Si el valor del carácter está entre 32 y 126, retorna 1.
 * Si el valor del carácter no está entre 32 y 126, retorna 0.
 *
 * @param c: El carácter a verificar.
 * @return: 1 si el carácter es imprimible, 0 en caso contrario.
 */
int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
	{
		return (1);
	}
	return (0);
}
