/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmendez- <pmendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 19:49:13 by pmendez-          #+#    #+#             */
/*   Updated: 2024/11/09 20:03:50 by pmendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * Busca una subcadena dentro de una cadena de caracteres.
 * 
 * Si el primer carácter de la cadena de caracteres a buscar es el
 * carácter nulo, retorna la cadena de caracteres original.
 * Mientras el carácter en la posición del primer contador de la cadena
 * de caracteres original no sea el carácter nulo, verifica si el carácter
 * en esa posición es igual al primer carácter de la cadena de caracteres
 * a buscar.
 * 
 * Si son iguales, entra en otro bucle donde verifica si los caracteres
 * en las posiciones correspondientes de las dos cadenas de caracteres
 * son iguales.
 * 
 * Si son iguales, incrementa el segundo contador. Si el siguiente carácter
 * de la cadena de caracteres a buscar es el carácter nulo, retorna un
 * puntero al primer carácter de la coincidencia en la cadena de
 * caracteres original.
 * 
 * Si después de comparar todos los caracteres, ninguna de las cadenas de
 * caracteres fue encontrada, retorna nulo.
 * 
 * @param haystack: Cadena de caracteres en la que buscar.
 * @param needle: Subcadena a buscar en la cadena de caracteres.
 * @return: Un puntero al primer carácter de la coincidencia en la cadena
 */

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[i] != '\0')
	{
		if (haystack[i] == needle[j])
		{
			while (haystack[i + j] == needle[j])
			{
				if (needle[j + 1] == '\0')
					return ((char *)haystack + i);
				j++;
			}
			j = 0;
		}
		i++;
	}
	return (0);
}
