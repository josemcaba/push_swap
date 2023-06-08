/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 21:35:20 by jocaball          #+#    #+#             */
/*   Updated: 2023/06/08 22:59:01 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find(int nbr, t_stack *a, t_stack *b)
{
	int	j;

	j = 0;
	while (a)
	{
		j++;
		if (a->nbr == nbr)
			return (j);
		a = a->next;
	}
	j = 0;
	while (b)
	{
		j++;
		if (b->nbr == nbr)
			return (-j);
		b = b->next;
	}
	return (0);
}

void	sort_push_b(t_stack **a, t_stack **b, int nbr, int count)
{
	if (count <= 1)
	{
		exec("pb\n", a, b, VER);
		return ;
	}
	if ((count == 1) && (nbr < (*b)->next->nbr))
	{
		exec("sb\n", a, b, VER);
		return ;
	}
	exec("pb\n", a, b, VER);
}

void	move_up_a(t_stack **a, t_stack **b, int *count, int pos)
{
	int	i;
	int	nbr;

	if ((pos == 2) && (count[1] == 0))
	{
		exec("sa\n", a, b, VER);
		return ;
	}
	i = count[0];
	while ((i - pos) >= 0)
	{
		nbr = (*a)->nbr;
		exec("rra\n", a, b, VER);
		if ((i - pos) > 0)
		{
			sort_push_b(a, b, nbr, count[1]);
			count[0]--;
			count[1]++;
		}
		i--;
	}
}

void	move_up_b(t_stack **a, t_stack **b, int *count, int pos)
{
	int	steps;

	if (pos > 1)
	{
		steps = steps_nbr(count[1], pos);
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
	exec("pa\n", a, b, VER);
	count[0]++;
	count[1]--;
}

int	steps_nbr(int count, int pos)
{
	int	up;
	int	down;

	up = pos - 1;
	down = count - pos + 1;
	if (up <= down)
		return (up);
	else
		return (-down);
}

void	place_first_nbr(t_stack **a, t_stack **b, int nbr, int count)
{
	int	pos;
	int	steps;

	if (check_order(*a, *b))
		return ;
	pos = find(nbr, *a, *b);
	steps = steps_nbr(count, pos);
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

void	swap_heads(t_stack **a, t_stack **b, int *count)
{
	if ((count[0] > 1) && (count[1] > 1))
	{	
		if (((*a)->nbr > (*a)->next->nbr) && ((*b)->nbr < (*b)->next->nbr))
			exec("ss\n", a, b, VER);
	}
	else if ((count[0] > 1) && ((*a)->nbr > (*a)->next->nbr))
		exec("sa\n", a, b, VER);
	else if ((count[1] > 1) && ((*b)->nbr > (*b)->next->nbr))
	{
		write(1, "sb\n", 3);
		exec("sb\n", a, b, VER);
	}	
}

void	sort(t_stack **a, t_stack **b, int *vector, int *count)
{
	int	i;
	int	j;

	place_first_nbr(a, b, vector[0], count[0]);
	i = 1;
	while (!check_order(*a, *b))
	{
		j = find(vector[i], *a, *b);
		if (j > 0)
			move_up_a(a, b, count, j);
		else
			move_up_b(a, b, count, -j);
		i++;
	}
}
