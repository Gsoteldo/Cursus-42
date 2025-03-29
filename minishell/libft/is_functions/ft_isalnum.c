/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:20:04 by gsoteldo          #+#    #+#             */
/*   Updated: 2024/01/06 20:05:31 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * Verifica si un carácter dado es alfanumérico.
 * Si el carácter es una letra (mayúscula o minúscula) o un número, retorna 1.
 * Si el carácter no es una letra ni un número, retorna 0.
 *
 * @param c: El carácter a verificar.
 * @return: 1 si el carácter es alfanumérico, 0 en caso contrario.
 */
int	ft_isalnum(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
		|| (c >= '0' && c <= '9'))
		return (1);
	return (0);
}
