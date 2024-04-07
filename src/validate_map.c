/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 17:40:08 by lsampiet          #+#    #+#             */
/*   Updated: 2024/04/07 17:38:35 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void is_invalid_entry(char **file_ext)
{
	char *valid_ext;
	char *ext;

	valid_ext = ".ber";
	ext = ft_strrchr(*file_ext, '.');
	if (ft_strncmp(ext, valid_ext, 4) != 0)
		exit(ft_printf("Invalid map file"));
	return;
}