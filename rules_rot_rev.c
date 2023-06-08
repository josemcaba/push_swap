/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_rot_rev.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 21:45:48 by jocaball          #+#    #+#             */
/*   Updated: 2023/06/08 20:57:35 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*get_blast(t_stack *p)
{
	t_stack	*np;

	np = p;
	while (np->next->next)
		np = np->next;
	return (np);
}

void	rotate(t_stack **p, char *order, int ver)
{
	t_stack	*last;

	if (*p == NULL)
		return ;
	if ((*p)->next == NULL)
		return ;
	last = get_blast(*p)->next;
	last->next = *p;
	*p = (*p)->next;
	last = last->next;
	last->next = NULL;
	if (ver && order)
		write(1, order, 3);
}

void	drotate(t_stack **a, t_stack **b, int ver)
{
	rotate(a, NULL, 0);
	rotate(b, NULL, 0);
	if (ver)
		write(1, "rr\n", 3);
}

void	reverse(t_stack **p, char *order, int ver)
{
	t_stack	*blast;

	if (*p == NULL)
		return ;
	if ((*p)->next == NULL)
		return ;
	blast = get_blast(*p);
	blast->next->next = *p;
	*p = blast->next;
	blast->next = NULL;
	if (ver && order)
		write(1, order, 4);
}

void	dreverse(t_stack **a, t_stack **b, int ver)
{
	reverse(a, NULL, 0);
	reverse(b, NULL, 0);
	if (ver)
		write(1, "rrr\n", 4);
}
