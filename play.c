/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 21:35:20 by jocaball          #+#    #+#             */
/*   Updated: 2023/05/31 20:48:27 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ver(t_stack *a, t_stack *b)
{
	t_stack	*na;
	t_stack	*nb;

	na = a;
	nb = b;
	while (na || nb)
	{
		if (na)
		{
			ft_printf("%11i", na->nbr);
			na = na->next;
			if (!nb)
				ft_printf("\n");
		}
		else
			ft_printf("%11s", "");
		if (nb)
		{
			ft_printf("%14i\n", nb->nbr);
			nb = nb->next;
		}
	}
	ft_printf("-----a-----   -----b-----\n");
}

static void	exec(char *order, t_stack *a, t_stack *b)
{
	if (!ft_strncmp("sa\n", order, ft_strlen(order)))
		swap(&(*a));
	if (!ft_strncmp("sb\n", order, ft_strlen(order)))
		swap(&(*b));
	if (!ft_strncmp("ss\n", order, ft_strlen(order)))
		dswap(&(*a), &(*b));
	if (!ft_strncmp("pa\n", order, ft_strlen(order)))
		push(&(*a), &(*b));
	if (!ft_strncmp("pb\n", order, ft_strlen(order)))
		push(&(*b), &(*a));
	if (!ft_strncmp("ra\n", order, ft_strlen(order)))
		rotate(&(*a));
	if (!ft_strncmp("rb\n", order, ft_strlen(order)))
		rotate(&(*b));
	if (!ft_strncmp("rr\n", order, ft_strlen(order)))
		drotate(&(*a), &(*b));
	if (!ft_strncmp("rra\n", order, ft_strlen(order)))
		reverse(&(*a));
	if (!ft_strncmp("rrb\n", order, ft_strlen(order)))
		reverse(&(*b));
	if (!ft_strncmp("rrr\n", order, ft_strlen(order)))
		dreverse(&(*a), &(*b));
}

void	play(t_stack *a, t_stack *b)
{
	char	*order;

	ver(a, b);
	order = get_next_line(0);
	while (order && order[0] != '\n')
	{
		ft_printf("%s", order);
		exec(order, a, b);
		ver(a, b);
		order = get_next_line(0);
	}
	free(order);
}
