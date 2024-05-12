/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 17:40:08 by lsampiet          #+#    #+#             */
/*   Updated: 2024/05/12 05:17:56 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	flood_path(char **map, int x, int y)
{
	if (map[x][y] != '1')
	{
		map[x][y] = '1';
		flood_path(map, x + 1, y);
		flood_path(map, x - 1, y);
		flood_path(map, x, y + 1);
		flood_path(map, x, y - 1);
	}
}

void	get_player_pos(char **map, t_pos *position)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				position->x = j;
				position->y = i;
			}
			j++;
		}
		i++;
	}
}

void	check_flood(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (ft_strchr("CE", map[i][j]))
				ft_error(ERROR_FLOODFILL, map);
			j++;
		}
		i++;
	}
}

void	floodfill(char **map, t_map *map_data)
{
	get_player_pos(map, &map_data->position);
	flood_path(map, map_data->position.x, map_data->position.y);
	check_flood(map);
}
