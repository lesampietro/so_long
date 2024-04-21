/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 18:50:53 by lsampiet          #+#    #+#             */
/*   Updated: 2024/04/21 19:33:09 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define VALID_CHARSET "01PCE\n"
# define TILE 64

#include <stdlib.h>

#include "../lib/MLX42/include/MLX42/MLX42.h"
#include "../lib/gnl/includes/get_next_line.h"
#include "../lib/ft_printf/includes/ft_printf.h"
#include "../lib/libft/libft.h"

typedef struct s_map	t_map;
typedef struct s_pos	t_pos;
typedef struct s_game	t_game;
typedef struct s_img	t_img;

struct s_pos
{
	int x;
	int y;
};

struct s_map
{
	int		player;
	int		collects;
	int		exit;
	int		columns;
	int		lines;
	t_pos	position;
};

struct s_game
{
	char	**map;
	mlx_t	*mlx;
	int		col;
	int		lin;
	t_img	*texture;
	t_img	*image;
};

struct s_texture
{
	mlx_texture_t	*wall;
	mlx_texture_t	*floor;
	mlx_texture_t	*player;
	mlx_texture_t	*collects;
	mlx_texture_t	*exit;
	mlx_image_t		*wall_img;
	mlx_image_t		*floor_img;
	mlx_image_t		*player_img;
	mlx_image_t		*collects_img;
	mlx_image_t		*exit_img;
};

char	**read_map(char *map);
void	is_valid_entry(char **file_ext);
void	is_valid_map(char **file_ext);
void	newline_off(char **map);
void	check_map_chars(char **map, t_map *map_data);
void	check_chars_count(char **map,t_map *map_data);
void	occurence_count(char **map, t_map *map_data);
void	check_map_shape(char **map, t_map *map_data);
void	check_col_lin_size(char **map, t_map *map_data);
void	check_map_walls(char **map, t_map *map_data);
void	floodfill(char **map, t_map *map_data);
void	get_player_pos(char **map, t_map *map_data);
void	ft_error(char *str, char **map);
void	free_map(char **map);
int32_t	init_game(char *argv, t_game *game);

#endif