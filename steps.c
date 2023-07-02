/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   steps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 21:35:20 by jocaball          #+#    #+#             */
/*   Updated: 2023/06/09 20:08:56 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	steps_to_top(int count, int pos)
{
	int	up;
	int	down;

	if (pos < 0)
		pos = -pos;
	up = pos - 1;
	down = count - pos + 1;
	if (up <= down)
		return (up);
	else
		return (-down);
}

int	steps_in_a(int nbr, t_stack *a, t_stack *b, int *count)
{
	int	steps;
	int	pos;

	pos = find_pos_nbr(nbr, a, b);
	if (pos <= 0)
		return (0);
	steps = steps_to_top(count[0], pos);
	if (steps < 0)
		steps *= -1;
	return (steps);
}

void	find_min_max(int nbr, t_stack *b, int *min, int *max)
{
	*min = nbr;
	*max = nbr;
	while (b)
	{
		if (b->nbr < *min)
			*min = b->nbr;
		if (b->nbr > *max)
			*max = b->nbr;
		b = b->next;
	}
}

int	steps_in_b(int nbr, t_stack *a, t_stack *b, int *count)
{
	int	steps;
	int	pos;
	int	hole;

	if (count[1] <= 1)
		return (0);
	hole = find_b_hole(nbr, b);
	pos = find_pos_nbr(hole, a, b);
	if (pos >= 0)
		return (0);
	steps = steps_to_top(count[1], -pos);
	if (steps < 0)
		steps *= -1;
	return (steps);
}

int	get_next_nbr(t_stack *a, t_stack *b, int *count)
{
	int		next_nbr;
	int		steps;
	int		current_steps;
	t_stack	*tmp_stk;

	tmp_stk = a;
	next_nbr = tmp_stk->nbr;
	steps = steps_in_a(next_nbr, a, b, count);
	steps += steps_in_b(next_nbr, a, b, count);
	tmp_stk = tmp_stk->next;
	while (tmp_stk && steps)
	{
		current_steps = steps_in_a(tmp_stk->nbr, a, b, count);
		current_steps += steps_in_b(tmp_stk->nbr, a, b, count);
		if (current_steps < steps)
			next_nbr = tmp_stk->nbr;
		tmp_stk = tmp_stk->next;
	}
	return (next_nbr);
}
