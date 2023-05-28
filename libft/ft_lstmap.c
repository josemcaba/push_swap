/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 09:22:24 by jocaball          #+#    #+#             */
/*   Updated: 2023/04/27 21:50:42 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Parámetros     : lst : un puntero a un nodo.
//				    f   : la dirección de un puntero a una función usada en la
//                        iteración de cada elemento de la lista. 
//				    del : un puntero a función utilizado para eliminar el 
//					      contenido de un nodo, si es necesario.
// Valor devuelto : La nueva lista
//					NULL si falla la reserva de memoria.
// Func. autoriz. : malloc, free
// Descripción    : Itera la lista ’lst’ y aplica la función ’f’ al contenido
//                  de cada nodo. Crea una lista resultante de la aplicación
//                  correcta y sucesiva de la función ’f’ sobre cada nodo. La
//                  función ’del’ se utiliza para eliminar el contenido de un
//                  nodo, si hace falta.

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_node;

	if (!lst || !f || !del)
		return (NULL);
	new_lst = NULL;
	while (lst)
	{
		new_node = (t_list *)malloc(sizeof(t_list));
		if (!new_node)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		new_node->content = (*f)(lst->content);
		new_node->next = NULL;
		ft_lstadd_back(&new_lst, new_node);
		lst = lst->next;
	}
	return (new_lst);
}
