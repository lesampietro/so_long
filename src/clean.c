/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 19:04:42 by lsampiet          #+#    #+#             */
/*   Updated: 2024/05/04 20:01:04 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void free_map(char **map)
{
	int i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void ft_error(char *str, char **map)
{
	if (map)
		free_map(map);
	ft_printf("%s", str);
	exit(EXIT_FAILURE);
}

void	free_game(t_game *game)
{
	
}