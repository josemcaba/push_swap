/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 21:35:20 by jocaball          #+#    #+#             */
/*   Updated: 2023/06/09 20:08:56 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_b_hole(int nbr, t_stack *b)
{
	int	min;
	int	max;
	int	prev;
	int	next;

	find_min_max(nbr, b, &min, &max);
	prev = min;
	next = max;
	while (b)
	{
		if ((prev < b->nbr) && (b->nbr < nbr))
			prev = b->nbr;
		if ((nbr < b->nbr) && (b->nbr < next))
			next = b->nbr;
		b = b->next;
	}
	if (prev == nbr)
		return (max);
	return (prev);
}

void	move_up_a(t_stack **a, t_stack **b, int *count, int pos)
{
	int	steps;

	if (pos > 1)
	{
		steps = steps_to_top(count[0], pos);
		while (steps)
		{
			if (steps > 0)
			{
				exec("ra\n", a, b, VER);
				steps--;
			}
			else
			{
				exec("rra\n", a, b, VER);
				steps++;
			}
		}
	}
}

void	move_up_b(t_stack **a, t_stack **b, int *count, int pos)
{
	int	steps;

	if (pos > 1)
	{
		steps = steps_to_top(count[1], pos);
		while (steps)
		{
			if (steps > 0)
			{
				exec("rb\n", a, b, VER);
				steps--;
			}
			else
			{
				exec("rrb\n", a, b, VER);
				steps++;
			}
		}
	}
}

int	find_pos_nbr(int nbr, t_stack *a, t_stack *b)
{
	int	pos;

	pos = 0;
	while (a)
	{
		pos++;
		if (a->nbr == nbr)
			return (pos);
		a = a->next;
	}
	pos = 0;
	while (b)
	{
		pos++;
		if (b->nbr == nbr)
			return (-pos);
		b = b->next;
	}
	return (0);
}

void	sort(t_stack **a, t_stack **b, int *vector, int *count)
{
	int	pos;
	int	next_nbr;
	int	hole;

	while (!check_order(*a, *b) && count[0])
	{
		next_nbr = get_next_nbr(*a, *b, count);
		pos = find_pos_nbr(next_nbr, *a, *b);
		move_up_a(a, b, count, pos);
		if (count[1] > 1)
		{
			hole = find_b_hole((*a)->nbr, *b);
			pos = find_pos_nbr(hole, *a, *b);
			move_up_b(a, b, count, -pos);
		}
		exec("pb\n", a, b, VER);
		count[0]--;
		count[1]++;
	}
	pos = find_pos_nbr(vector[0], *a, *b);
	move_up_b(a, b, count, -pos);
	while (*b)
		exec("pa\n", a, b, VER);
}
