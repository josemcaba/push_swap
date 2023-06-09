/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_push_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 21:47:13 by jocaball          #+#    #+#             */
/*   Updated: 2023/06/09 17:32:57 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **dst, t_stack **src, char *order, int ver)
{
	t_stack	*tn;

	if (!(*src))
		return ;
	if (!(*dst))
	{
		*dst = *src;
		*src = (*src)->next;
		(*dst)->next = NULL;
	}
	else
	{
		tn = *dst;
		*dst = *src;
		*src = (*src)->next;
		(*dst)->next = tn;
	}
	if (ver)
		write(1, order, 3);
}

void	swap(t_stack **p, char *order, int ver)
{
	t_stack	*tmp;

	if (*p == NULL)
		return ;
	if ((*p)->next == NULL)
		return ;
	tmp = *p;
	*p = (*p)->next;
	tmp->next = (*p)->next;
	(*p)->next = tmp;
	if (ver && order)
		write(1, order, 3);
}

void	dswap(t_stack **a, t_stack **b, int ver)
{
	swap(a, NULL, 0);
	swap(b, NULL, 0);
	if (ver)
		write(1, "ss\n", 3);
}
