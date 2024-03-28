/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 18:27:29 by lsampiet          #+#    #+#             */
/*   Updated: 2024/03/27 23:05:18 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	**read_map(char *map)
{
	int		fd;
	char	*new_map;
	
	if(!map)
		exit(ft_printf("Map is empty"));
	fd = open(map, O_RDONLY);
	new_map = get_next_line(fd);
	while(new_map != '\0')
		ft_printf(new_map);
	close(fd);
	return (NULL);
}