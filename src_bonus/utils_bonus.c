/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 20:15:23 by lsampiet          #+#    #+#             */
/*   Updated: 2024/05/12 06:38:56 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	put_counter(t_game *game)
{
	char	*str;

	str = ft_itoa(game->steps);
	if (!str)
		ft_error(ERROR_STEPS_B, NULL);
	if (game->counter)
		mlx_delete_image(game->mlx, game->counter);
	game->counter = mlx_put_string(game->mlx, str, 10, 10);
	free(str);
}

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
	put_counter(game);
	ft_printf("Steps: %i\n", game->steps);
}

void	display_icon(t_game *game)
{
	game->icon = mlx_load_png("./assets/player/p-idle-R-00.png");
	if (!game->icon)
		ft_error(ERROR_TEXTURE_B, NULL);
	mlx_set_icon(game->mlx, game->icon);
}
