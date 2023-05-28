/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 17:20:52 by jocaball          #+#    #+#             */
/*   Updated: 2023/04/23 22:16:11 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Parámetros				:	lst: el principio de la lista.
// Valor devuelto			:	El último nodo de la lista
// Funciones autorizadas	:	Ninguna
// Descripción 				:	Devuelve el último nodo de la lista.

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*node;

	if (lst == NULL)
		return (NULL);
	node = lst;
	while (node->next)
		node = node->next;
	return (node);
}
