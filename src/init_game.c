/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 17:47:30 by lsampiet          #+#    #+#             */
/*   Updated: 2024/05/04 22:53:02 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// checar valgrind com as bandeiras indicadas pelo dani
// limpar os leaks de memória - função q limpa tudo
// filtro qtd de linhas e colunas / resize maximo
// animar o gato (muito importante!!!)

void	init_game_image(t_game *game)
{
	init_tile_textures(game);
	put_floor_n_walls(game);
	put_collects_n_exit(game);
	put_player(game);
}

void	init_window(t_game *game)
{
	int32_t moni_w;
	int32_t moni_h;

	moni_w = 0;
	moni_h = 0;
	mlx_set_setting(MLX_STRETCH_IMAGE, 1);
	game->mlx = mlx_init((TILE * game->col), (TILE * game->lin), "Pagu", true);
	if (!game->mlx)
		ft_error("Error.\nMlx handle instance could not be initialized", NULL);
	mlx_get_monitor_size(0, &moni_w, &moni_h);
	mlx_set_window_limit(game->mlx, TILE, TILE, moni_w, moni_h);
	if (game->mlx->width > moni_w || game->mlx->height > moni_h)
	{
		ft_error("Error.\nMap is too big.", NULL);
		free_game(game);
	}
}

int32_t	init_game(char *argv, t_game *game)
{
	game->map = read_map(argv);
	count_map_size(game);
	init_window(game);
	init_game_image(game);
	get_player_pos(game->map, &game->player_pos);
	occurence_count(game->map, &game->occ);
	mlx_key_hook(game->mlx, &init_move, game);
	mlx_loop(game->mlx);
	free_game(game);
	return (EXIT_SUCCESS);
}

// double mlx_get_time(void);
