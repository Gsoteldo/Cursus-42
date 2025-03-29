/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmendez- <pmendez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 10:38:49 by gsoteldo          #+#    #+#             */
/*   Updated: 2025/01/31 23:58:17 by pmendez-         ###   ########.fr       */
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
	int	cont;

	cont = 0;
	if (!str)
		return (cont);
	while (str[cont] != '\0')
		cont++;
	return (cont);
}
