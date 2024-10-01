/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 17:27:42 by gsoteldo          #+#    #+#             */
/*   Updated: 2024/01/08 18:14:40 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * Escribe un solo carácter en un descriptor de archivo especificado.
 * Utiliza la función write del sistema operativo para escribir el carácter.
 *
 * @param c: El carácter a escribir.
 * @param  fd: El descriptor de archivo donde escribir el carácter.
 */

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
