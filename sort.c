/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 21:35:20 by jocaball          #+#    #+#             */
/*   Updated: 2023/06/08 01:23:45 by jocaball         ###   ########.fr       */
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

void	move_up_a(t_stack **a, t_stack **b, int *count, int pos)
{
	int	i;
	
	if ((pos == 2) && (count[1] == 0))
	{
		write(1, "sa\n", 3);
		exec("sa", a, b);
		return ;
	}
	i = count[0];
	while ((i - pos) >= 0)
	{
/***********************************************
*
*/
		write(1, "rra\n", 4);
		exec("rra", a, b);
		if ((i - pos) > 0)
		{
			write(1, "pb\n", 3);
			exec("pb", a, b);
			count[0]--;
			count[1]++;
			if ((*b)->next != 0)
			{
				if (get_blast(*b)->next->nbr > (*b)->nbr)
				{
					write(1, "rb\n", 3);
					exec("rb", a, b);
				}
			}
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
				write(1, "rb\n", 3);
				exec("rb", a, b);
				steps--;			
			}
			else
			{
				write(1, "rrb\n", 4);
				exec("rrb", a, b);
				steps++;			
			}
		}
	}
	write(1, "pa\n", 3);
	exec("pa", a, b);
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
			write(1, "ra\n", 3);
			exec("ra", a, b);
			steps--;			
		}
		else
		{
			write(1, "rra\n", 4);
			exec("rra", a, b);
			steps++;			
		}
	}
}

void	swap_heads(t_stack **a, t_stack **b, int *count)
{
	if ((count[0] > 1) && (count[1] > 1))
	{	
		if (((*a)->nbr > (*a)->next->nbr) && ((*b)->nbr < (*b)->next->nbr))
		{
			write(1, "ss\n", 3);
			exec("ss", a, b);
		}
	}
	else if ((count[0] > 1) && ((*a)->nbr > (*a)->next->nbr))
	{
		write(1, "sa\n", 3);
		exec("sa", a, b);
	}
	else if ((count[1] > 1) && ((*b)->nbr > (*b)->next->nbr))
	{
		write(1, "sb\n", 3);
		exec("sb", a, b);
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
