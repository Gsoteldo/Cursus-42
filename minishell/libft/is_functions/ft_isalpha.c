/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 12:29:57 by gsoteldo          #+#    #+#             */
/*   Updated: 2024/01/06 20:06:19 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * Verifica si un carácter dado es una letra.
 * Si el carácter es una letra (mayúscula o minúscula), retorna 1.
 * Si el carácter no es una letra, retorna 0.
 *
 * @param c: El carácter a verificar.
 * @return: 1 si el carácter es una letra, 0 en caso contrario.
 */
int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}
