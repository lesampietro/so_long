/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 20:15:23 by lsampiet          #+#    #+#             */
/*   Updated: 2024/05/11 21:27:06 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	count_map_size(t_game *game)
{
	int	l;
	int	c;

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

void	display_icon(t_game *game)
{
	game->icon = mlx_load_png("./assets/player/p-idle-00.png");
	if (!game->icon)
		ft_error(ERROR_TEXTURE_B, NULL);
	mlx_set_icon(game->mlx, game->icon);
}
