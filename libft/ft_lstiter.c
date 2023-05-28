/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 18:08:54 by jocaball          #+#    #+#             */
/*   Updated: 2023/04/23 22:20:13 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Parámetros  : lst: un puntero al primer nodo.
//               f  : un puntero a la función que utilizará cada nodo. 
// Descripción : Itera la lista ’lst’ y aplica la función ’f’ en el contenido
//               de cada nodo.

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
