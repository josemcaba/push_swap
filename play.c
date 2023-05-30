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

void	ver(t_stack *stack_a, t_stack *stack_b)
{
	ssize_t	i;

	i = stack_a->i;
	if (stack_b->i > i)
		i = stack_b->i;
	while (i >= 0)
	{
		if (i <= stack_a->i)
			ft_printf("%11i", stack_a->layer[i][0]);
		else
			ft_printf("%11s", "");
		if (i <= stack_b->i)
			ft_printf("%14i\n", stack_b->layer[i][0]);
		else
			ft_printf("%11s\n", "");
		i--;
	}
	ft_printf("-----a-----   -----b-----\n");
}

void	exec(char *order, t_stack *stack_a, t_stack *stack_b)
{
	if (!ft_strncmp("sa\n", order, ft_strlen(order)))
		swap(stack_a);
	if (!ft_strncmp("sb\n", order, ft_strlen(order)))
		swap(stack_b);
	if (!ft_strncmp("ss\n", order, ft_strlen(order)))
		dswap(stack_a, stack_b);
	if (!ft_strncmp("pa\n", order, ft_strlen(order)))
		push(stack_a, stack_b);
	if (!ft_strncmp("pb\n", order, ft_strlen(order)))
		push(stack_b, stack_a);
	if (!ft_strncmp("ra\n", order, ft_strlen(order)))
		rotate(stack_a);
	if (!ft_strncmp("rb\n", order, ft_strlen(order)))
		rotate(stack_b);
	if (!ft_strncmp("rr\n", order, ft_strlen(order)))
		drotate(stack_a, stack_b);
	if (!ft_strncmp("rra\n", order, ft_strlen(order)))
		reverse(stack_a);
	if (!ft_strncmp("rrb\n", order, ft_strlen(order)))
		reverse(stack_b);
	if (!ft_strncmp("rrr\n", order, ft_strlen(order)))
		dreverse(stack_a, stack_b);
}

void	play(t_stack *stack_a, t_stack *stack_b)
{
	char	*order;

	ver(stack_a, stack_b);
	order = get_next_line(0);
	while (order)
	{
		ft_printf("%s", order);
		exec(order, stack_a, stack_b);
		ver(stack_a, stack_b);
		order = get_next_line(0);
	}
	free(order);
}
