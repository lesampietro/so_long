/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 18:50:53 by lsampiet          #+#    #+#             */
/*   Updated: 2024/05/13 12:45:49 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H
# define VALID_CHARSET "01PCEG\n"
# define TILE 64

# define ERROR_ARG_B "Error.\nMissing argument.\n"
# define ERROR_EXT_B "Error.\nInvalid map file extension.\n"
# define ERROR_EMPTY_MAP_B "Error.\nMap is empty or doesn't exist.\n"
# define ERROR_FLOODFILL_B "Error.\nUnreachable collectible or exit.\n"
# define ERROR_MAP_DISPLAY_B "Error.\nMap image could not be displayed.\n"
# define ERROR_MAP_SHAPE_B "Error.\nMap is not rectangular.\n"
# define ERROR_MAP_SIZE_B "Error.\nMap size is invalid.\n"
# define ERROR_MAP_WALLS_B "Error.\nMap is not closed by walls.\n"
# define ERROR_MAP_2BIG_B "Error.\nMap is too big.\n"
# define ERROR_MLX_LOAD_B "Error.\nCould not initialize MLX handle instance.\n"
# define ERROR_MAP_P_B "Error.\nInvalid number of players.\n"
# define ERROR_MAP_E_B "Error.\nInvalid number of exits.\n"
# define ERROR_MAP_C_B "Error.\nThere are no collectibles on the map.\n"
# define ERROR_MAP_G_B "Error.\nThere are no enemies on the map.\n"
# define ERROR_MAP_CHARS_B "Error.\nMap with invalid characters.n"
# define ERROR_TEXTURE_B "Error.\nTexture could not be loaded.\n"
# define ERROR_IMG_B "Error.\nImage could not be created.\n"
# define ERROR_ASSET_DISPLAY_B "Error.\nAssets could not be displayed.\n"
# define ERROR_STEPS_B "Error.\nStep counter was not malloc'd.\n"
# define END_SUCCESS "Congratulations!\nPagu's belly is full and she's happy'\n"
# define END_FAIL "Oh no!\nYou lost!\n"

# include <stdlib.h>
# include "../lib/MLX42/include/MLX42/MLX42.h"
# include "../lib/gnl/includes/get_next_line.h"
# include "../lib/ft_printf/includes/ft_printf.h"
# include "../lib/libft/libft.h"

typedef struct s_map	t_map;
typedef struct s_pos	t_pos;
typedef struct s_img	t_img;
typedef struct s_game	t_game;

enum e_directions {
	RIGHT,
	LEFT,
	TOP,
	BOTTOM
};

struct s_pos
{
	int	x;
	int	y;
};

struct s_map
{
	int		player;
	int		collects;
	int		defo_collects;
	int		ghosts;
	int		exit;
	int		columns;
	int		lines;
	t_pos	position;
};

struct s_img
{
	mlx_image_t	*wall;
	mlx_image_t	*floor;
	mlx_image_t	*collects;
	mlx_image_t	*exit;
	mlx_image_t	*ghost;
	mlx_image_t	*p_r0;
	mlx_image_t	*p_r1;
	mlx_image_t	*p_r2;
	mlx_image_t	*p_r3;
	mlx_image_t	*p_l0;
	mlx_image_t	*p_l1;
	mlx_image_t	*p_l2;
	mlx_image_t	*p_l3;
};

struct s_game
{
	char			**map;
	mlx_t			*mlx;
	int				col;
	int				lin;
	int				end_game;
	int				steps;
	int				player_side;
	t_pos			player_pos;
	t_map			occ;
	mlx_image_t		*counter;
	mlx_image_t		*counter_txt;
	mlx_texture_t	*icon;
	t_img			img;
};

/*Map validation functions*/
char		**read_map(char *map);
int			count_lines(char *map);
void		is_valid_entry(char **file_ext);
void		is_valid_map(char **file_ext);
void		newline_off(char **map);
void		check_map_chars(char **map, t_map *map_data);
void		check_chars_count(char **map, t_map *map_data);
void		occurence_count(char **map, t_map *map_data);
void		check_map_shape(char **map, t_map *map_data);
void		check_col_lin_size(char **map, t_map *map_data);
void		check_map_walls(char **map, t_map *map_data);
void		floodfill(char **map, t_map *map_data);

/*Game Initialization functions*/
int32_t		init_game(char *argv, t_game *game);
void		init_window(t_game *game);
void		init_values(t_game *game);
void		get_player_pos(char **map, t_pos *position);

/*Image functions*/
void		put_counter(t_game *game);
void		count_map_size(t_game *game);
void		init_game_image(t_game *game);
mlx_image_t	*create_img(mlx_t *mlx, char *img_path);
void		display_img(t_game *game);
void		display_icon(t_game *game);
void		put_player(t_game *game);
void		put_floor_n_walls(t_game *game);
void		put_collects_n_exit(t_game *game);
void		put_ghost(t_game *game);

/*Moving and playing functions*/
void		init_move(mlx_key_data_t keydata, void *param);
void		player_moves(t_game *game, int movement);
void		validate_collects(t_game *game);
void		validate_moves(t_game *game, int movement);
void		validate_exit(mlx_key_data_t keydata, t_game *game);
void		counter(t_game *game);

/*Animation functions*/
void		put_player_frames(t_game *game, int col, int line);
void		timer(void *param);
void		init_anim_images(t_game *game);
void		anim_images_off(t_game *game);
void		check_side(t_game *game);
void		animate_player_right(t_game *game);
void		animate_player_left(t_game *game);

/*Cleaning & error functions*/
void		delete_images(t_game *game);
void		delete_textures(t_game *game);
void		free_map(char **map);
void		free_game(t_game *game);
void		ft_error(char *str, char **map);

#endif