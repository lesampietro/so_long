/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 18:50:53 by lsampiet          #+#    #+#             */
/*   Updated: 2024/04/14 18:08:59 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define VALID_CHARSET "01PCE\n"

#include <stdlib.h>

#include "../lib/MLX42/include/MLX42/MLX42.h"
#include "../lib/gnl/includes/get_next_line.h"
#include "../lib/ft_printf/includes/ft_printf.h"
#include "../lib/libft/libft.h"

typedef struct s_map	t_map;

struct s_map
{
	int	player;
	int	collects;
	int	exit;
	int	columns;
	int	lines;
};

char	**read_map(char *map);
void	is_valid_entry(char **file_ext);
void	is_valid_map(char **file_ext);
void	newline_off(char **map);
void	check_map_chars(char **map, t_map *map_data);
void	check_chars_count(t_map *map_data);
void	occurence_count(char **map, t_map *map_data);
void	check_map_shape(char **map, t_map *map_data);
void	check_col_lin_size(char **map, t_map *map_data);
void	check_map_walls(char **map, t_map *map_data);

#endif