/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 10:38:49 by gsoteldo          #+#    #+#             */
/*   Updated: 2024/01/08 18:26:37 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * Calcula la longitud de una cadena de caracteres.
 * Mientras el carácter en la posición del primer contador de la cadena 
 * de caracteres no sea el carácter nulo, incrementa el segundo contador 
 * y el primer contador.
 * Retorna el segundo contador, que representa la longitud de la cadena 
 * de caracteres.
 *
 * @param str: Cadena de caracteres cuya longitud calcular.
 * @return: Longitud de la cadena de caracteres.
 */
size_t	ft_strlen(const char *str)
{
	int	n;
	int	cont;

	n = 0;
	cont = 0;
	while (str[n] != '\0')
	{
		cont++;
		n++;
	}
	return (cont);
}
