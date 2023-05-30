/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_rot_rev.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 21:45:48 by jocaball          #+#    #+#             */
/*   Updated: 2023/05/31 01:04:57 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack *p)
{
	if (!(p->stack))
		return ;
	if ((p->stack)->next == NULL)
		return ;
	p->last->next = p->stack;
	p->stack = p->stack->next;
	p->last = p->last->next;
	p->last->next = NULL;
}

void	drotate(t_stack *a, t_stack *b)
{
	rotate(a);
	rotate(b);
}

void	reverse(t_stack *p)
{
	t_node	*tn;

	if (!(p->stack))
		return ;
	if ((p->stack)->next == NULL)
		return ;
	tn = p->last;
	p->last->next = p->stack;
	p->last = NULL;

	tn++;
	tn--;
}

void	dreverse(t_stack *a, t_stack *b)
{
	reverse(a);
	reverse(b);
}
