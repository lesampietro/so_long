/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 17:47:30 by lsampiet          #+#    #+#             */
/*   Updated: 2024/05/04 19:46:34 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void error(void)
{
	exit(EXIT_FAILURE);
}

// checar valgrind com as bandeiras indicadas pelo dani
// limpar os leaks de memória - função q limpa tudo
// filtro qtd de linhas e colunas / resize maximo
// animar o gato (muito importante!!!)
//void	mlx_close_hook(mlx_t * mlx, mlx_closefunc func, void *param);


void init_game_image(t_game *game)
{
	init_tile_textures(game);
	put_floor_n_walls(game);
	put_collects_n_exit(game);
	put_player(game);
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
