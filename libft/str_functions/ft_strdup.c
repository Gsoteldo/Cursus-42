/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 20:10:58 by gsoteldo          #+#    #+#             */
/*   Updated: 2024/01/08 18:24:38 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * Duplica una cadena de caracteres.
 * Calcula la longitud de la cadena de caracteres utilizando la función 
 * ft_strlen.
 * Asigna memoria dinámicamente para una nueva cadena de caracteres de 
 * la misma longitud que la cadena de caracteres original más 1 
 * (para el carácter nulo al final de la cadena de caracteres).
 * Verifica si la asignación de memoria fue exitosa. Si no fue exitosa,
 * retorna nulo.
 * Copia los caracteres de la cadena de caracteres original a la nueva 
 * cadena de caracteres.
 * Agrega un carácter nulo al final de la nueva cadena de caracteres.
 * Retorna la nueva cadena de caracteres.
 *
 * @param str: Cadena de caracteres a duplicar.
 * @return: Nueva cadena de caracteres duplicada de la cadena de 
 * caracteres original, o nulo si la asignación de memoria falló.
 */
char	*ft_strdup(const char *str)
{
	size_t	len;
	char	*ptr;
	size_t	i;

	len = ft_strlen(str);
	ptr = malloc((len + 1) * sizeof(char));
	if (!ptr)
		return (0);
	i = 0;
	while (i < len)
	{
		ptr[i] = str[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
