/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 17:47:30 by lsampiet          #+#    #+#             */
/*   Updated: 2024/04/21 21:51:43 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void error(void)
{
	exit(EXIT_FAILURE);
}

void	put_floor(t_game *game)
{
	int line;
	int col;

	line = 0;
	while (game->map[line])
	{
		col = 0;
		while (game->map[line][col])
		{
			if (ft_strchr("0PCE", game->map[line][col]))
			{
				if (mlx_image_to_window(game->mlx, game->image->floor_img, col * TILE, line * TILE) < 0)
					error();
			}
			else if (game->map[line][col] == '1')
			{
				if (mlx_image_to_window(game->mlx, game->image->wall_img, col * TILE, line * TILE) < 0)
					error();
			}
			col++;
		}
		line++;
	}
}

void	delete_images(t_game *game)
{
	mlx_delete_image(game->mlx, game->image->floor_img);
	mlx_delete_image(game->mlx, game->image->wall_img);
}

void	delete_textures(t_game *game)
{
	mlx_delete_texture(game->texture->floor);
	mlx_delete_texture(game->texture->wall);
}

void	init_tile_images(t_game *game)
{
	game->image = malloc(sizeof(t_img));
	game->image->floor_img = mlx_texture_to_image(game->mlx, game->texture->floor);
	game->image->wall_img = mlx_texture_to_image(game->mlx, game->texture->wall);
	if ((!(game->image->floor_img)) || (!(game->image->wall_img)))
		error();
}

void	init_tile_textures(t_game *game)
{
	game->texture = malloc(sizeof(t_img));
	game->texture->floor = mlx_load_png("./assets/textures/floor-64px.png");
	game->texture->wall = mlx_load_png("./assets/textures/wall-64px.png");
	if ((!(game->texture->floor)) || (!(game->texture->wall)))
		error();
	init_tile_images(game);
	delete_textures(game);
}

void	init_map_image(t_game *game)
{
	init_tile_textures(game);
	put_floor(game);
}

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

int32_t	init_game(char *argv, t_game *game)
{
	game->map = read_map(argv);
	count_map_size(game);
	game->mlx = mlx_init((TILE * game->col), (TILE * game->lin), "Pagu", false);
	if (!game->mlx)
		error();
	init_map_image(game);
	mlx_loop(game->mlx);
	ft_printf("%s", "OK");
	delete_images(game);
	mlx_terminate(game->mlx);
	return (EXIT_SUCCESS);
}