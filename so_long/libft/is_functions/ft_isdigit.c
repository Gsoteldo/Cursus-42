/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 12:56:00 by gsoteldo          #+#    #+#             */
/*   Updated: 2024/01/06 20:07:46 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * Verifica si un carácter dado es un dígito.
 * Si el carácter es un número del 0 al 9, retorna 1.
 * Si el carácter no es un número, retorna 0.
 *
 * @param c: El carácter a verificar.
 * @return: 1 si el carácter es un dígito, 0 en caso contrario.
 */
int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	return (0);
}
