/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_push_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 21:47:13 by jocaball          #+#    #+#             */
/*   Updated: 2023/05/31 20:40:06 by jocaball         ###   ########.fr       */
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
		tn = dst;
		dst = src;
		src = src->next;
		dst->next = tn;
	}
}

void	swap(t_stack *p)
{
	int	tmp;

	if (p == NULL)
		return ;
	if (p->next == NULL)
		return ;
	tmp = p->nbr;
	p->nbr = p->next->nbr;
	p->next->nbr = tmp;
}

void	dswap(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
}
