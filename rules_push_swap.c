/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_push_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 21:47:13 by jocaball          #+#    #+#             */
/*   Updated: 2023/05/30 01:57:42 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack *dst, t_stack *src)
{
	t_node	*tn;

	if (!(src->stack))
		return ;	
	if (!(dst->stack))
	{
		dst->stack = src->stack;
		src->stack = src->stack->next;
		dst->stack->next = NULL;
		dst->last = dst->stack;
	}
	else
	{
		tn = dst->stack;
		dst->stack = src->stack;
		src->stack = src->stack->next;
		dst->stack->next = tn;
	}
	if (!(src->stack))
		src->last = NULL;
}

void	swap(t_stack *a)
{
	t_node	*tn;

	if (!(a->stack))
		return ;
	if (a->stack->next == NULL)
		return ;
	tn = a->stack;
	a->stack = a->stack->next;
	tn->next = a->stack->next;
	a->stack->next = tn;
}

void	dswap(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
}
