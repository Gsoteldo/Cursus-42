/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 21:28:35 by gabo              #+#    #+#             */
/*   Updated: 2024/08/01 19:24:13 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "../mlx/mlx.h"

static int	check_extension(char *map)
{
	size_t	size;
	char	*first_dot;
	char	*last_dot;

	first_dot = ft_strchr(map, '.');
	last_dot = ft_strrchr(map, '.');
	if (first_dot == NULL || last_dot == NULL)
		print_error(0);
	if (ft_strncmp(last_dot, first_dot, 5) == 0)
	{
		size = ft_strlen(map);
		if ((map[size - 4] != '.' || map[size - 3] != 'b'
				|| map[size - 2] != 'e'
				|| map[size - 1] != 'r'))
			print_error(0);
	}
	else
		print_error(0);
	return (1);
}

static int	comprobation(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putstr_fd(RED "Error! " RC, 2);
		ft_putstr_fd("Se necesita este formato: \n", 2);
		ft_putstr_fd("\n\t./so_long (nombre_del_archivo).ber\n\n", 2);
		return (0);
	}
	else if (check_extension(argv[1]) == 0)
		return (0);
	else
		return (1);
}

/*
int key_view(int key, void * param)
{
	t_map *map_copy;

	map_copy = (t_map *)param;
	ft_printf("Key: %d\n", key);	
	return (0);
}
*/

void	start_game(t_map *map)
{
	map->mlx = mlx_init();
	if (!map->mlx)
	{
		ft_putstr_fd(RED "Error! " RC, 2);
		ft_putstr_fd("No se pudo iniciar el mlx\n", 2);
		return ;
	}
	if (map->size.width <= 40 && map->size.height <= 100)
		map->win = mlx_new_window(map->mlx, map->size.height * SIZE, \
			map->size.width * SIZE, "La leyenda de Sombra");
	if (!map->win)
	{
		ft_putstr_fd(RED "Error! " RC, 2);
		ft_putstr_fd("No se pudo iniciar la ventana\n", 2);
		free_map(map);
		print_error(2);
	}
	lore_begin();
	instruction();
	load_images(map);
	mlx_hook(map->win, CLOSE_BUTTON, 1L << 0, close_windows, map);
	mlx_key_hook(map->win, movements, map);
	mlx_loop(map->mlx);
}

int	main(int argc, char *argv[])
{
	t_map	map;

	initialize_map(&map);
	if (comprobation(argc, argv) == 0)
		return (0);
	map.file = argv[1];
	map.fd = open(map.file, O_RDONLY);
	if (map.fd < 0)
		print_error(1);
	if (check_map(&map) == 0)
		return (0);
	start_game(&map);
	lore_end(&map);
	free_map(&map);
	return (0);
}
