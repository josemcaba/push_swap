/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 20:55:23 by jocaball          #+#    #+#             */
/*   Updated: 2023/05/26 19:43:25 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_glist	*lst_new_node(char *content, int nl_flag, size_t len)
{
	t_glist	*node;

	node = (t_glist *)malloc(sizeof(t_glist));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	node->nl_flag = nl_flag;
	node->nl = nl_flag;
	node->len = len;
	return (node);
}

void	lst_add_node(t_glist **list, t_glist *node)
{
	t_glist	*last_node;

	if (!(*list))
		*list = node;
	else
	{
		last_node = *list;
		last_node->nl += node->nl;
		while (last_node->next)
		{
			last_node = last_node->next;
			last_node->nl += node->nl;
		}
		last_node->next = node;
	}
}

void	lst_free(t_glist **list)
{
	t_glist	*next_node;

	while (*list)
	{
		next_node = (*list)->next;
		free((*list)->content);
		free(*list);
		*list = next_node;
	}
}

void	mem_cpy_str(char *dst, char *src, size_t len)
{
	if ((char *)dst && (char *)src)
		while (len--)
			*(dst + len) = *(src + len);
}

size_t	str_len(char *str, int *nl_flag)
{
	size_t	i;

	i = 0;
	*nl_flag = 0;
	while ((str[i] != '\n') && (str[i] != '\0'))
		i++;
	if (str[i] == '\n')
	{
		*nl_flag = 1;
		i++;
	}
	return (i);
}
