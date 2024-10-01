/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsoteldo <gsoteldo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 21:42:46 by gabo              #+#    #+#             */
/*   Updated: 2024/08/01 17:54:35 by gsoteldo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../mlx/mlx.h"

# define RC "\x1b[0m"
# define RED "\x1b[31m"
# define GREEN "\x1b[32m"

# define ESC 65307
# define CLOSE_BUTTON 17 
# define W_KEY 119
# define A_KEY 97
# define S_KEY 115
# define D_KEY 100
# define UP_KEY 65362
# define DOWN_KEY 65364
# define LEFT_KEY 65361
# define RIGHT_KEY 65363
# define SIZE 80

/*Position and Size Struct*/
typedef struct s_size
{
	int	x;
	int	y;
	int	width;
	int	height;
}				t_size;

/*Image Struct*/
typedef struct s_image
{
	void	*collectable;
	void	*floor;
	void	*locked_exit;
	void	*player;
	void	*unlocked_exit;
	void	*wall;
}				t_image;

/*Map and Game Struct*/
typedef struct s_map
{
	void	*mlx;
	void	*win;
	char	**map_copy;
	char	**map;
	char	*file;
	int		exit_flag;
	int		fd;
	int		n_collectable;
	int		n_exit;
	int		n_movements;
	int		n_start;
	t_image	img;
	t_size	size;
}				t_map;

/*Checker and Error Functions*/
int		check_map(t_map *map);
void	comprobation_map(t_map *map);
void	comprobation_wall(t_map *map);
int		is_rectangle(char **map);
int		surrounded_by_walls(char **map);
int		has_empty_lines_in_middle(char *str);
int		is_valid_map(t_map *map);
void	split_and_comprobation(t_map *map, char *line);
void	print_error(int message_flag);
/*Map and Window Function*/
void	free_map(t_map *map);
void	initialize_map(t_map *map);
void	load_images(t_map *map);
/*Game Functions*/
int		close_windows(t_map *map);
int		movements(int key, t_map *map);
/*Lore Function*/
void	instruction(void);
void	lore_begin(void);
void	lore_thinks(t_map *map);
void	lore_end(t_map *map);

#endif