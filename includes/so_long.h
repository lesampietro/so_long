/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 18:50:53 by lsampiet          #+#    #+#             */
/*   Updated: 2024/05/04 22:49:44 by lsampiet         ###   ########.fr       */
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

enum directions {
	RIGHT,
	LEFT,
	TOP,
	BOTTOM
};

struct s_pos
{
	int x;
	int y;
};

struct s_map
{
	int		player;
	int		collects;
	int		defo_collects;
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
	int		end_game;
	int		steps;
	t_pos	player_pos;
	t_map	occ;
	t_img	*texture;
	t_img	*image;
};

struct s_img
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

/*Map validation functions*/
char	**read_map(char *map);
int		count_lines(char *map);
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

/*Game Initialization functions*/
int32_t	init_game(char *argv, t_game *game);
void	init_window(t_game *game);
void	init_values(t_game *game);
void	get_player_pos(char **map, t_pos *position);

/*Map drawing functions*/
void	count_map_size(t_game *game);
void	init_game_image(t_game *game);
void	init_tile_textures(t_game *game);
void	init_tile_images(t_game *game);
void	put_player(t_game *game);
void	put_floor_n_walls(t_game *game);
void	put_collects_n_exit(t_game *game);

/*Moving and playing functions*/
void	init_move(mlx_key_data_t keydata, void *param);
void	player_moves(t_game *game, int movement);
void	validate_collects(t_game *game);
void	validate_moves(t_game *game, int movement);
void	validate_exit(mlx_key_data_t keydata, t_game *game);
void	counter(t_game *game);

/*Cleaning & error functions*/
void	delete_images(t_game *game);
void	delete_textures(t_game *game);
void	free_map(char **map);
void	free_game(t_game *game);
void	ft_error(char *str, char **map);

#endif