/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 19:40:59 by lsampiet          #+#    #+#             */
/*   Updated: 2024/05/05 19:24:22 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	put_player(t_game *game)
{
	int	line;
	int	col;

	line = 0;
	while (game->map[line])
	{
		col = 0;
		while (game->map[line][col])
		{
			if (game->map[line][col] == 'P')
			{
				if (mlx_image_to_window(game->mlx,
						game->img.player, col * TILE, line * TILE) < 0)
					ft_error(ERROR_ASSET_DISPLAY, NULL);
			}
			col++;
		}
		line++;
	}
}

void	put_collects_n_exit(t_game *game)
{
	int	line;
	int	col;

	line = 0;
	while (game->map[line])
	{
		col = 0;
		while (game->map[line][col])
		{
			if (game->map[line][col] == 'C')
			{
				if (mlx_image_to_window(game->mlx,
						game->img.collects, col * TILE, line * TILE) < 0)
					ft_error(ERROR_MAP_DISPLAY, NULL);
			}
			else if (game->map[line][col] == 'E')
			{
				if (mlx_image_to_window(game->mlx,
						game->img.exit, col * TILE, line * TILE) < 0)
					ft_error(ERROR_MAP_DISPLAY, NULL);
			}
			col++;
		}
		line++;
	}
}

void	put_floor_n_walls(t_game *game)
{
	int	line;
	int	col;

	line = 0;
	while (game->map[line])
	{
		col = 0;
		while (game->map[line][col])
		{
			if (ft_strchr("0PCE", game->map[line][col]))
			{
				if (mlx_image_to_window(game->mlx,
						game->img.floor, col * TILE, line * TILE) < 0)
					ft_error(ERROR_MAP_DISPLAY, NULL);
			}
			else if (game->map[line][col] == '1')
			{
				if (mlx_image_to_window(game->mlx,
						game->img.wall, col * TILE, line * TILE) < 0)
					ft_error(ERROR_MAP_DISPLAY, NULL);
			}
			col++;
		}
		line++;
	}
}
