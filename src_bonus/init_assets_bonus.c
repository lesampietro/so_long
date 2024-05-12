/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_assets_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 19:47:56 by lsampiet          #+#    #+#             */
/*   Updated: 2024/05/11 21:05:35 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

mlx_image_t	*create_img(mlx_t *mlx, char *img_path)
{
	mlx_texture_t	*texture;
	mlx_image_t		*img;

	texture = mlx_load_png(img_path);
	if (!texture)
		ft_error(ERROR_TEXTURE_B, NULL);
	img = mlx_texture_to_image(mlx, texture);
	if (!img)
		ft_error(ERROR_IMG_B, NULL);
	mlx_delete_texture(texture);
	return (img);
}

void	display_img(t_game *game)
{
	game->img.floor = create_img(game->mlx, "./assets/tiles/floor.png");
	game->img.wall = create_img(game->mlx, "./assets/tiles/wall.png");
	game->img.collects = create_img(game->mlx, "./assets/tiles/collect.png");
	game->img.exit = create_img(game->mlx, "./assets/tiles/exit.png");
	init_anim_images(game);
	if ((!(game->img.floor)) || (!(game->img.wall)
		|| (!(game->img.collects)) || (!(game->img.exit))))
		ft_error(ERROR_IMG_B, NULL);
}

void	delete_images(t_game *game)
{
	mlx_delete_image(game->mlx, game->img.floor);
	mlx_delete_image(game->mlx, game->img.wall);
	mlx_delete_image(game->mlx, game->img.collects);
	mlx_delete_image(game->mlx, game->img.exit);
	mlx_delete_image(game->mlx, game->img.player_00);
	mlx_delete_image(game->mlx, game->img.player_01);
	mlx_delete_image(game->mlx, game->img.player_02);
	mlx_delete_image(game->mlx, game->img.player_03);
}
