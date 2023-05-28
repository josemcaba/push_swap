/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 17:21:34 by jocaball          #+#    #+#             */
/*   Updated: 2023/04/23 22:17:37 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Parámetros				:	lst: el puntero al primer nodo de una lista.
//								new: el puntero a un nodo que añadir a la lista.
// Valor devuelto			:	Nada
// Funciones autorizadas	:	Ninguna
// Descripción 				:	Añade el nodo ’new’ al final de la lista ’lst’.

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*node;

	node = ft_lstlast(*lst);
	if (node == NULL)
		*lst = new;
	else
		node->next = new;
}
