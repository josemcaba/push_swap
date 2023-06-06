/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 21:35:20 by jocaball          #+#    #+#             */
/*   Updated: 2023/06/02 22:35:11 by jocaball         ###   ########.fr       */
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
			return (j) ;
		a = a->next;
	}
	j = 0;
	while (b)
	{
		j++;
		if (b->nbr == nbr)
			return (-j) ;
		b = b->next;
	}
	return (0);
}

void	move_up_a(t_stack **a, t_stack **b, int	count, int pos)
{
	while ((count - pos) >= 0)
	{
		write(1, "rra\n", 4);			
		exec("rra", a, b);
		if ((count - pos) > 0)
		{
			write(1, "pb\n", 3);
			exec("pb", a, b);
			if ((*b)->next != NULL)
				if (get_blast(*b)->next->nbr > (*b)->nbr)
				{
					write(1, "rb\n", 3);
					exec("rb", a, b);
				}
		}
		count--;	
	}
}

void	move_up_b(t_stack **a, t_stack **b, int	count, int pos)
{
	if (pos > 1)
	{
		if (pos <= (count / 2))
			while (pos <= (count / 2))
			{
				write(1, "rb\n", 3);
				exec("rb", a, b);
				pos++;
			}
		else
			while (count + 1 - pos)
			{
				write(1, "rrb\n", 4);			
				exec("rrb", a, b);
				pos++;
			}
	}
	write(1, "pa\n", 3);
	exec("pa", a, b);
}

void	place_first_nbr(t_stack **a, t_stack **b, int nbr)
{
	int	count[2];
	int i;

	if (!check_order(*a, *b, count))
	{
		i = find(nbr, *a, *b);
		if (i <= ((count[0] + 1) / 2))
		{
			while ((*a)->nbr != nbr)
			{
				write(1, "ra\n", 3);
				exec("ra", a, b);
			}
		}
		else
		{
			while (count[0] + 1 - i)
			{
				write(1, "rra\n", 4);			
				exec("rra", a, b);
				i++;
			}
		}
	}
}

void	sort(t_stack **a, t_stack **b, int *vector)
{
	int	i;
	int	j;
	int	count[2];

	place_first_nbr(a, b, vector[0]);
	i = 1;
	while (!check_order(*a, *b, count))
	{
		j = find(vector[i], *a, *b);
		if (j > 0)
			move_up_a(a, b, count[0], j);
		else
			move_up_b(a, b, count[1], -j);
		i++;		
	}
}
