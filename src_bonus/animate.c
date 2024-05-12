/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 22:55:28 by lsampiet          #+#    #+#             */
/*   Updated: 2024/05/12 01:40:29 by lsampiet         ###   ########.fr       */
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
		if (counter == 8)
		{
			counter = 0;
			animate_player(game);
		}
	}
}

void	init_anim_images(t_game *game)
{
	game->img.player_00 = create_img(game->mlx, "./assets/player/p-idle-R-00.png");
	game->img.player_01 = create_img(game->mlx, "./assets/player/p-idle-R-01.png");
	game->img.player_02 = create_img(game->mlx, "./assets/player/p-idle-R-02.png");
	game->img.player_03 = create_img(game->mlx, "./assets/player/p-idle-R-03.png");
	if ((!(game->img.player_00)) || (!(game->img.player_01) 
		|| (!(game->img.player_02)) || (!(game->img.player_03))))
		ft_error(ERROR_IMG_B, NULL);
}

void	anim_images_off(t_game *game)
{
	game->img.player_00->enabled = 0;
	game->img.player_01->enabled = 0;
	game->img.player_02->enabled = 0;
	game->img.player_03->enabled = 0;
}

void	animate_player(t_game *game)
{
	static int	frame;

	anim_images_off(game);
	if (frame == 0)
		game->img.player_00->enabled = 1;
	if (frame == 1)
		game->img.player_01->enabled = 1;
	if (frame == 2)
		game->img.player_02->enabled = 1;
	if (frame == 3)
		game->img.player_03->enabled = 1;
	frame++;
	if (frame > 3)
		frame = 0;
}
