/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_chars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 17:40:08 by lsampiet          #+#    #+#             */
/*   Updated: 2024/04/28 19:22:01 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	newline_off(char **map)
{
	int	i;
	int	j;

	i = 0;
	while(map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '\n')
				map[i][j] = '\0';
			j++;
		}
		i++;
		
	}
}

void	check_map_chars(char **map, t_map *map_data)
{
	int	i;
	int	j;
	
	i = 0;
	while(map[i])
	{
		j = 0;
		while(map[i][j])
		{
			if(!(ft_strchr(VALID_CHARSET, map[i][j])))
				ft_error("Error.\nMap with invalid characters.n", map);
			j++;
		}
		i++;
	}
	map_data->lines = i;
	map_data->columns = j;
}

void	check_chars_count(char **map, t_map *map_data)
{
	if (map_data->player != 1)
		ft_error("Error.\nInvalid number of players.\n", map);
	else if (map_data->exit != 1)
		ft_error("Error.\nInvalid number of exits.\n", map);
	else if (map_data->collects < 1)
		ft_error("Error.\nThere are no collectibles on the map.\n", map);
	return;
}

void	occurence_count(char **map, t_map *map_data)
{
	int i;
	int j;

	i = 0;
	map_data->player = 0;
	map_data->collects = 0;
	map_data->exit = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				map_data->player += 1;
			else if (map[i][j] == 'C')
				map_data->collects += 1;
			else if (map[i][j] == 'E')
				map_data->exit += 1;
			j++;
		}
		i++;
	}
	map_data->defo_collects = map_data->collects;
	check_chars_count(map, map_data);
}
