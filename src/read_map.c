/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 18:27:29 by lsampiet          #+#    #+#             */
/*   Updated: 2024/04/07 18:05:21 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

git 

char	**read_map(char *map)
{
	int		fd;
	char	*new_map;
	
	if(!map)
		exit(ft_printf("Map is empty"));
	fd = open(map, O_RDONLY);
	while((new_map = get_next_line(fd)))
	{
		ft_printf("%s", new_map);
		free(new_map);
	}
	close(fd);
	return (NULL);
}