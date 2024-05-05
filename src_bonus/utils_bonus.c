/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 20:15:23 by lsampiet          #+#    #+#             */
/*   Updated: 2024/05/05 14:37:34 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

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

void	counter(t_game *game)
{
	game->steps++;
	ft_printf("Steps: %i\n", game->steps);
}
