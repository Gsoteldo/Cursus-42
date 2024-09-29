/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 13:43:45 by gsoteldo          #+#    #+#             */
/*   Updated: 2024/01/08 18:29:35 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * Convierte un carácter a minúsculas si es una letra mayúscula.
 * Si el carácter es una letra mayúscula (su valor ASCII está entre 65 y 90), 
 * suma 32 a su valor ASCII para convertirlo a minúsculas.
 * Retorna el carácter.
 *
 * @param c: Carácter a convertir a minúsculas.
 * @return: Carácter convertido a minúsculas, o el mismo carácter si no 
 * era una letra mayúscula.
 */
int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
	{
		c = c + 32;
	}
	return (c);
}
