/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 17:47:30 by lsampiet          #+#    #+#             */
/*   Updated: 2024/04/28 20:41:52 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void error(void)
{
	exit(EXIT_FAILURE);
}

// fazer o contador de passos dados com printf
// animar o gato (muito importante!!!)
//void	mlx_close_hook(mlx_t * mlx, mlx_closefunc func, void *param);

void counter(t_game *game)
{
	game->steps++;	
	ft_printf("Steps: %i\n", game->steps);
}

void	validate_exit(mlx_key_data_t keydata, t_game *game)
{
	if(game->occ.defo_collects == 0)
	{
		game->image->exit_img->enabled = true;
		if (game->image->exit_img->instances[0].x == game->image->player_img->instances[0].x 
		&& game->image->exit_img->instances[0].y == game->image->player_img->instances[0].y)
			game->end_game = 0;
	}
	if (keydata.action == MLX_RELEASE && game->end_game == 0)
		exit(EXIT_SUCCESS);
}

void	player_moves(t_game *game, int movement)
{
	if (movement == TOP)
	{
		game->player_pos.y--;
		game->image->player_img->instances[0].y -= 64;
	}
	if (movement == LEFT)
	{
		game->player_pos.x--;
		game->image->player_img->instances[0].x -= 64;
	}
	if (movement == RIGHT)
	{
		game->player_pos.x++;
		game->image->player_img->instances[0].x += 64;
	}
	if (movement == BOTTOM)
	{
		game->player_pos.y++;
		game->image->player_img->instances[0].y += 64;
	}
	counter(game);
}
void	validate_collects(t_game *game)
{
	int	i;

	i = 0;
	if (game->map[game->player_pos.y][game->player_pos.x] == 'C' && game->occ.collects > 0)
	{
		game->map[game->player_pos.y][game->player_pos.x] = '0';
		while(i < game->occ.collects)
		{
			if (game->image->collects_img->instances[i].x == game->image->player_img->instances[0].x 
			&& game->image->collects_img->instances[i].y == game->image->player_img->instances[0].y)
				game->image->collects_img->instances[i].enabled = false;
			i++;
		}
		game->occ.defo_collects--;
	}
}

void	validate_moves(t_game *game, int movement)
{
	if(movement == TOP)
		if(game->map[game->player_pos.y - 1][game->player_pos.x] != '1')
		{
			player_moves(game, TOP);
			validate_collects(game);
		}
	if (movement == LEFT)
		if (game->map[game->player_pos.y][game->player_pos.x - 1] != '1')
		{
			player_moves(game, LEFT);
			validate_collects(game);
		}
	if(movement == RIGHT)
		if (game->map[game->player_pos.y][game->player_pos.x + 1] != '1')
		{
			player_moves(game, RIGHT);
			validate_collects(game);
		}
	if (movement == BOTTOM)
		if (game->map[game->player_pos.y + 1][game->player_pos.x] != '1')
		{	
			player_moves(game, BOTTOM);
			validate_collects(game);
		}
}

void	init_move(mlx_key_data_t keydata, void *param)
{
	t_game *game;

	game = (t_game *)param;
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		validate_moves(game, TOP);
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		validate_moves(game, LEFT);
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		validate_moves(game, BOTTOM);
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		validate_moves(game, RIGHT);
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		exit(EXIT_SUCCESS);
	validate_exit(keydata, game);
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
			col++;
		}
		line++;
	}
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
			else if (game->map[line][col] == 'E')
			{
				if (mlx_image_to_window(game->mlx, game->image->exit_img, col * TILE, line * TILE) < 0)
					error();
			}
			col++;
		}
		line++;
	}
	game->image->exit_img->enabled = false;
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
	mlx_delete_image(game->mlx, game->image->collects_img);
	mlx_delete_image(game->mlx, game->image->exit_img);
	mlx_delete_image(game->mlx, game->image->player_img);
	free(game->image);
}

void	delete_textures(t_game *game)
{
	mlx_delete_texture(game->texture->floor);
	mlx_delete_texture(game->texture->wall);
	mlx_delete_texture(game->texture->collects);
	mlx_delete_texture(game->texture->exit);
	mlx_delete_texture(game->texture->player);
	free(game->texture);
}

void	init_tile_images(t_game *game)
{
	game->image = malloc(sizeof(t_img));
	game->image->floor_img = mlx_texture_to_image(game->mlx, game->texture->floor);
	game->image->wall_img = mlx_texture_to_image(game->mlx, game->texture->wall);
	game->image->collects_img = mlx_texture_to_image(game->mlx, game->texture->collects);
	game->image->exit_img = mlx_texture_to_image(game->mlx, game->texture->exit);
	game->image->player_img = mlx_texture_to_image(game->mlx, game->texture->player);
	if ((!(game->image->floor_img)) || (!(game->image->wall_img)) || (!(game->image->player_img)) 
	|| (!(game->image->collects_img)) || (!(game->image->exit_img)))
		error();
}

void	init_tile_textures(t_game *game)
{
	game->texture = malloc(sizeof(t_img));
	game->texture->floor = mlx_load_png("./assets/textures/floor-64px.png");
	game->texture->wall = mlx_load_png("./assets/textures/wall-64px.png");
	game->texture->collects = mlx_load_png("./assets/textures/collect-64px.png");
	game->texture->exit = mlx_load_png("./assets/textures/exit-64px.png");
	game->texture->player = mlx_load_png("./assets/player/pagu-idle-03-64px.png");
	if ((!(game->texture->floor)) || (!(game->texture->wall)) || (!(game->texture->player)) 
	|| (!(game->texture->collects))|| (!(game->texture->collects))|| (!(game->texture->exit)))
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
	get_player_pos(game->map, &game->player_pos);
	occurence_count(game->map, &game->occ);
	mlx_key_hook(game->mlx, &init_move, game);
	mlx_loop(game->mlx);
	delete_images(game);
	free_map(game->map);
	mlx_terminate(game->mlx);
	return (EXIT_SUCCESS);
}
