/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 20:51:14 by jocaball          #+#    #+#             */
/*   Updated: 2023/05/26 19:42:42 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*alloc_line(t_glist **list)
{
	int		nl_flag;
	t_glist	*node;
	size_t	len;
	char	*line;

	nl_flag = 0;
	node = *list;
	len = 0;
	while (node && !nl_flag)
	{
		len += node->len;
		nl_flag = node->nl_flag;
		node = node->next;
	}
	line = (char *)malloc(len * sizeof(char) + 1);
	return (line);
}

static char	*write_line(t_glist **list)
{
	t_glist	*next_node;
	int		nl_flag;
	char	*line;
	size_t	i;

	line = alloc_line(&(*list));
	if (!line)
		return (NULL);
	nl_flag = 0;
	i = 0;
	while (*list && !nl_flag)
	{
		nl_flag = (*list)->nl_flag;
		mem_cpy_str(&line[i], (*list)->content, (*list)->len);
		i += (*list)->len;
		next_node = (*list)->next;
		free((*list)->content);
		free(*list);
		*list = next_node;
	}
	line[i] = '\0';
	return (line);
}

static ssize_t	add_node_to_list(char *buffer, t_glist **list, ssize_t read_len)
{
	ssize_t	len;
	int		nl_flag;
	t_glist	*node;
	char	*content;
	ssize_t	i;

	i = 0;
	len = 0;
	while ((i < read_len) && (len >= 0))
	{	
		len = str_len(&(buffer[i]), &nl_flag);
		content = (char *)malloc(len * sizeof(char) + 1);
		if (!content)
			return (-1);
		mem_cpy_str(content, &(buffer[i]), len);
		node = lst_new_node(content, nl_flag, len);
		if (!node)
		{
			free(content);
			return (-1);
		}
		lst_add_node(&(*list), node);
		i += len;
	}
	return (len);
}

static ssize_t	read_buff_to_list(t_glist **list, int fd)
{
	char	*buffer;
	ssize_t	read_len;
	ssize_t	node_len;

	buffer = (char *)malloc(BUFFER_SIZE * sizeof(char) + 1);
	if (!buffer)
		return (-1);
	read_len = 1;
	node_len = 0;
	while (read_len && (node_len >= 0) && (!*list || !(*list)->nl))
	{
		read_len = read(fd, buffer, BUFFER_SIZE);
		if (read_len < 0)
		{
			lst_free(&(*list));
			break ;
		}
		buffer[read_len] = '\0';
		node_len = add_node_to_list(buffer, &(*list), read_len);
	}
	free(buffer);
	return (read_len * node_len);
}

char	*get_next_line(int fd)
{
	ssize_t			len;
	char			*line;
	static t_glist	*list[FD_MAX];

	if ((fd < 0) || BUFFER_SIZE <= 0)
		return (NULL);
	len = 0;
	if (!list[fd] || !list[fd]->nl)
		len = read_buff_to_list(&list[fd], fd);
	if ((len < 0) || !list[fd])
	{
		lst_free(&list[fd]);
		return (NULL);
	}
	line = write_line(&list[fd]);
	if (!line)
	{
		lst_free(&list[fd]);
		return (NULL);
	}
	return (line);
}
