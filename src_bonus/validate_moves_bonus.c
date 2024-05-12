/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_moves_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 19:46:54 by lsampiet          #+#    #+#             */
/*   Updated: 2024/05/11 21:38:35 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	validate_exit(mlx_key_data_t keydata, t_game *game)
{
	if (game->occ.defo_collects == 0)
	{
		game->img.exit->enabled = true;
		if (game->img.exit->instances[0].x
			== game->img.player_00->instances[0].x
			&& game->img.exit->instances[0].y
			== game->img.player_00->instances[0].y)
			game->end_game = 0;
	}
	if (keydata.action == MLX_RELEASE && game->end_game == 0)
		free_game(game);
}

void	update_frame_pos(t_game *game, int x, int y)
{
	game->img.player_00->instances[0].x = x;
	game->img.player_00->instances[0].y = y;
	game->img.player_01->instances[0].x = x;
	game->img.player_01->instances[0].y = y;
	game->img.player_02->instances[0].x = x;
	game->img.player_02->instances[0].y = y;
	game->img.player_03->instances[0].x = x;
	game->img.player_03->instances[0].y = y;
}

void	player_moves(t_game *game, int movement)
{
	if (movement == TOP)
	{
		update_frame_pos(game, game->img.player_00->instances[0].x,
			game->img.player_00->instances[0].y - 64);
		game->player_pos.y--;
	}
	if (movement == LEFT)
	{
		update_frame_pos(game, game->img.player_00->instances[0].x - 64,
						 game->img.player_00->instances[0].y);
		game->player_pos.x--;
	}
	if (movement == RIGHT)
	{
		update_frame_pos(game, game->img.player_00->instances[0].x + 64,
						 game->img.player_00->instances[0].y);
		game->player_pos.x++;
	}
	if (movement == BOTTOM)
	{
		update_frame_pos(game, game->img.player_00->instances[0].x,
						 game->img.player_00->instances[0].y + 64);
		game->player_pos.y++;
	}
	counter(game);
}

void	validate_collects(t_game *game)
{
	int	i;

	i = 0;
	if (game->map[game->player_pos.y][game->player_pos.x]
		== 'C' && game->occ.collects > 0)
	{
		game->map[game->player_pos.y][game->player_pos.x] = '0';
		while (i < game->occ.collects)
		{
			if (game->img.collects->instances[i].x
				== game->img.player_00->instances[0].x
				&& game->img.collects->instances[i].y
				== game->img.player_00->instances[0].y)
				game->img.collects->instances[i].enabled = false;
			i++;
		}
		game->occ.defo_collects--;
	}
}

void	validate_moves(t_game *game, int movement)
{
	if (movement == TOP)
		if (game->map[game->player_pos.y - 1][game->player_pos.x] != '1')
			player_moves(game, TOP);
	if (movement == LEFT)
		if (game->map[game->player_pos.y][game->player_pos.x - 1] != '1')
			player_moves(game, LEFT);
	if (movement == RIGHT)
		if (game->map[game->player_pos.y][game->player_pos.x + 1] != '1')
			player_moves(game, RIGHT);
	if (movement == BOTTOM)
		if (game->map[game->player_pos.y + 1][game->player_pos.x] != '1')
			player_moves(game, BOTTOM);
	validate_collects(game);
}

void	init_move(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
	if (((keydata.key == MLX_KEY_W) || (keydata.key == MLX_KEY_UP))
		&& keydata.action == MLX_PRESS)
		validate_moves(game, TOP);
	if (((keydata.key == MLX_KEY_A) || (keydata.key == MLX_KEY_LEFT))
		&& keydata.action == MLX_PRESS)
		validate_moves(game, LEFT);
	if (((keydata.key == MLX_KEY_S) || (keydata.key == MLX_KEY_DOWN))
		&& keydata.action == MLX_PRESS)
		validate_moves(game, BOTTOM);
	if (((keydata.key == MLX_KEY_D) || (keydata.key == MLX_KEY_RIGHT))
		&& keydata.action == MLX_PRESS)
		validate_moves(game, RIGHT);
	validate_exit (keydata, game);
}
