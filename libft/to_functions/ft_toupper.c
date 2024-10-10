/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 13:38:14 by gsoteldo          #+#    #+#             */
/*   Updated: 2024/01/08 18:29:45 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * Convierte un carácter a mayúsculas si es una letra minúscula.
 * Si el carácter es una letra minúscula (su valor ASCII está entre 97 y 122), 
 * resta 32 a su valor ASCII para convertirlo a mayúsculas.
 * Retorna el carácter.
 *
 * @param c: Carácter a convertir a mayúsculas.
 * @return: Carácter convertido a mayúsculas, o el mismo carácter si no era 
 * una letra minúscula.
 */
int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
	{
		c = c - 32;
	}
	return (c);
}
