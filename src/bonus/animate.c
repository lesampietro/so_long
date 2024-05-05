/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 22:55:28 by lsampiet          #+#    #+#             */
/*   Updated: 2024/05/05 19:46:20 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

void	timer(void *param)
{
	int32_t	time;
	t_game	*game;

	time = (int)(mlx_get_time() * 10);
	game = (t_game *)param;
	animate_player(game, time);
}

void	init_anim_images(t_game *game)
{
	game->image = malloc(sizeof(t_img));
	game->anim_img->player_01 = mlx_texture_to_image(game->mlx, game->anim_texture->player_01);
	game->anim_img->player_02 = mlx_texture_to_image(game->mlx, game->anim_texture->player_02);
	if ((!(game->anim_img->player_01)) || (!(game->anim_img->player_02)))
		ft_error(ERROR_ASSET_LOAD, NULL);
}

void	init_anim_textures(t_game *game)
{
	game->texture = malloc(sizeof(t_img));
	game->anim_texture->player_01 = mlx_load_png("./assets/player/pagu-idle-01-64px.png");
	game->anim_texture->player_02 = mlx_load_png("./assets/player/pagu-idle-01-64px.png");
	if ((!(game->anim_texture->player_01)) || (!(game->anim_texture->player_02)))
		ft_error(ERROR_ASSET_LOAD, NULL);
	init_anim_images(game);
	delete_textures(game);
}

void	animate_player(t_game *game, int32_t time)
{
	if ((time % 3 == 0))
	{
		game->player_data[x]->img->enabled = 0;
		game->player_data[y]->img->enabled = 1;
	}
	if ((time % 6 == 0))
	{
		game->player_data[x]->img->enabled = 0;
		game->player_data[y]->img->enabled = 1;
	}
}
