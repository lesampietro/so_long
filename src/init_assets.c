/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 19:47:56 by lsampiet          #+#    #+#             */
/*   Updated: 2024/05/04 19:56:51 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void init_tile_images(t_game *game)
{
	game->image = malloc(sizeof(t_img));
	game->image->floor_img = mlx_texture_to_image(game->mlx, game->texture->floor);
	game->image->wall_img = mlx_texture_to_image(game->mlx, game->texture->wall);
	game->image->collects_img = mlx_texture_to_image(game->mlx, game->texture->collects);
	game->image->exit_img = mlx_texture_to_image(game->mlx, game->texture->exit);
	game->image->player_img = mlx_texture_to_image(game->mlx, game->texture->player);
	if ((!(game->image->floor_img)) || (!(game->image->wall_img)) || (!(game->image->player_img)) || (!(game->image->collects_img)) || (!(game->image->exit_img)))
		ft_error("Error.\nImage could not be loaded", NULL);
}

void init_tile_textures(t_game *game)
{
	game->texture = malloc(sizeof(t_img));
	game->texture->floor = mlx_load_png("./assets/textures/floor-64px.png");
	game->texture->wall = mlx_load_png("./assets/textures/wall-64px.png");
	game->texture->collects = mlx_load_png("./assets/textures/collect-64px.png");
	game->texture->exit = mlx_load_png("./assets/textures/exit-64px.png");
	game->texture->player = mlx_load_png("./assets/player/pagu-idle-03-64px.png");
	if ((!(game->texture->floor)) || (!(game->texture->wall)) || (!(game->texture->player)) || (!(game->texture->collects)) || (!(game->texture->collects)) || (!(game->texture->exit)))
		ft_error("Error.\nTextures could not be loaded", NULL);
	init_tile_images(game);
	delete_textures(game);
}

void delete_images(t_game *game)
{
	mlx_delete_image(game->mlx, game->image->floor_img);
	mlx_delete_image(game->mlx, game->image->wall_img);
	mlx_delete_image(game->mlx, game->image->collects_img);
	mlx_delete_image(game->mlx, game->image->exit_img);
	mlx_delete_image(game->mlx, game->image->player_img);
	free(game->image);
}

void delete_textures(t_game *game)
{
	mlx_delete_texture(game->texture->floor);
	mlx_delete_texture(game->texture->wall);
	mlx_delete_texture(game->texture->collects);
	mlx_delete_texture(game->texture->exit);
	mlx_delete_texture(game->texture->player);
	free(game->texture);
}