/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 17:47:30 by lsampiet          #+#    #+#             */
/*   Updated: 2024/03/23 19:14:21 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/MLX42/include/MLX42/MLX42.h"
#include "../lib/gnl/get_next_line.h"
#include "../lib/ft_printf/includes/ft_printf.h"
#include "../lib/libft/libft.h"

// int32_t	main(void)
// {
// 	// Start mlx
// 	mlx_t *mlx = mlx_init(WIDTH, HEIGHT, "Capybara Game", false);
// 	if (!mlx)
// 		error();

// 	// Try to load the file
// 	mlx_texture_t *texture = mlx_load_png("./images/menu_bg.png");
// 	if (!texture)
// 		error();

// 	// Convert texture to a displayable image
// 	mlx_image_t *img = mlx_texture_to_image(mlx, texture);
// 	if (!img)
// 		error();

// 	// Display the image
// 	if (mlx_image_to_window(mlx, img, 0, 0) < 0)
// 		error();

// 	mlx_loop(mlx);

// 	mlx_delete_image(mlx, img);
// 	mlx_delete_texture(texture);

// 	// Optional, terminate will clean up any leftover images (not textures!)
// 	mlx_terminate(mlx);
// 	return (EXIT_SUCCESS);
// }