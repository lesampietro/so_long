/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 17:47:30 by lsampiet          #+#    #+#             */
/*   Updated: 2024/04/21 19:33:29 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

//valor de width e height mocados, substituir por variável (multiplicar tamanho dos bloquinhos por tamanho do mapa)

static void error(void)
{
	exit(EXIT_FAILURE);
}
// void	init_tile_images(t_game game)
// {
// 	mlx_image_t *img = mlx_texture_to_image(mlx, texture);
// 	if (!img)
// 		error();
// }

// void	init_tile_textures(t_game game)
// {
// 	t_texture *tiles;

// 	mlx_texture_t *texture = mlx_load_png("./assets/textures/grass-64px.png");
// 	if (!texture)
// 		error();
// 	(*data)->tiles = (t_texture *)malloc(sizeof(t_texture));
// 	tiles = (*data)->tiles;
// 	tiles->floor = mlx_load_png("assets/tiles/floor/0.png");
// 	tiles->wall = mlx_load_png("assets/tiles/wall/0.png");
// 	tiles->exit[0] = mlx_load_png("assets/tiles/other/33.png");
// 	tiles->exit[1] = mlx_load_png("assets/tiles/other/34.png");
// 	tiles->exit[2] = NULL;
// 	load_tile_images(data);
// 	delete_tile_textures(data);
// }

// void	init_map_image(t_game game)
// {
// 	init_tile_textures(t_data **data);
// 	init_tile_images(t_data *data);
// 	// Display the image
// 	if (mlx_image_to_window(mlx, img, 0, 0) < 0)
// 		error();
// 	mlx_loop(mlx);
// 	mlx_delete_image(mlx, img);
// 	mlx_delete_texture(game->texture);
// 	mlx_terminate(mlx);
// 	return (EXIT_SUCCESS);
// }

void	count_map_size(t_game *game)
{
	int l;
	int c;

	l = 0;
	game->lin = 0;
	game->col = 0;
	while (game->map[l])
	{
		c = 0;
		while (game->map[l][c])
			c++;
		l++;
	}
	game->lin = l;
	game->col = c;
}

int32_t init_game(char *argv, t_game *game)
{
	mlx_t	*mlx;

	game->map = read_map(argv);
	count_map_size(game);
	mlx = mlx_init((TILE * game->lin), (TILE * game->col), "Pagu", false);
	if (!mlx)
		error();
	mlx_texture_t *texture = mlx_load_png("./assets/textures/grass-64px.png");
	if (!texture)
		error();
	mlx_image_t *img = mlx_texture_to_image(mlx, texture);
	if (!img)
		error();
	if (mlx_image_to_window(mlx, img, 0, 0) < 0)
		error();
	mlx_loop(mlx);
	mlx_delete_image(mlx, img);
	mlx_delete_texture(texture);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
	// init_map_image(game);
}