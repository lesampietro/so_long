/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 17:39:51 by lsampiet          #+#    #+#             */
/*   Updated: 2024/04/20 19:06:17 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// static void error(void)
// {
// 	puts(mlx_strerror(mlx_errno));
// 	exit(EXIT_FAILURE);
// }

int32_t main(int argc, char **argv)
{
	char	**new_map;
	int		i;
	t_game	game;

	i = 0;
	if(argc != 2)
		ft_error("Error.\nMissing argument.\n", NULL);
	is_valid_entry(&argv[1]);
	new_map = read_map(argv[1]);
	is_valid_map(new_map);
	init_game(new_map, &game);
	free_map(new_map);
	return (EXIT_SUCCESS);
}
		// if(new_map)
		// {
		// 	return (1);
		// 	// check_map_shape(argv[1]);
		// 	// check_map_chars(argv[1]);
		// 	// check_map_walls;
		// 	// check_col_lin_size;
		// 	// floodfill;
		// }