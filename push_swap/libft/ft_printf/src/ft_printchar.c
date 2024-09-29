/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 18:11:25 by gsoteldo          #+#    #+#             */
/*   Updated: 2024/01/08 18:15:48 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

/**
 * Escribe un carácter en la salida estándar y actualiza un contador 
 * de caracteres escritos.
 * Utiliza la función write del sistema operativo para escribir el carácter.
 * Si la función write retorna -1, establece el valor apuntado por el 
 * puntero a -1 y termina la función.
 * Si la función write retorna un número distinto de -1, suma ese número 
 * al valor apuntado por el puntero.
 *
 * @param c: El carácter a escribir.
 * @param total: Un puntero a un entero que se actualizará con el número 
 * de caracteres escritos.
 */

void	ft_printchar(int c, int *total)
{
	int	aux;

	aux = write(1, &c, 1);
	if (aux == -1)
	{
		*total = -1;
		return ;
	}
	*total = *total + aux;
}
