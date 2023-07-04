/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 21:32:02 by jocaball          #+#    #+#             */
/*   Updated: 2023/07/04 13:59:50 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max(t_stack *s)
{
	int	max;

	max = s->nbr;
	while (s)
	{
		if (s->nbr > max)
			max = s->nbr;
		s = s->next;
	}
	return (max);
}

int	find_min(t_stack *s)
{
	int	min;

	min = s->nbr;
	while (s)
	{
		if (s->nbr < min)
			min = s->nbr;
		s = s->next;
	}
	return (min);
}

void	sort_3_nbr(t_stack **a, t_stack **b)
{
	int		max;

	max = find_max(*a);
	if ((*a)->nbr == max)
		exec("ra\n", a, b, VER);
	if ((*a)->next->nbr == max)
		exec("rra\n", a, b, VER);
	if ((*a)->nbr > (*a)->next->nbr)
		exec("sa\n", a, b, VER);
}

void	set_up(t_stack **a, t_stack **b, int *count)
{
	if (!check_order(*a, *b) && (count[0] == 2))
		exec("sa\n", a, b, VER);
	while (!check_order(*a, *b) && (count[0] > 3))
	{
		exec("pb\n", a, b, VER);
		count[0]--;
		count[1]++;
	}
	sort_3_nbr(a, b);
}

void	finish(t_stack **a, t_stack **b, int *count)
{
	int	pos;
	int	min;

	min = find_min(*a);
	pos = find_pos_nbr(min, *a, *b);
	move_up_a(a, b, count, pos);
}
