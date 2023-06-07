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
	int	up;
	int	down;

	if (pos == 2)
	{
		write(1, "sb\n", 3);
		exec("sb", a, b);
	}
	if (pos > 2)
	{
		up = pos - 1;
		down = count[1] - pos + 1;
		if (up <= down)
		{
			while (up--)
			{
				write(1, "rb\n", 3);
				exec("rb", a, b);
			}
		}
		else
		{
			while (down--)
			{
				write(1, "rrb\n", 4);
				exec("rrb", a, b);
			}
		}
	}
	write(1, "pa\n", 3);
	exec("pa", a, b);
	count[0]++;
	count[1]--;
}

void	place_first_nbr(t_stack **a, t_stack **b, int nbr, int count)
{
	int	i;

	if (!check_order(*a, *b))
	{
		i = find(nbr, *a, *b);
		if (i <= ((count + 1) / 2))
		{
			while (i > 1)
			{
				write(1, "ra\n", 3);
				exec("ra", a, b);
				i--;
			}
		}
		else
		{
			while (count + 1 - i)
			{
				write(1, "rra\n", 4);
				exec("rra", a, b);
				i++;
			}
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
	// if (!check_order(*a, *b))
	// 	swap_heads(a, b, count);
	i = 1;
	while (!check_order(*a, *b))
	{
		j = find(vector[i], *a, *b);
		if (j > 0)
			move_up_a(a, b, count, j);
		else
			move_up_b(a, b, count, -j);
		i++;
//		swap_heads(a, b, count);
	}
}
