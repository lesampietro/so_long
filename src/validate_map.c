/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 17:40:08 by lsampiet          #+#    #+#             */
/*   Updated: 2024/04/14 18:12:22 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_map_shape(char **map, t_map *map_data)
{
	int	i;
	int	j;

	i = 0;
	while(map[i])
	{
		j = 0;
		while ((map[i][j]) && (map[i][j] != '\n'))
			j++;
		if (j != (map_data->columns))
			exit(ft_printf("Map is not rectangular\n"));
		i++;
	}
}

void	check_col_lin_size(char **map, t_map *map_data)
{
	int i;

	i = 0;
	while (map[i])
		i++;
	if ((i < 5) && (map_data->columns < 4))
		exit(ft_printf("Map size is invalid\n"));
	else if ((map_data->columns < 5) && (i < 4))
		exit(ft_printf("Map size is invalid\n"));
}

void	check_map_walls(char **map, t_map *map_data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if(!(ft_strchr("1", map[i][j])) && i == 0)
				exit(ft_printf("Map is not closed by walls\n"));
			if (!(ft_strchr("1", map[i][j])) && ((j == 0) || (j == (map_data->columns) - 1)))
				exit(ft_printf("Map is not closed by walls\n"));
			j++;
		}
		i++;
	}
	j = 0;
	while (map[(map_data->lines) - 1][j])
	{
		if (!(ft_strchr("1", map[(map_data->lines) - 1][j])))
			exit(ft_printf("Map is not closed by walls\n"));
		j++;
	}
}

void	is_valid_map(char **map)
{
	t_map temp;
	
	newline_off(map);
	check_map_chars(map, &temp);
	occurence_count(map, &temp);
	check_map_shape(map, &temp);
	check_col_lin_size(map, &temp);
	check_map_walls(map, &temp);
	//floodfill(map, &temp);
}