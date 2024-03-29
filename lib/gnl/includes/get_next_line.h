/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsampiet <lsampiet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:48:49 by lsampiet          #+#    #+#             */
/*   Updated: 2024/03/27 21:18:37 by lsampiet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct gnl_list
{
	char			*str_buffer;
	struct gnl_list	*next;
}					g_list;

int		ft_line_len(g_list *list);
int		ft_find_newline(g_list *list);
char	*get_next_line(int fd);
char	*ft_get_line(g_list **list);
void	ft_tideup_list(g_list **list);
void	*ft_copy_line(g_list *list, char *nxt_str);
void	ft_add_node(g_list **list, char *buffer);
void	ft_create_list(g_list **list, int fd);
void	ft_dealloc(g_list **list, g_list *clean_node, char *buffer);
g_list	*ft_find_last_node(g_list *list);

#endif