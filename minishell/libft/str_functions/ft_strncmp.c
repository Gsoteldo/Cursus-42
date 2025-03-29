/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 17:51:57 by gsoteldo          #+#    #+#             */
/*   Updated: 2024/01/08 18:27:18 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * Compara las primeras 'n' caracteres de dos cadenas de caracteres.
 * Mientras el carácter en la posición del contador de la primera cadena 
 * de caracteres no sea el carácter nulo o el carácter en la posición del 
 * contador de la segunda cadena de caracteres no sea el carácter nulo, y
 * el contador sea menor que el número, verifica si los caracteres en 
 * las posiciones correspondientes de las dos cadenas de caracteres son 
 * diferentes.
 * Si son diferentes, retorna la diferencia entre los valores ASCII 
 * de los caracteres.
 * Si son iguales, incrementa el contador.
 * Si después de comparar todos los caracteres hasta el número, ninguno 
 * de los caracteres fue diferente, retorna 0.
 *
 * @param s1: Primera cadena de caracteres a comparar.
 * @param s2: Segunda cadena de caracteres a comparar.
 * @param i: Número de caracteres a comparar.
 * @return: Diferencia entre los valores ASCII de los caracteres 
 * en las posiciones correspondientes de las dos cadenas de caracteres, 
 * o 0 si los caracteres son iguales.
 */
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (((s1[i] != '\0') || (s2[i] != '\0')) && (i < n))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}
