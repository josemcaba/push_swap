/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 17:06:45 by jocaball          #+#    #+#             */
/*   Updated: 2023/04/24 20:38:55 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Parámetros				:	content: el contenido con el que crear el nodo.
// Valor devuelto			:	El nuevo nodo
// Funciones autorizadas	:	malloc
// Descripción				:	Crea un nuevo nodo utilizando malloc(3). La 
// 								variable miembro ’content’ se inicializa con el
// 								contenido del parámetro ’content’. La variable
// 								’next’, con NULL.

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}
