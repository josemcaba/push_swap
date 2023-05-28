/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 17:22:21 by jocaball          #+#    #+#             */
/*   Updated: 2023/04/23 22:18:00 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Parámetros				:	lst: el nodo a liberar.
//								del: un puntero a la función utilizada para 
//								liberar el contenido del nodo.
// Valor devuelto			:	Nada
// Funciones autorizadas	:	free
// Descripción 				:	Toma como parámetro un nodo ’lst’ y libera la
// 								memoria del contenido utilizando la función 
// 								’del’ dada como parámetro, además de liberar el 
// 								nodo. La memoria de ’next’ no debe liberarse.

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	del(lst->content);
	free(lst);
}
