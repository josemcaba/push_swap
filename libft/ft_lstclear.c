/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 18:00:54 by jocaball          #+#    #+#             */
/*   Updated: 2023/04/23 22:18:51 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Parámetros            : lst: la dirección de un puntero a un nodo.
//                         del: un puntero a función utilizado para eliminar el
//                              contenido de un nodo.
// Funciones autorizadas : free
// Descripción           : Elimina y libera el nodo ’lst’ dado y todos los
//                         consecutivos de ese nodo, utilizando la función 
//						   ’del’ y free(3).
//                         Al final, el puntero a la lista debe ser NULL.

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*next_node;

	while (*lst)
	{
		next_node = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = next_node;
	}
	*lst = NULL;
}
