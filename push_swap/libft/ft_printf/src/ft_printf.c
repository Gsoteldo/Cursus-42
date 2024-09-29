/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 18:11:52 by gsoteldo          #+#    #+#             */
/*   Updated: 2024/01/08 18:17:25 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

/**
 * Imprime un argumento específico según su tipo.
 * Dependiendo del carácter de formato proporcionado, imprime un carácter, 
 * una cadena de caracteres, un número entero, un puntero, 
 * un número hexadecimal o un número sin signo.
 *
 * @param c: El carácter de formato que especifica 
 * el tipo de argumento a imprimir.

 * @param vargs: Una lista variable de argumentos a imprimir.

 * @param total: Un puntero a un entero que se actualizará 
 * con el número de caracteres escritos.

 * @param i: Un puntero a un entero que se utiliza para recorrer 
 *la lista de argumentos.
 */

void	ft_type_print(char c, va_list vargs, int *total, int *i)
{
	if (c == 'c')
		ft_printchar(va_arg(vargs, int), total);
	else if (c == 's')
		ft_printstring(va_arg(vargs, char *), total);
	else if (c == 'i' || c == 'd')
		ft_printinteger(va_arg(vargs, int), total);
	else if (c == 'p')
		ft_printpointer(va_arg(vargs, unsigned long long), total);
	else if (c == 'x' || c == 'X')
		ft_printhexa(va_arg(vargs, unsigned int), c, total);
	else if (c == 'u')
		ft_printunsigned(va_arg(vargs, unsigned int), total);
	else if (c == '%')
		ft_printchar('%', total);
	else
		(*i)--;
}
/**
 * Imprime una serie de datos en la salida estándar según un formato 
 * especificado.
 * Utiliza un bucle while para recorrer la cadena de formato.
 * Si encuentra un carácter %, llama a la función ft_type_print 
 * para imprimir el argumento correspondiente.
 * Si encuentra un carácter que no es %, lo imprime directamente.
 * Cuando termina de recorrer la cadena de formato, retorna el 
 * contador de caracteres escritos.
 *
 * @param string: La cadena de formato que especifica 
 * cómo imprimir los datos.
 * @param vargs: Una lista variable de argumentos 
 * a imprimir.
 * @return El número de caracteres escritos.
 */

int	ft_printf(const char *string, ...)
{
	int		total;
	int		i;
	va_list	vargs;

	total = 0;
	i = 0;
	va_start(vargs, string);
	while (string[i] != '\0')
	{
		if (string[i] == '%')
		{
			ft_type_print(string[++i], vargs, &total, &i);
			if (total == -1)
				return (-1);
			i++;
		}
		else
		{
			ft_printchar((char)string[i++], &total);
			if (total == -1)
				return (-1);
		}
	}
	va_end(vargs);
	return (total);
}
