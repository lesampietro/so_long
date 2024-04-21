/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 17:39:51 by lsampiet          #+#    #+#             */
/*   Updated: 2024/04/21 19:30:53 by lsampiet         ###   ########.fr       */
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
	free_map(new_map);
	init_game(argv[1], &game);
	return (EXIT_SUCCESS);
}
