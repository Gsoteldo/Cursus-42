/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 11:36:58 by gabo              #+#    #+#             */
/*   Updated: 2024/09/05 19:25:59 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	surrounded_by_walls(char **map)
{
	int	i;
	int	j;
	int	size;

	i = 0;
	j = 0;
	size = 0;
	while (map[i++])
		size++;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (i == 0 || i == size - 1 || j == 0
				|| (size_t)j == ft_strlen(map[i]) - 1)
				if (map[i][j] != '1')
					print_error(3);
			j++;
		}
		i++;
	}
	return (1);
}

void	flood_fill(t_map *map, int pos_x, int pos_y)
{
	if (pos_x < 0 || pos_x >= map->size.width
		|| pos_y < 0 || pos_y >= map->size.height
		|| map->map_copy[pos_x][pos_y] == '1'
		|| map->map_copy[pos_x][pos_y] == 'X')
		return ;
	if (map->map_copy[pos_x][pos_y] == 'C')
		map->n_collectable--;
	if (map->map_copy[pos_x][pos_y] == 'E'
		&& map->n_collectable != 0)
		return ;
	if (map->map_copy[pos_x][pos_y] != 'E' \
		&& map->map_copy[pos_x][pos_y] != 'C' \
		&& map->map_copy[pos_x][pos_y] != 'P' \
		&& map->map_copy[pos_x][pos_y] != '0' \
		&& map->map_copy[pos_x][pos_y] != '1')
	{
		free_map(map);
		print_error(2);
	}
	map->map_copy[pos_x][pos_y] = 'X';
	flood_fill(map, pos_x + 1, pos_y);
	flood_fill(map, pos_x - 1, pos_y);
	flood_fill(map, pos_x, pos_y + 1);
	flood_fill(map, pos_x, pos_y - 1);
}

int	is_valid_map(t_map *map)
{
	int	i;
	int	pos_x;
	int	pos_y;
	int	n_collectable;

	i = 0;
	pos_x = map->size.x;
	pos_y = map->size.y;
	n_collectable = map->n_collectable;
	flood_fill(map, pos_x, pos_y);
	while (map->map_copy[i])
	{
		if ((ft_strchr(map->map_copy[i], 'E') != 0
				|| ft_strchr(map->map_copy[i], 'C') != 0))
		{
			free_map(map);
			print_error(4);
		}
		i++;
	}
	map->n_collectable = n_collectable;
	return (1);
}

int	is_rectangle(char **map)
{
	int		i;
	size_t	size;

	i = 1;
	size = ft_strlen(map[0]);
	while (map[i])
	{
		if (ft_strlen(map[i]) != size)
		{
			ft_printf("No es rectangular\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_map(t_map *map)
{
	char	*line;
	char	*aux;
	char	*temp;

	aux = ft_strdup("");
	line = get_next_line(map->fd);
	while (line != NULL)
	{
		temp = aux;
		aux = ft_strjoin(aux, line);
		free(temp);
		free(line);
		line = get_next_line(map->fd);
	}
	temp = ft_strtrim(aux, "\n");
	free(aux);
	if (has_empty_lines_in_middle(temp) == 1)
	{
		free(temp);
		free_map(map);
		print_error(4);
	}
	split_and_comprobation(map, temp);
	close(map->fd);
	return (1);
}
