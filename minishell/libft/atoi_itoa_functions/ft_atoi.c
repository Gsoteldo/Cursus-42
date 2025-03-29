/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 19:41:50 by gsoteldo          #+#    #+#             */
/*   Updated: 2024/01/26 20:22:09 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * Convierte una cadena de caracteres a un número entero.
 * Ignora los espacios en blanco iniciales y los signos '+' o '-'.
 * Retorna el número entero correspondiente o 0 si la cadena no contiene 
 * ningún dígito.
 *
 * @param str: La cadena de caracteres a convertir.
 * @return: El número entero correspondiente a la cadena.
 */
int	ft_atoi(const char *str)
{
	int	i;
	int	num;
	int	negativo;

	i = 0;
	num = 0;
	negativo = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
	{
		i++;
	}
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			negativo++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	if (negativo % 2 == 1)
		return (num * -1);
	return (num);
}
