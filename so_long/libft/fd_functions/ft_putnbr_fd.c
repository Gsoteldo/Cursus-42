/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 17:30:04 by gsoteldo          #+#    #+#             */
/*   Updated: 2024/01/08 18:10:35 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * Escribe un número entero en un descriptor de archivo especificado.
 * Si el número es igual a -2147483648, escribe directamente esta cadena 
 * en el descriptor de archivo.
 * Si el número es menor que 0, escribe un guión "-" en el descriptor 
 * de archivo y cambia el signo del número a positivo.
 * Si el número es mayor que 9, llama recursivamente a sí misma con 
 * el número dividido por 10.
 * Calcula el último dígito del número y lo convierte a un carácter.
 * Escribe el carácter en el descriptor de archivo.
 *
 * @param n: El número entero a escribir.
 * @param fd: El descriptor de archivo donde escribir el número.
 */
void	ft_putnbr_fd(int n, int fd)
{
	int		num;
	char	aux;

	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		num = n * -1;
	}
	else
	{
		num = n;
	}
	if (num / 10 != 0)
	{
		ft_putnbr_fd(num / 10, fd);
	}
	aux = num % 10 + '0';
	ft_putchar_fd(aux, fd);
}
