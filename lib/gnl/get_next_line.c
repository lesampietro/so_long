/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 20:03:51 by lsampiet          #+#    #+#             */
/*   Updated: 2024/03/27 21:30:28 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/get_next_line.h"

char	*ft_get_line(g_list **list)
{
	int		str_len;
	char	*next_str;

	str_len = 0;
	if (*list == NULL)
	{
		free(*list);
		list = NULL;
		return (NULL);
	}
	str_len = ft_line_len(*list);
	next_str = malloc(str_len + 1);
	if (next_str == NULL)
		return (NULL);
	ft_copy_line(*list, next_str);
	return (next_str);
}

void	ft_tideup_list(g_list **list)
{
	g_list	*last_node;
	g_list	*new_node;
	int		i;
	int		n;
	char	*buffer;

	i = 0;
	n = 0;
	if (*list == NULL)
		return ;
	buffer = malloc(BUFFER_SIZE + 1);
	new_node = malloc(sizeof(g_list));
	if (buffer == NULL || new_node == NULL)
		return ;
	last_node = ft_find_last_node(*list);
	while (last_node->str_buffer[i] != '\0' \
		&& last_node->str_buffer[i] != '\n')
		i++;
	while (last_node->str_buffer[i] != '\0' \
		&& last_node->str_buffer[i++] != '\0')
		buffer[n++] = last_node->str_buffer[i];
	buffer[n] = '\0';
	new_node->str_buffer = buffer;
	new_node->next = NULL;
	ft_dealloc(list, new_node, buffer);
}

void	ft_add_node(g_list **list, char *buffer)
{
	g_list	*new_node;
	g_list	*last_node;

	if (buffer == NULL)
		return ;
	last_node = ft_find_last_node(*list);
	new_node = malloc(sizeof(g_list));
	if (new_node == NULL)
		return ;
	if (last_node == NULL)
		*list = new_node;
	else
		last_node->next = new_node;
	new_node->str_buffer = buffer;
	new_node->next = NULL;
}

void	ft_create_list(g_list **list, int fd)
{
	int		chars_read;
	char	*buffer;

	while (!ft_find_newline(*list))
	{
		buffer = malloc(BUFFER_SIZE + 1);
		if (buffer == NULL)
			return ;
		chars_read = read(fd, buffer, BUFFER_SIZE);
		if (!chars_read)
		{
			free(buffer);
			return ;
		}
		buffer[chars_read] = '\0';
		ft_add_node(list, buffer);
	}
}

char	*get_next_line(int fd)
{
	static g_list	*list;
	char			*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		if (list != NULL)
		{
			free(list->str_buffer);
			list->str_buffer = NULL;
		}	
		free(list);
		list = NULL;
		return (NULL);
	}	
	ft_create_list(&list, fd);
	next_line = ft_get_line(&list);
	ft_tideup_list(&list);
	return (next_line);
}
