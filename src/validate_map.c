/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 17:40:08 by lsampiet          #+#    #+#             */
/*   Updated: 2024/04/13 18:18:51 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
void	newline_off(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while(map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == '\n')
				map[i][j] = '\0';
			j++;
		}
		i++;
		
	}
}

void check_map_chars(char **map, t_map *map_data)
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
				exit(ft_printf("Map with invalid characters\n"));
			j++;
		}
		i++;
	}
	map_data->lines = i;
	map_data->columns = j;
}

void check_map_shape(char **map, t_map *map_data)
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
		{
			ft_printf("%i\n%i", i, j);
			exit(ft_printf("Map is not rectangular\n"));
		}
		i++;
	}
}

void check_col_lin_size(char **map, t_map *map_data)
{
	int i;

	i = 0;
	while (map[i])
		i++;
	if ((i < 5) && (map_data->columns < 4))
		exit(ft_printf("Map is invalid\n"));
	else if ((map_data->columns < 5) && (i < 4))
		exit(ft_printf("Map is invalid\n"));
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
//fazer função para contar numero de linhas e de colunas, e depois puxar como parametros
void	is_valid_map(char **map)
{
	t_map temp;
	
	newline_off(map);
	check_map_chars(map, &temp);
	check_map_shape(map, &temp);
	check_col_lin_size(map, &temp);
	check_map_walls(map, &temp);
	//validar se há a ocorrência de pelo menos 1 caracter de cada mandatorio -> fazer com struct
}