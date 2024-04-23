/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 17:47:30 by lsampiet          #+#    #+#             */
/*   Updated: 2024/04/22 21:54:52 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void error(void)
{
	exit(EXIT_FAILURE);
}

// void	player_move_validation(t_game *game, t_pos *player_pos)
// {
// 	game->player_pos->x = (game->image->player_img->instances[0].x / 64);
// 	game->player_pos->y = (game->image->player_img->instances[0].y / 64);
	// if (keydata.action == MLX_PRESS)
	// 	ft_printf("x=%i\ny=%i\n\n", game->image->player_img->instances[0].x, game->image->player_img->instances[0].y);
// }

void	player_moves(mlx_key_data_t keydata, void *param)
{
	t_game *game;

	game = (t_game *)param;
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		game->image->player_img->instances[0].y -= 64;
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		game->image->player_img->instances[0].x -= 64;
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		game->image->player_img->instances[0].y += 64;
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		game->image->player_img->instances[0].x += 64;
}

void put_collects_n_exit(t_game *game)
{
	int line;
	int col;

	line = 0;
	while (game->map[line])
	{
		col = 0;
		while (game->map[line][col])
		{
			if (game->map[line][col] == 'C')
			{
				if (mlx_image_to_window(game->mlx, game->image->collects_img, col * TILE, line * TILE) < 0)
					error();
			}
			col++;
		}
		line++;
	}
}

void	put_player(t_game *game)
{
	int line;
	int col;

	line = 0;
	while (game->map[line])
	{
		col = 0;
		while (game->map[line][col])
		{
			if (game->map[line][col] == 'P')
			{
				if (mlx_image_to_window(game->mlx, game->image->player_img, col * TILE, line * TILE) < 0)
					error();
			}
			else if (game->map[line][col] == 'E')
			{
				if (mlx_image_to_window(game->mlx, game->image->exit_img, col * TILE, line * TILE) < 0)
					error();
			}
			col++;
		}
		line++;
	}
}

void	put_floor_n_walls(t_game *game)
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
	mlx_delete_image(game->mlx, game->image->player_img);
	mlx_delete_image(game->mlx, game->image->collects_img);
	mlx_delete_image(game->mlx, game->image->exit_img);
}

void	delete_textures(t_game *game)
{
	mlx_delete_texture(game->texture->floor);
	mlx_delete_texture(game->texture->wall);
	mlx_delete_texture(game->texture->player);
	mlx_delete_texture(game->texture->collects);
	mlx_delete_texture(game->texture->exit);
}

void	init_tile_images(t_game *game)
{
	game->image = malloc(sizeof(t_img));
	game->image->floor_img = mlx_texture_to_image(game->mlx, game->texture->floor);
	game->image->wall_img = mlx_texture_to_image(game->mlx, game->texture->wall);
	game->image->player_img = mlx_texture_to_image(game->mlx, game->texture->player);
	game->image->collects_img = mlx_texture_to_image(game->mlx, game->texture->collects);
	game->image->exit_img = mlx_texture_to_image(game->mlx, game->texture->exit);
	if ((!(game->image->floor_img)) || (!(game->image->wall_img)) || (!(game->image->player_img)) 
	|| (!(game->image->collects_img)) || (!(game->image->exit_img)))
		error();
}

void	init_tile_textures(t_game *game)
{
	game->texture = malloc(sizeof(t_img));
	game->texture->floor = mlx_load_png("./assets/textures/floor-64px.png");
	game->texture->wall = mlx_load_png("./assets/textures/wall-64px.png");
	game->texture->player = mlx_load_png("./assets/player/pagu-01.png");
	game->texture->collects = mlx_load_png("./assets/textures/collect-64px.png");
	game->texture->exit = mlx_load_png("./assets/textures/exit-64px.png");
	if ((!(game->texture->floor)) || (!(game->texture->wall)) || (!(game->image->player)) 
	|| (!(game->image->collects))|| (!(game->image->collects))|| (!(game->image->exit)))
		error();
	init_tile_images(game);
	delete_textures(game);
}

void	init_game_image(t_game *game)
{
	init_tile_textures(game);
	put_floor_n_walls(game);
	put_collects_n_exit(game);
	put_player(game);
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
	init_game_image(game);
	mlx_key_hook(game->mlx, &player_moves, game);
	mlx_loop(game->mlx);
	delete_images(game);
	mlx_terminate(game->mlx);
	return (EXIT_SUCCESS);
}
