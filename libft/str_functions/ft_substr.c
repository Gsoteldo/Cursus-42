/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 17:13:42 by gsoteldo          #+#    #+#             */
/*   Updated: 2024/01/08 18:28:41 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * Extrae una subcadena de una cadena de caracteres, comenzando desde un 
 * índice especificado y con una longitud especificada.
 * Si la longitud de la cadena de caracteres es menor que el índice de 
 * inicio, retorna una nueva cadena de caracteres vacía.
 * Si la longitud de la subcadena desde el índice de inicio es menor que 
 * la longitud especificada, ajusta la longitud a la longitud de la 
 * subcadena desde el índice de inicio.
 * Si la cadena de caracteres es nula, retorna nulo.
 * Asigna memoria dinámicamente para una nueva cadena de caracteres de 
 * la misma longitud que la subcadena más 1 (para el carácter nulo al 
 * final de la cadena de caracteres).
 * Verifica si la asignación de memoria fue exitosa. Si no fue exitosa, 
 * retorna nulo.
 * Copia la subcadena de la cadena de caracteres original a la nueva 
 * cadena de caracteres.
 * Retorna la nueva cadena de caracteres.
 *
 * @param str: Cadena de caracteres de la que extraer la subcadena.
 * @param start: Índice de inicio de la subcadena.
 * @param len: Longitud de la subcadena.
 * @return: Nueva cadena de caracteres que es la subcadena de la cadena 
 * de caracteres original, o nulo si la asignación de memoria falló.
 */
char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	char	*ptr;

	if ((unsigned int)ft_strlen(str) < start)
		return (ft_strdup(""));
	if ((size_t)ft_strlen(str + start) < len)
		len = ft_strlen(str + start);
	if (str == 0)
		return (0);
	ptr = (char *)malloc(sizeof(*str) * (len + 1));
	if (ptr == 0)
		return (0);
	ft_strlcpy(ptr, (char *)(str + start), len + 1);
	return (ptr);
}
