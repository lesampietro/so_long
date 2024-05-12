/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 02:52:15 by lsampiet          #+#    #+#             */
/*   Updated: 2024/05/12 03:00:38 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	update_frame_pos(t_game *game, int x, int y)
{
	game->img.p_r0->instances[0].x = x;
	game->img.p_r0->instances[0].y = y;
	game->img.p_r1->instances[0].x = x;
	game->img.p_r1->instances[0].y = y;
	game->img.p_r2->instances[0].x = x;
	game->img.p_r2->instances[0].y = y;
	game->img.p_r3->instances[0].x = x;
	game->img.p_r3->instances[0].y = y;
	game->img.p_l0->instances[0].x = x;
	game->img.p_l0->instances[0].y = y;
	game->img.p_l1->instances[0].x = x;
	game->img.p_l1->instances[0].y = y;
	game->img.p_l2->instances[0].x = x;
	game->img.p_l2->instances[0].y = y;
	game->img.p_l3->instances[0].x = x;
	game->img.p_l3->instances[0].y = y;
}

void	player_moves(t_game *game, int movement)
{
	if (movement == TOP)
	{
		update_frame_pos(game, game->img.p_r0->instances[0].x,
			game->img.p_r0->instances[0].y - 64);
		game->player_pos.y--;
	}
	if (movement == LEFT)
	{
		update_frame_pos(game, game->img.p_r0->instances[0].x - 64,
			game->img.p_r0->instances[0].y);
		game->player_pos.x--;
	}
	if (movement == RIGHT)
	{
		update_frame_pos(game, game->img.p_r0->instances[0].x + 64,
			game->img.p_r0->instances[0].y);
		game->player_pos.x++;
	}
	if (movement == BOTTOM)
	{
		update_frame_pos(game, game->img.p_r0->instances[0].x,
			game->img.p_r0->instances[0].y + 64);
		game->player_pos.y++;
	}
	counter(game);
}
