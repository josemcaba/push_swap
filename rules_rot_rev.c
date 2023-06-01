/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_rot_rev.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 21:45:48 by jocaball          #+#    #+#             */
/*   Updated: 2023/06/01 13:29:28 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*get_last(t_stack *p)
{
	t_stack	*np;

	np = p;
	while (np->next)
		np = np->next;
	return (np);
}

void	rotate(t_stack *p)
{
	t_stack	*last;

	if (p == NULL)
		return ;
	if (p->next == NULL)
		return ;
	last = get_last(p);
	last->next = p;
	p = p->next;
	last = last->next;
	last->next = NULL;
}

void	drotate(t_stack *a, t_stack *b)
{
	rotate(a);
	rotate(b);
}

void	reverse(t_stack *p)
{
	t_stack	*tn;

	if (p == NULL)
		return ;
	if (p->next == NULL)
		return ;
	tn = get_last(p);
	tn->next = p;
	tn = NULL;
	tn++;
	tn--;
}

void	dreverse(t_stack *a, t_stack *b)
{
	reverse(a);
	reverse(b);
}
