/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 18:27:29 by lsampiet          #+#    #+#             */
/*   Updated: 2024/04/14 20:46:24 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int		count_lines(char *map)
{
	int		n;
	int		fd;
	char	*read_map;

	n = 0;
	fd = open(map, O_RDONLY);
	while ((read_map = get_next_line(fd)))
	{
		free(read_map);
		n++;
	}
	close(fd);
	return (n);
}

char	**read_map(char *map)
{
	int		fd;
	int		i;
	int		n_lines;
	char	*tmp_map;
	char	**new_map;
	
	i = 0;
	n_lines = count_lines(map);
	if(!n_lines)
		exit(ft_printf("Error.\nMap is empty.\n"));
	new_map = malloc(sizeof(char *) * (n_lines + 1));
	new_map[n_lines] = NULL;
	fd = open(map, O_RDONLY);
	while ((n_lines >= 0) && (tmp_map = get_next_line(fd)))
	{
		new_map[i] = tmp_map;
		i++;		
	}
	close(fd);
	return (new_map);
}