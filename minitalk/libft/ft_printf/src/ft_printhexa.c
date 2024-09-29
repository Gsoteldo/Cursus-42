/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 18:12:36 by gsoteldo          #+#    #+#             */
/*   Updated: 2024/01/06 21:18:40 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

/**
 * Imprime un número entero en formato hexadecimal.
 * Si el número es mayor o igual a 16, llama a sí misma recursivamente 
 * con el número dividido por 16 y luego con el resto de la división por 16.
 * Si el número es menor o igual a 9, imprime el número como un dígito decimal.
 * Si el número es mayor que 9, imprime el número como un dígito hexadecimal.
 * Dependiendo del carácter proporcionado ('x' o 'X'), imprime el dígito 
 * en minúsculas o mayúsculas.
 *
 * @param n: El número entero a imprimir en formato hexadecimal.
 * @param c: El carácter que especifica si imprimir el dígito en minúsculas 
 * o mayúsculas.
 * @param total: Un puntero a un entero que se actualizará con el número de 
 * caracteres escritos.
 */
void	ft_printhexa(unsigned int n, char c, int *total)
{
	int	aux;

	if (n >= 16)
	{
		ft_printhexa(n / 16, c, total);
		aux = *total;
		if (aux == -1)
		{
			*total = -1;
			return ;
		}
		ft_printhexa(n % 16, c, total);
	}
	else
	{
		if (n <= 9)
			ft_printchar(n + '0', total);
		else
		{
			if (c == 'x')
				ft_printchar(n - 10 + 'a', total);
			else if (c == 'X')
				ft_printchar(n - 10 + 'A', total);
		}
	}
}
