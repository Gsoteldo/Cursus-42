/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 17:29:31 by gsoteldo          #+#    #+#             */
/*   Updated: 2024/01/08 18:13:50 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * Escribe una cadena de caracteres en un descriptor de archivo especificado.
 * Utiliza la función write del sistema operativo para escribir la cadena 
 * de caracteres.
 * La longitud de la cadena de caracteres se obtiene con 
 * la función ft_strlen.
 *
 * @param s:  La cadena de caracteres a escribir.
 * @param fd: El descriptor de archivo donde escribir la cadena de caracteres.
 */

void	ft_putstr_fd(char *s, int fd)
{
	if (s == NULL)
		return ;
	write(fd, s, ft_strlen(s));
}
