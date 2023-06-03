/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_push_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 21:47:13 by jocaball          #+#    #+#             */
/*   Updated: 2023/06/02 12:55:21 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **dst, t_stack **src)
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
}

void	swap(t_stack **p)
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
}

void	dswap(t_stack **a, t_stack **b)
{
	swap(a);
	swap(b);
}

void	exec(char *order, t_stack **a, t_stack **b)
{
	if (!ft_strncmp("sa\n", order, ft_strlen(order)))
		swap(a);
	if (!ft_strncmp("sb\n", order, ft_strlen(order)))
		swap(b);
	if (!ft_strncmp("ss\n", order, ft_strlen(order)))
		dswap(a, b);
	if (!ft_strncmp("pa\n", order, ft_strlen(order)))
		push(a, b);
	if (!ft_strncmp("pb\n", order, ft_strlen(order)))
		push(b, a);
	if (!ft_strncmp("ra\n", order, ft_strlen(order)))
		rotate(a);
	if (!ft_strncmp("rb\n", order, ft_strlen(order)))
		rotate(b);
	if (!ft_strncmp("rr\n", order, ft_strlen(order)))
		drotate(a, b);
	if (!ft_strncmp("rra\n", order, ft_strlen(order)))
		reverse(a);
	if (!ft_strncmp("rrb\n", order, ft_strlen(order)))
		reverse(b);
	if (!ft_strncmp("rrr\n", order, ft_strlen(order)))
		dreverse(a, b);
}
