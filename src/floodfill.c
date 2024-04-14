/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 17:40:08 by lsampiet          #+#    #+#             */
/*   Updated: 2024/04/14 19:53:02 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"



void	get_player_pos(char **map, t_map *map_data)
{
	int i;
	int j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				map_data->position.x = i;
				map_data->position.y = j;
			}
			j++;
		}
		i++;
	}
	ft_printf("%i\n%i", map_data->position.x, map_data->position.y);
}

void	floodfill(char **map, t_map *map_data)
{
	get_player_pos(map, map_data);
	//checar as posições em volta do player
	//checar se em todas as linhas tem pelo menos um "0"
}