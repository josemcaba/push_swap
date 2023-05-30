/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 21:35:20 by jocaball          #+#    #+#             */
/*   Updated: 2023/05/30 02:01:57 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ver(t_node *a_stack, t_node *b_stack)
{
	t_node	*na;
	t_node	*nb;

	na = a_stack;
	nb = b_stack;
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

void	exec(char *order, t_stack *a, t_stack *b)
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
 	// if (!ft_strncmp("ra\n", order, ft_strlen(order)))
 	// 	rotate(&(*stack_a), &(*last_a));
 	// if (!ft_strncmp("rb\n", order, ft_strlen(order)))
 	// 	rotate(&(*stack_b), &(*last_b));
 	// if (!ft_strncmp("rr\n", order, ft_strlen(order)))
 	// 	drotate(&(*stack_a), &(*stack_b), &(*last_a), &(*last_b));
 	// if (!ft_strncmp("rra\n", order, ft_strlen(order)))
 	// 	reverse(&(*stack_a), &(*last_a));
 	// if (!ft_strncmp("rrb\n", order, ft_strlen(order)))
 	// 	reverse(&(*stack_b), &(*last_b));
 	// if (!ft_strncmp("rrr\n", order, ft_strlen(order)))
 	// 	dreverse(&(*stack_a), &(*stack_b), &(*last_a), &(*last_b));
}

void	play(t_stack *a, t_stack *b)
{
 	char	*order;

	ver(a->stack, b->stack);
 	order = get_next_line(0);
 	while (order && order[0] != '\n')
 	{
 		ft_printf("%s", order);
 		exec(order, a, b);
 		ver(a->stack, b->stack);
 		order = get_next_line(0);
 	}
 	free(order);
}
