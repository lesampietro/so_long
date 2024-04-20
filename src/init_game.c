/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 17:47:30 by lsampiet          #+#    #+#             */
/*   Updated: 2024/04/20 19:08:03 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// void	init_game(char *argv)
// {
// 	t_game	game;
// 	mlx_t	*mlx;

// 	game.map = read_map(argv);
// 	//valor de width e height mocados, substituir por variável (multiplicar tamanho dos bloquinhos por tamanho do mapa)

static void error(void)
{
	exit(EXIT_FAILURE);
}

void	count_map_size(char **map, t_game *game)
{
	int l;
	int c;

	l = 0;
	game->lin = 0;
	game->col = 0;
	while (map[l])
	{
		c = 0;
		while (map[l][c])
			c++;
		l++;
	}
	game->lin = l;
	game->col = c;
}

int32_t	init_game(char **map, t_game *game)
{
	mlx_t *mlx;

	count_map_size(map, game);
	mlx = mlx_init((TILE * game->lin), (TILE * game->col), "Pagu", false);
	// Start mlx
	if (!mlx)
		error();

	// Try to load the file
	mlx_texture_t *texture = mlx_load_png("./assets/textures/grass-64px.png");
	if (!texture)
		error();

	// Convert texture to a displayable image
	mlx_image_t *img = mlx_texture_to_image(mlx, texture);
	if (!img)
		error();

	// Display the image
	if (mlx_image_to_window(mlx, img, 0, 0) < 0)
		error();
	mlx_loop(mlx);

	mlx_delete_image(mlx, img);
	mlx_delete_texture(texture);

	// Optional, terminate will clean up any leftover images (not textures!)
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}