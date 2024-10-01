/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 17:02:43 by gabo              #+#    #+#             */
/*   Updated: 2024/07/30 21:55:16 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	error_loading(t_map *map)
{
	if (!map->img.collectable || !map->img.floor || !map->img.locked_exit
		|| !map->img.player || !map->img.unlocked_exit || !map->img.wall)
	{
		free_map(map);
		print_error(5);
	}
}

void	load_sprites(t_map *map)
{
	int	width;
	int	height;

	if (!map->mlx || !map->win || !map)
	{
		free_map(map);
		print_error(4);
	}
	map->img.collectable = mlx_xpm_file_to_image(map->mlx, \
		"./textures/collectable.xpm", &width, &height);
	map->img.floor = mlx_xpm_file_to_image(map->mlx, \
		"./textures/floor.xpm", &width, &height);
	map->img.locked_exit = mlx_xpm_file_to_image(map->mlx, \
		"./textures/locked_door.xpm", &width, &height);
	map->img.player = mlx_xpm_file_to_image(map->mlx, \
		"./textures/player.xpm", &width, &height);
	map->img.unlocked_exit = mlx_xpm_file_to_image(map->mlx, \
		"./textures/unlocked_door.xpm", &width, &height);
	map->img.wall = mlx_xpm_file_to_image(map->mlx, \
		"./textures/wall.xpm", &width, &height);
	error_loading(map);
}

void	put_image_to_window(t_map *map, int i, int j)
{
	if (map->map[i][j] == '1')
		mlx_put_image_to_window(map->mlx, map->win, map->img.wall, \
			j * SIZE, i * SIZE);
	else if (map->map[i][j] == '0')
		mlx_put_image_to_window(map->mlx, map->win, map->img.floor, \
			j * SIZE, i * SIZE);
	else if (map->map[i][j] == 'C')
		mlx_put_image_to_window(map->mlx, map->win, map->img.collectable, \
			j * SIZE, i * SIZE);
	else if (map->map[i][j] == 'E')
	{
		mlx_put_image_to_window(map->mlx, map->win, map->img.locked_exit, \
			j * SIZE, i * SIZE);
		if (map->n_collectable == 0)
			mlx_put_image_to_window(map->mlx, map->win, map->img.unlocked_exit, \
				j * SIZE, i * SIZE);
	}
	else if (map->map[i][j] == 'P')
		mlx_put_image_to_window(map->mlx, map->win, map->img.player, j * SIZE, \
			i * SIZE);
}

void	load_images(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!map->mlx || !map->win || !map)
	{
		free_map(map);
		print_error(4);
	}
	if (!map->img.collectable || !map->img.floor || !map->img.locked_exit
		|| !map->img.player || !map->img.unlocked_exit || !map->img.wall)
		load_sprites(map);
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			put_image_to_window(map, i, j);
			j++;
		}
		i++;
	}
}
