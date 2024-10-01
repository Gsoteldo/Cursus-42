/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lore.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 22:08:54 by gsoteldo          #+#    #+#             */
/*   Updated: 2024/08/01 19:06:24 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	lore_begin(void)
{
	ft_printf("\n");
	ft_printf("-------------------------------------------------------------");
	ft_printf("------------------\n");
	ft_printf("                                 Español\n\n");
	ft_printf(GREEN"                    La leyenda de Sombra/");
	ft_printf("The Legend of Shadow\n" RC);
	ft_printf("\nEn el corazón de la noche, Sombra, el ladrón más hábil ");
	ft_printf("de la ciudad,\nse infiltró en la misteriosa Casa del Oro. ");
	ft_printf("Deslizando su figura entre sombras,\nse adentró en la ");
	ft_printf("mansión, donde brillaban monedas doradas bajo la tenue luz\n");
	ft_printf("de la luna. Con cada paso silencioso, la fortuna de Sombra ");
	ft_printf("se acercaba más\ny más, prometiendo riquezas inimaginables...");
	ft_printf("\n\n");
	ft_printf("                                 English\n\n");
	ft_printf("In the heart of the night, Shadow, the most skilled thief ");
	ft_printf("in the city,\ninfiltrated the mysterious House of Gold. ");
	ft_printf("Sliding his figure through shadows,\nhe entered the ");
	ft_printf("mansion, where golden coins shone under the dim light\n");
	ft_printf("of the moon. With each silent step, Shadow's fortune ");
	ft_printf("came closer\nand closer, promising unimaginable riches...\n");
	ft_printf("-------------------------------------------------------------");
	ft_printf("------------------\n\n");
}

void	lore_thinks(t_map *map)
{
	ft_printf("\n");
	ft_printf("-------------------------------------------------------------");
	ft_printf("------------------\n");
	ft_printf("                                 Español\n\n");
	ft_printf("Al acercarse a la puerta de salida, Sombra se detuvo un ");
	ft_printf("instante y pensó:\n");
	ft_printf("\n");
	ft_printf("\t\"No puedo irme aún, tengo que terminar lo que empecé, ");
	ft_printf("aun faltan %d monedas\"\n", map->n_collectable);
	ft_printf("\n");
	ft_printf("                                 English\n\n");
	ft_printf("As he approached the exit door, Shadow stopped for a moment ");
	ft_printf("and thought:\n\n");
	ft_printf("\t\"I can't leave yet, I have to finish what I started, ");
	ft_printf("there are still %d coins left\"\n", map->n_collectable);
	ft_printf("-------------------------------------------------------------");
	ft_printf("------------------\n\n");
}

void	lore_end(t_map *map)
{
	ft_printf("-------------------------------------------------------------");
	ft_printf("------------------\n\n");
	ft_printf("                                 Español\n\n");
	ft_printf("Con la bolsa llena de monedas y su corazón latiendo con la ");
	ft_printf("emoción\nde la victoria, se encaminó hacia la salida. ");
	ft_printf("Con un salto ágil, atravesó\nla puerta y se deslizó en la ");
	ft_printf("oscuridad de la noche.\n\n");
	ft_printf("Con todo el dinero conseguido, Sombra planeaba abandonar \n");
	ft_printf("su vida de ladrón para siempre. Utilizaría su botín para ");
	ft_printf("construir\nun refugio seguro para los huérfanos de la ciudad,");
	ft_printf(" ofreciendo esperanza\n y un futuro mejor a aquellos que, ");
	ft_printf("como él, habían vivido en las sombras.\n\n\t\t\t\tEnglish\n\n");
	ft_printf("With his bag full of coins and his heart beating with the ");
	ft_printf("excitement\nof victory, he headed towards the exit. With an ");
	ft_printf("agile leap, he crossed\nthe door and slid into the darkness ");
	ft_printf("of the night.\n\n");
	ft_printf("With all the money he had obtained, Shadow planned to leave ");
	ft_printf("his life of crime forever.\nHe would use his loot to build ");
	ft_printf("a safe shelter for the city's orphans,\noffering hope and a ");
	ft_printf("better future to those who, like him, had lived in ");
	ft_printf("the shadows.\n\n");
	ft_printf(GREEN"                                     FIN\n" RC);
	ft_printf("-------------------------------------------------------------");
	ft_printf("------------------\n\n");
	ft_printf("Total de movimientos: %d\n", map->n_movements);
}

void	instruction(void)
{
	ft_printf("\n");
	ft_printf("-------------------------------------------------------------");
	ft_printf("------------------\n");
	ft_printf("                                 Español\n\n");
	ft_printf("Instrucciones:\n\n");
	ft_printf("Mueve a Sombra con las teclas W, A, S, D (o las flechas).\n");
	ft_printf("Recoge todas las monedas antes de llegar a la puerta de ");
	ft_printf("Para salir, presiona la tecla ESC o cierra la ventana.\n");
	ft_printf("salida.\n\n");
	ft_printf("                                 English\n\n");
	ft_printf("Instructions:\n\n");
	ft_printf("Move Shadow with the W, A, S, D keys (or the arrows).\n");
	ft_printf("Collect all the coins before reaching the exit door.\n");
	ft_printf("To exit, press the ESC key or close the window.\n");
	ft_printf("-------------------------------------------------------------");
	ft_printf("------------------\n\n");
}
