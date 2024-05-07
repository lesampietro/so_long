/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 17:40:08 by lsampiet          #+#    #+#             */
/*   Updated: 2024/05/06 23:55:40 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	is_valid_entry(char **file_ext)
{
	char	*valid_ext;
	char	*ext;

	valid_ext = ".ber";
	ext = ft_strrchr(*file_ext, '.');
	if (!ext)
		ft_error(ERROR_EXT_B, NULL);
	if ((ft_strlen(ext) != 4) || (ft_strncmp(ext, valid_ext, 4) != 0))
		ft_error(ERROR_EXT_B, NULL);
}

void	check_map_shape(char **map, t_map *map_data)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while ((map[i][j]) && (map[i][j] != '\n'))
			j++;
		if (j != (map_data->columns))
			ft_error(ERROR_MAP_SHAPE_B, map);
		i++;
	}
}

void	check_col_lin_size(char **map, t_map *map_data)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	if ((i < 5) && (map_data->columns < 4))
		ft_error(ERROR_MAP_SIZE_B, map);
	else if ((map_data->columns < 5) && (i < 4))
		ft_error(ERROR_MAP_SIZE_B, map);
}

void	check_map_walls(char **map, t_map *map_data)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (!(ft_strchr("1", map[i][j])) && i == 0)
				ft_error(ERROR_MAP_WALLS_B, map);
			if (!(ft_strchr("1", map[i][j])) && ((j == 0)
				|| (j == (map_data->columns) - 1)))
				ft_error(ERROR_MAP_WALLS_B, map);
			j++;
		}
		i++;
	}
	j = 0;
	while (map[(map_data->lines) - 1][j])
	{
		if (!(ft_strchr("1", map[(map_data->lines) - 1][j])))
			ft_error(ERROR_MAP_WALLS_B, map);
		j++;
	}
}

void	is_valid_map(char **map)
{
	t_map	temp;

	newline_off(map);
	check_map_chars(map, &temp);
	occurence_count(map, &temp);
	check_map_shape(map, &temp);
	check_col_lin_size(map, &temp);
	check_map_walls(map, &temp);
	floodfill(map, &temp);
}
