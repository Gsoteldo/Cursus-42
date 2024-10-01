/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comprobation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 18:44:45 by gsoteldo          #+#    #+#             */
/*   Updated: 2024/08/01 17:06:31 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	comprobation_characters(t_map *map, int i, int j)
{
	if (map->map_copy[i][j] == 'C')
		map->n_collectable++;
	if (map->map_copy[i][j] == 'E')
		map->n_exit++;
	if (map->map_copy[i][j] == 'P')
	{
		map->n_start++;
		map->size.x = i;
		map->size.y = ft_strchr(map->map_copy[i], 'P') - map->map_copy[i];
	}
}

void	comprobation_map(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map_copy[i] != NULL)
	{
		j = 0;
		while (map->map_copy[i][j++] != '\0')
			comprobation_characters(map, i, j);
		i++;
	}
	if (map->n_collectable == 0 || map->n_exit != 1 || map->n_start != 1)
	{
		free_map(map);
		print_error(2);
	}
	map->size.width = i;
	map->size.height = ft_strlen(map->map_copy[0]);
}

void	comprobation_wall(t_map *map)
{
	if (is_rectangle(map->map_copy) == 0
		|| surrounded_by_walls(map->map_copy) == 0)
	{
		free_map(map);
		print_error(3);
	}
	if (is_valid_map(map) == 0)
	{
		free_map(map);
		print_error(4);
	}
}

int	has_empty_lines_in_middle(char *str)
{
	int	line_started;
	int	line_ended;

	line_started = 0;
	line_ended = 0;
	while (*str)
	{
		if (*str == '\n')
		{
			if (line_started && !line_ended)
				line_ended = 1;
			else if (line_ended)
				return (1);
		}
		else
		{
			if (line_ended)
				line_ended = 0;
			line_started = 1;
		}
		str++;
	}
	return (0);
}

void	split_and_comprobation(t_map *map, char *line)
{
	map->map = ft_split(line, '\n');
	map->map_copy = ft_split(line, '\n');
	free(line);
	if (map->map == NULL || map->map_copy == NULL)
	{
		free_map(map);
		print_error(1);
	}
	comprobation_map(map);
	comprobation_wall(map);
}
