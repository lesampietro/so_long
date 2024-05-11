/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 18:27:29 by lsampiet          #+#    #+#             */
/*   Updated: 2024/05/11 17:15:58 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	count_lines(char *map)
{
	int		n;
	int		fd;
	char	*read_map;

	n = 0;
	fd = open(map, O_RDONLY);
	read_map = NULL;
	while (1)
	{
		read_map = get_next_line(fd);
		if (!read_map)
			break ;
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
	if (!n_lines)
		ft_error(ERROR_EMPTY_MAP, NULL);
	tmp_map = NULL;
	new_map = malloc(sizeof(char *) * (n_lines + 1));
	new_map[n_lines] = NULL;
	fd = open(map, O_RDONLY);
	while (1)
	{
		tmp_map = get_next_line(fd);
		if (!tmp_map)
			break ;
		new_map[i] = tmp_map;
		i++;
	}
	close(fd);
	return (new_map);
}
