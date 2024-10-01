/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabo <gabo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 20:35:56 by gsoteldo          #+#    #+#             */
/*   Updated: 2024/07/26 01:00:56 by gabo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	up_movement(t_map *map)
{
	if (map->map[map->size.x - 1][map->size.y] == '1')
		return ;
	if (map->map[map->size.x - 1][map->size.y] == 'E')
	{
		if (map->n_collectable == 0)
		{
			map->exit_flag = 1;
			return ;
		}
		else
		{
			lore_thinks(map);
			return ;
		}
	}
	if (map->map[map->size.x - 1][map->size.y] == 'C')
		map->n_collectable--;
	map->map[map->size.x][map->size.y] = '0';
	map->size.x--;
	map->map[map->size.x][map->size.y] = 'P';
	map->n_movements++;
	ft_printf("Moves: %d\n", map->n_movements);
	load_images(map);
}

void	down_movement(t_map *map)
{
	if (map->map[map->size.x + 1][map->size.y] == '1')
		return ;
	if (map->map[map->size.x + 1][map->size.y] == 'E')
	{
		if (map->n_collectable == 0)
		{
			map->exit_flag = 1;
			return ;
		}
		else
		{
			lore_thinks(map);
			return ;
		}
	}
	if (map->map[map->size.x + 1][map->size.y] == 'C')
		map->n_collectable--;
	map->map[map->size.x][map->size.y] = '0';
	map->size.x++;
	map->map[map->size.x][map->size.y] = 'P';
	map->n_movements++;
	ft_printf("Moves: %d\n", map->n_movements);
	load_images(map);
}

void	left_movement(t_map *map)
{
	if (map->map[map->size.x][map->size.y - 1] == '1')
		return ;
	if (map->map[map->size.x][map->size.y - 1] == 'E')
	{
		if (map->n_collectable == 0)
		{
			map->exit_flag = 1;
			return ;
		}
		else
		{
			lore_thinks(map);
			return ;
		}
	}
	if (map->map[map->size.x][map->size.y - 1] == 'C')
		map->n_collectable--;
	map->map[map->size.x][map->size.y] = '0';
	map->size.y--;
	map->map[map->size.x][map->size.y] = 'P';
	map->n_movements++;
	ft_printf("Moves: %d\n", map->n_movements);
	load_images(map);
}

void	right_movement(t_map *map)
{
	if (map->map[map->size.x][map->size.y + 1] == '1')
		return ;
	if (map->map[map->size.x][map->size.y + 1] == 'E')
	{
		if (map->n_collectable == 0)
		{
			map->exit_flag = 1;
			return ;
		}
		else
		{
			lore_thinks(map);
			return ;
		}
	}
	if (map->map[map->size.x][map->size.y + 1] == 'C')
		map->n_collectable--;
	map->map[map->size.x][map->size.y] = '0';
	map->size.y++;
	map->map[map->size.x][map->size.y] = 'P';
	map->n_movements++;
	ft_printf("Moves: %d\n", map->n_movements);
	load_images(map);
}

int	movements(int key, t_map *map)
{
	if (key == W_KEY || key == UP_KEY)
		up_movement(map);
	else if (key == A_KEY || key == LEFT_KEY)
		left_movement(map);
	else if (key == S_KEY || key == DOWN_KEY)
		down_movement(map);
	else if (key == D_KEY || key == RIGHT_KEY)
		right_movement(map);
	else if (key == ESC)
	{
		free_map(map);
		exit(0);
	}
	if (map->exit_flag == 1)
		mlx_loop_end(map->mlx);
	return (0);
}
