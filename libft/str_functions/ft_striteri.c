/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 19:01:07 by gsoteldo          #+#    #+#             */
/*   Updated: 2024/01/08 18:24:44 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * Aplica una función dada a cada carácter de una cadena de caracteres junto 
 * con su índice.
 * Llama a la función dada con el índice y el carácter actual de la cadena 
 * de caracteres como argumentos y luego incrementa el contador.
 *
 * @param s: Cadena de caracteres sobre la cual aplicar la función.
 * @param f: Función a aplicar a cada carácter de la cadena de caracteres 
 * junto con su índice.
 */
void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int		i;

	i = 0;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
}
