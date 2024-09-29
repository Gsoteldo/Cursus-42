/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 18:02:43 by gsoteldo          #+#    #+#             */
/*   Updated: 2024/01/08 18:27:39 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * Busca una subcadena dentro de una cadena de caracteres, pero solo 
 * hasta un número determinado de caracteres.
 * Si el primer carácter de la cadena de caracteres a buscar es el 
 * carácter nulo, retorna la cadena de caracteres original.
 * Mientras el carácter en la posición del primer contador de la cadena 
 * de caracteres original no sea el carácter nulo y el primer contador 
 * sea menor que el número, verifica si el carácter en esa posición es 
 * igual al primer carácter de la cadena de caracteres a buscar.
 * Si son iguales, entra en otro bucle donde verifica si los caracteres 
 * en las posiciones correspondientes de las dos cadenas de caracteres 
 * son iguales y el segundo contador más el primer contador es menor que 
 * el número.
 * Si son iguales, incrementa el segundo contador. Si el siguiente carácter 
 * de la cadena de caracteres a buscar es el carácter nulo, retorna un 
 * puntero al primer carácter de la coincidencia en la cadena de 
 * caracteres original.
 * Si después de comparar todos los caracteres hasta el número, ninguna 
 * de las cadenas de caracteres fue encontrada, retorna nulo.
 *
 * @param haystack: Cadena de caracteres en la que buscar.
 * @param needle: Subcadena a buscar en la cadena de caracteres.
 * @param n: Número de caracteres a considerar en la búsqueda.
 * @return: Un puntero al primer carácter de la coincidencia en la cadena 
 * de caracteres original, o nulo si la subcadena no se encuentra.
 */
char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[i] != '\0' && i < n)
	{
		if (haystack[i] == needle[j])
		{
			while ((haystack[i + j] == needle[j]) && (i + j < n))
			{
				if (needle[j + 1] == '\0')
				{
					return ((char *)haystack + i);
				}
				j++;
			}
			j = 0;
		}
		i++;
	}
	return (0);
}
