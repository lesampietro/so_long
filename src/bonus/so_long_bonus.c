/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 17:39:51 by lsampiet          #+#    #+#             */
/*   Updated: 2024/05/05 19:46:53 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

void	init_values(t_game *game)
{
	game->map = NULL;
	game->mlx = NULL;
	game->col = 0;
	game->lin = 0;
	game->icon = NULL;
	game->player_pos.x = 0;
	game->player_pos.y = 0;
	game->end_game = 1;
	game->steps = 0;
}

int32_t	main(int argc, char **argv)
{
	char	**new_map;
	int		i;
	t_game	game;

	i = 0;
	init_values (&game);
	if (argc != 2)
		ft_error(ERROR_ARG, NULL);
	is_valid_entry(&argv[1]);
	new_map = read_map(argv[1]);
	is_valid_map(new_map);
	free_map(new_map);
	init_game(argv[1], &game);
	return (EXIT_SUCCESS);
}
