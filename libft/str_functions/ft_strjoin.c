/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 17:56:49 by gsoteldo          #+#    #+#             */
/*   Updated: 2024/01/08 18:24:59 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * Une dos cadenas de caracteres.
 * Asigna memoria dinámicamente para una nueva cadena de caracteres de la 
 * misma longitud que las dos cadenas de caracteres originales más 1 
 * (para el carácter nulo al final de la cadena de caracteres).
 * Verifica si la asignación de memoria fue exitosa. Si no fue exitosa, 
 * retorna nulo.
 * Copia los caracteres de la primera cadena de caracteres a la nueva 
 * cadena de caracteres.
 * Copia los caracteres de la segunda cadena de caracteres a la nueva 
 * cadena de caracteres.
 * Agrega un carácter nulo al final de la nueva cadena de caracteres.
 * Retorna la nueva cadena de caracteres.
 *
 * @param s1: Primera cadena de caracteres a unir.
 * @param s2: Segunda cadena de caracteres a unir.
 * @return: Nueva cadena de caracteres que es la unión de las dos 
 * cadenas de caracteres originales, o nulo si la asignación de memoria falló.
 */
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	size_t	i;
	size_t	j;

	ptr = (char *)malloc(sizeof(*s1) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!ptr)
		return (0);
	i = 0;
	j = 0;
	while (s1[i])
	{
		ptr[j++] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		ptr[j++] = s2[i];
		i++;
	}
	ptr[j] = 0;
	return (ptr);
}
