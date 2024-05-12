/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 22:55:28 by lsampiet          #+#    #+#             */
/*   Updated: 2024/05/12 04:20:40 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	timer(void *param)
{
	int32_t		time;
	t_game		*game;
	static int	counter;

	time = (int)(mlx_get_time() * 10);
	game = (t_game *)param;
	if (time % 2 == 0)
	{
		counter++;
		if (counter == 6)
		{
			counter = 0;
			check_side(game);
		}
	}
}

void	check_side(t_game *game)
{
	if (game->player_side == RIGHT)
		animate_player_right(game);
	if (game->player_side == LEFT)
		animate_player_left(game);
}

void	anim_images_off(t_game *game)
{
	game->img.p_r0->enabled = 0;
	game->img.p_r1->enabled = 0;
	game->img.p_r2->enabled = 0;
	game->img.p_r3->enabled = 0;
	game->img.p_l0->enabled = 0;
	game->img.p_l1->enabled = 0;
	game->img.p_l2->enabled = 0;
	game->img.p_l3->enabled = 0;
}

void	animate_player_right(t_game *game)
{
	static int	frame;

	anim_images_off(game);
	if (frame == 0)
		game->img.p_r0->enabled = 1;
	if (frame == 1)
		game->img.p_r1->enabled = 1;
	if (frame == 2)
		game->img.p_r2->enabled = 1;
	if (frame == 3)
		game->img.p_r3->enabled = 1;
	frame++;
	if (frame > 3)
		frame = 0;
}

void	animate_player_left(t_game *game)
{
	static int	frame;

	anim_images_off(game);
	if (frame == 0)
		game->img.p_l0->enabled = 1;
	if (frame == 1)
		game->img.p_l1->enabled = 1;
	if (frame == 2)
		game->img.p_l2->enabled = 1;
	if (frame == 3)
		game->img.p_l3->enabled = 1;
	frame++;
	if (frame > 3)
		frame = 0;
}
