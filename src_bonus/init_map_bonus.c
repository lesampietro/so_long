/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 19:40:59 by lsampiet          #+#    #+#             */
/*   Updated: 2024/05/11 21:30:57 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	put_player_frames(t_game *game, int col, int line)
{
	if (mlx_image_to_window(game->mlx, game->img.player_00, col, line) < 0)
		ft_error(ERROR_ASSET_DISPLAY_B, NULL);
	if (mlx_image_to_window(game->mlx, game->img.player_01, col, line) < 0)
		ft_error(ERROR_ASSET_DISPLAY_B, NULL);
	if (mlx_image_to_window(game->mlx, game->img.player_02, col, line) < 0)
		ft_error(ERROR_ASSET_DISPLAY_B, NULL);
	if (mlx_image_to_window(game->mlx, game->img.player_03, col, line) < 0)
		ft_error(ERROR_ASSET_DISPLAY_B, NULL);
}

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
				put_player_frames(game, col * TILE, line * TILE);
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
					ft_error(ERROR_MAP_DISPLAY_B, NULL);
			}
			else if (game->map[line][col] == 'E')
			{
				if (mlx_image_to_window(game->mlx,
						game->img.exit, col * TILE, line * TILE) < 0)
					ft_error(ERROR_MAP_DISPLAY_B, NULL);
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
					ft_error(ERROR_MAP_DISPLAY_B, NULL);
			}
			else if (game->map[line][col] == '1')
			{
				if (mlx_image_to_window(game->mlx,
						game->img.wall, col * TILE, line * TILE) < 0)
					ft_error(ERROR_MAP_DISPLAY_B, NULL);
			}
			col++;
		}
		line++;
	}
}
