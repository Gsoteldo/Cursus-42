/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 18:28:47 by gsoteldo          #+#    #+#             */
/*   Updated: 2024/01/08 18:28:21 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * Elimina los caracteres especificados al principio y al final de una 
 * cadena de caracteres.
 * Mientras el carácter en la posición del primer contador de la cadena 
 * de caracteres no sea el carácter nulo y el carácter en esa posición 
 * esté en la cadena de caracteres a eliminar, incrementa el primer contador.
 * Mientras el carácter en la posición del segundo contador de la cadena 
 * de caracteres no sea el carácter nulo y el carácter en esa posición 
 * esté en la cadena de caracteres a eliminar, decrementa el segundo contador.
 * Asigna memoria dinámicamente para una nueva cadena de caracteres de 
 * la misma longitud que la cadena de caracteres original menos el rango 
 * de caracteres a eliminar más 1 (para el carácter nulo al final de la 
 * cadena de caracteres).
 * Verifica si la asignación de memoria fue exitosa. Si no fue exitosa, 
 * retorna nulo.
 * Copia los caracteres de la cadena de caracteres original a la nueva
 * cadena de caracteres, excluyendo los caracteres a eliminar.
 * Retorna la nueva cadena de caracteres.
 *
 * @param s1 Cadena de caracteres a modificar.
 * @param set Cadena de caracteres que contiene los caracteres a eliminar.
 * @return Nueva cadena de caracteres sin los caracteres especificados 
 * al principio y al final, o nulo si la asignación de memoria falló.
 */
char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr;
	int		i;
	int		j;

	ptr = NULL;
	if (s1 != 0 && set != 0)
	{
		i = 0;
		j = ft_strlen(s1);
		while (s1[i] != '\0' && ft_strchr(set, s1[i]))
		{
			i++;
		}
		while (ft_strchr(set, s1[j - 1]) && (j > i))
		{
			j--;
		}
		ptr = (char *)malloc(sizeof(char) * (j - i + 1));
		if (ptr)
		{
			ft_strlcpy(ptr, &s1[i], (j - i + 1));
		}
	}
	return (ptr);
}
