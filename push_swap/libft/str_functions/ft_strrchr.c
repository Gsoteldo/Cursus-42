/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 17:31:40 by gsoteldo          #+#    #+#             */
/*   Updated: 2024/01/08 18:27:58 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * Busca la última aparición de un carácter en una cadena de caracteres.
 * Obtiene la longitud de la cadena de caracteres utilizando la función 
 * ft_strlen.
 * Inicializa un contador en la longitud de la cadena de caracteres.
 * Mientras el contador sea mayor o igual a 0, verifica si el carácter 
 * en la posición del contador de la cadena de caracteres es igual al 
 * carácter buscado.
 * Si son iguales, retorna un puntero al carácter. Si son diferentes, 
 * decrementa el contador.
 * Si después de recorrer toda la cadena de caracteres, el carácter 
 * buscado no se encuentra, retorna nulo.
 *
 * @param str: Cadena de caracteres en la que buscar.
 * @param c: Carácter a buscar.
 * @return: Un puntero al último carácter encontrado en la cadena de 
 * caracteres, o nulo si el carácter no se encuentra.
 */
char	*ft_strrchr(const char *str, int c)
{
	int	i;

	i = ft_strlen(str);
	while (i >= 0)
	{
		if ((char)str[i] == (char)c)
		{
			return ((char *)str + i);
		}
		i--;
	}
	return (0);
}
