/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 17:39:51 by lsampiet          #+#    #+#             */
/*   Updated: 2024/03/24 19:44:08 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// static void error(void)
// {
// 	puts(mlx_strerror(mlx_errno));
// 	exit(EXIT_FAILURE);
// }

int32_t main(int argc, char **argv)
{
	char	**new_map;
	
	if(argc == 2)
	{
		new_map = read_map(argv[1]);
		if(new_map)
		{
			return (1);
			// check_map_ext(argv[1]);
			// check_map_shape(argv[1]);
			// check_map_chars(argv[1]);
		}
		exit(ft_printf("Could not open map"));
	}
	exit(ft_printf("Missing argument"));
}