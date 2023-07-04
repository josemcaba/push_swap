/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 21:35:20 by jocaball          #+#    #+#             */
/*   Updated: 2023/07/04 17:29:43 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_a_hole(int nbr, t_stack *a)
{
	int	min;
	int	max;
	int	prev;
	int	next;

	find_min_max(nbr, a, &min, &max);
	prev = min;
	next = max;
	while (a)
	{
		if ((prev < a->nbr) && (a->nbr < nbr))
			prev = a->nbr;
		if ((nbr < a->nbr) && (a->nbr < next))
			next = a->nbr;
		a = a->next;
	}
	if (max == nbr)
		return (min);
	return (next);
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

int	move_up(int stack, int count, int pos)
{
	int	steps;

	steps = 0;
	if (stack == 1)
		pos *= -1;
	if (pos > 1)
		steps = steps_to_top(count, pos);
	return (steps);
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

void	sort(t_stack **a, t_stack **b, int *count)
{
	int	pos;
	int	next_nbr;
	int	hole;
	int	move[2];

	set_up(a, b, count);
	while (!check_order(*a, *b) && count[1])
	{
		next_nbr = get_next_nbr(*a, *b, count);
		pos = find_pos_nbr(next_nbr, *a, *b);
		move[1] = move_up(1, count[1], pos);
		hole = find_a_hole(next_nbr, *a);
		pos = find_pos_nbr(hole, *a, *b);
		move[0] = move_up(0, count[0], pos);
		let_move(a, b, move);
		count[0]++;
		count[1]--;
	}
	finish(a, b, count);
}
