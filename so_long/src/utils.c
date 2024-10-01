/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 17:35:57 by gsoteldo          #+#    #+#             */
/*   Updated: 2024/07/31 21:21:51 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	print_error(int message_flag)
{
	ft_putstr_fd(RED "Error:\n" RC, 2);
	if (message_flag == 1)
		ft_putstr_fd("\t[No se encontro mapa]\n\n", 2);
	else if (message_flag == 2)
		ft_putstr_fd("\t[mapa invalido]\n\n", 2);
	else if (message_flag == 3)
		ft_putstr_fd("\t[Mapa no rodeado de paredes]\n\n", 2);
	else if (message_flag == 4)
		ft_putstr_fd("\t[Mapa imposible de resolver]\n\n", 2);
	else if (message_flag == 5)
		ft_putstr_fd("\t[No se pudieron cargar las imagenes]\n\n", 2);
	else if (message_flag == 0)
		ft_putstr_fd("\t[Extension invalida]\n\n", 2);
	exit(0);
}

void	initialize_map(t_map *map)
{
	map->mlx = NULL;
	map->win = NULL;
	map->file = NULL;
	map->size.x = 0;
	map->size.y = 0;
	map->size.width = 0;
	map->size.height = 0;
	map->n_collectable = 0;
	map->n_exit = 0;
	map->n_movements = 0;
	map->n_start = 0;
	map->n_collectable = 0;
	map->exit_flag = 0;
	map->map = NULL;
	map->map_copy = NULL;
	map->mlx = NULL;
	map->win = NULL;
	map->img.collectable = NULL;
	map->img.floor = NULL;
	map->img.locked_exit = NULL;
	map->img.player = NULL;
	map->img.unlocked_exit = NULL;
	map->img.wall = NULL;
}

void	destroy_map(t_map *map)
{
	if (map->img.collectable)
		mlx_destroy_image(map->mlx, map->img.collectable);
	if (map->img.floor)
		mlx_destroy_image(map->mlx, map->img.floor);
	if (map->img.locked_exit)
		mlx_destroy_image(map->mlx, map->img.locked_exit);
	if (map->img.player)
		mlx_destroy_image(map->mlx, map->img.player);
	if (map->img.unlocked_exit)
		mlx_destroy_image(map->mlx, map->img.unlocked_exit);
	if (map->img.wall)
		mlx_destroy_image(map->mlx, map->img.wall);
	if (map->win)
		mlx_destroy_window(map->mlx, map->win);
	if (map->mlx)
	{
		mlx_destroy_display(map->mlx);
		free(map->mlx);
	}
}

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	destroy_map(map);
	if (map->map && map->map_copy)
	{
		while (map->map[i])
		{
			free(map->map[i]);
			free(map->map_copy[i]);
			i++;
		}
		free(map->map);
		free(map->map_copy);
	}
}

int	close_windows(t_map *map)
{
	mlx_loop_end(map->mlx);
	free_map(map);
	exit(0);
}
