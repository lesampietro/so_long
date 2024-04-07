/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 18:50:53 by lsampiet          #+#    #+#             */
/*   Updated: 2024/04/07 18:15:23 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <stdlib.h>

#include "../lib/MLX42/include/MLX42/MLX42.h"
#include "../lib/gnl/includes/get_next_line.h"
#include "../lib/ft_printf/includes/ft_printf.h"
#include "../lib/libft/libft.h"

char		**read_map(char *map);
void		is_invalid_entry(char **file_ext);

#endif