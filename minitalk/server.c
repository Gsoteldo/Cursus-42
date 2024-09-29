/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 17:59:02 by gsoteldo          #+#    #+#             */
/*   Updated: 2024/03/31 17:44:11 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <signal.h>

#define RC "\x1b[0m"

/*Colores
	Blue: "\x1b[34m"
	ORANGE: "\x1b[33m"
*/

/**
 * @brief Manejador de señales para recibir mensajes.
 *
 * Esta función se encarga de manejar las señales recibidas para la recepción
 * de mensajes.
 * Cada vez que se recibe una señal, se va construyendo un carácter bit a bit
 * hasta completar 8 bits. Una vez completado el carácter, se imprime por
 * pantalla. Si se recibe una señal vacía, se muestra un mensaje indicando
 * que se está esperando un mensaje.
 *
 * @param sig La señal recibida.
 */
static void	handler(int sig)
{
	static char		c;
	static int		count;

	c |= (sig == SIGUSR2);
	if (++count == 8)
	{
		count = 0;
		if (!c)
		{
			ft_printf("\x1b[33m" "\n\n\nWaiting for message... \n" RC);
			return ;
		}
		ft_putchar_fd(c, 1);
		c = 0;
	}
	else
		c <<= 1;
}

int	main(void)
{
	ft_printf("\x1b[34m" "Server PID: " RC "%d\n\n", getpid());
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	ft_printf("\x1b[33m" "Waiting for message...\n" RC);
	while (1)
		pause();
	return (0);
}
