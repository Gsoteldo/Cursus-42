/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmendez- <pmendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 17:33:23 by gsoteldo          #+#    #+#             */
/*   Updated: 2024/09/07 14:52:56 by pmendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * Aplica una función dada a cada carácter de una cadena de caracteres 
 * junto con su índice y devuelve una nueva cadena de caracteres con 
 * los resultados.
 * Asigna memoria dinámicamente para una nueva cadena de caracteres de 
 * la misma longitud que la cadena de caracteres original más 1 
 * (para el carácter nulo al final de la cadena de caracteres).
 * Verifica si la asignación de memoria fue exitosa. Si no fue exitosa, 
 * retorna nulo.
 * Aplica la función dada a cada carácter de la cadena de caracteres 
 * original junto con su índice y guarda el resultado en la nueva 
 * cadena de caracteres.
 * Agrega un carácter nulo al final de la nueva cadena de caracteres.
 * Retorna la nueva cadena de caracteres.
 *
 * @param s: Cadena de caracteres sobre la cual aplicar la función.
 * @param f: Función a aplicar a cada carácter de la cadena de caracteres 
 * junto con su índice.
 * @return: Nueva cadena de caracteres con los resultados de aplicar la 
 * función a cada carácter de la cadena de caracteres original, o 
 * nulo si la asignación de memoria falló.
 */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*aux;
	size_t	i;

	i = 0;
	aux = ft_calloc((ft_strlen(s) + 1), sizeof(char));
	if (aux == NULL)
		return (0);
	while (i < ft_strlen(s))
	{
		aux[i] = f(i, s[i]);
		i++;
	}
	aux[i] = '\0';
	return (aux);
}
