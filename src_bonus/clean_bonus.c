/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 19:04:42 by lsampiet          #+#    #+#             */
/*   Updated: 2024/05/12 06:49:25 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	ft_error(char *str, char **map)
{
	if (map)
		free_map(map);
	ft_printf("%s", str);
	exit(EXIT_FAILURE);
}

void	free_game(t_game *game)
{
	free_map(game->map);
	mlx_delete_texture(game->icon);
	delete_images(game);
	mlx_terminate(game->mlx);
	exit(EXIT_SUCCESS);
}
