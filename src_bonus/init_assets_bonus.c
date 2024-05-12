/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_assets_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 19:47:56 by lsampiet          #+#    #+#             */
/*   Updated: 2024/05/12 06:49:59 by lsampiet         ###   ########.fr       */
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
	game->img.ghost = create_img(game->mlx, "./assets/enemy/g_down.png");
	init_anim_images(game);
	if ((!(game->img.floor)) || (!(game->img.wall)
			|| (!(game->img.collects)) || (!(game->img.exit))
			|| (!(game->img.ghost))))
		ft_error(ERROR_IMG_B, NULL);
}

void	init_anim_images(t_game *game)
{
	game->img.p_r0 = create_img(game->mlx, "./assets/player/p-idle-R-00.png");
	game->img.p_r1 = create_img(game->mlx, "./assets/player/p-idle-R-01.png");
	game->img.p_r2 = create_img(game->mlx, "./assets/player/p-idle-R-02.png");
	game->img.p_r3 = create_img(game->mlx, "./assets/player/p-idle-R-03.png");
	game->img.p_l0 = create_img(game->mlx, "./assets/player/p-idle-L-00.png");
	game->img.p_l1 = create_img(game->mlx, "./assets/player/p-idle-L-01.png");
	game->img.p_l2 = create_img(game->mlx, "./assets/player/p-idle-L-02.png");
	game->img.p_l3 = create_img(game->mlx, "./assets/player/p-idle-L-03.png");
	if ((!(game->img.p_r0)) || (!(game->img.p_r1)
			|| (!(game->img.p_r2)) || (!(game->img.p_r3))
			|| (!(game->img.p_r0)) || (!(game->img.p_r1)
				|| (!(game->img.p_r2)) || (!(game->img.p_r3)))))
		ft_error(ERROR_IMG_B, NULL);
}

void	delete_images(t_game *game)
{
	mlx_delete_image(game->mlx, game->img.floor);
	mlx_delete_image(game->mlx, game->img.wall);
	mlx_delete_image(game->mlx, game->img.collects);
	mlx_delete_image(game->mlx, game->img.exit);
	mlx_delete_image(game->mlx, game->img.ghost);
	mlx_delete_image(game->mlx, game->img.p_r0);
	mlx_delete_image(game->mlx, game->img.p_r1);
	mlx_delete_image(game->mlx, game->img.p_r2);
	mlx_delete_image(game->mlx, game->img.p_r3);
	mlx_delete_image(game->mlx, game->img.p_l0);
	mlx_delete_image(game->mlx, game->img.p_l1);
	mlx_delete_image(game->mlx, game->img.p_l2);
	mlx_delete_image(game->mlx, game->img.p_l3);
	mlx_delete_image(game->mlx, game->counter);
}
