/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 17:28:55 by gsoteldo          #+#    #+#             */
/*   Updated: 2024/01/08 18:09:32 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * Escribe una cadena de caracteres seguida de un salto de línea en un 
 * descriptor de archivo especificado.
 * Primero llama a la función ft_putstr_fd para escribir la cadena 
 * de caracteres.
 * Luego llama a la función ft_putchar_fd para escribir un salto de línea.
 *
 * @param s: La cadena de caracteres a escribir.
 * @param fd: El descriptor de archivo donde escribir la cadena de caracteres 
 * y el salto de línea.
 */

void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}
