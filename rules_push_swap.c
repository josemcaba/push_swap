/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_push_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 21:47:13 by jocaball          #+#    #+#             */
/*   Updated: 2023/05/31 00:45:45 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack *dst, t_stack *src)
{
	t_stack	*tn;

	if (!(src))
		return ;
	if (!(dst))
	{
		dst = src;
		dst->next = NULL;
		src = src->next;
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

void	swap(t_stack *p)
{
	t_node	*tn;

	if (!(p->stack))
		return ;
	if (p->stack->next == NULL)
		return ;
	tn = p->stack;
	p->stack = p->stack->next;
	tn->next = p->stack->next;
	p->stack->next = tn;
}

void	dswap(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
}
