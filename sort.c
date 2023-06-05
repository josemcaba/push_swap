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

	(void)b;
	j = 0;
	while (a)
	{
		if (a->nbr == nbr)
			break ;
		a = a->next;
		j++;
	}
	return (j);
}

void	move_up_a(t_stack **a, t_stack **b, int	count)
{
	while (count > 0)
	{
		write(1, "rra\n", 4);			
		exec("rra", a, b);
		if (count > 1)
		{
			write(1, "pb\n", 3);
			exec("pb", a, b);
		}
		count--;	
	}
}

void	place_first_nbr(t_stack **a, t_stack **b, int nbr)
{
	int	count[2];
	int i;

	check_order(*a, *b, count);
	i = find(nbr, *a, *b);
	if (i <= (count[0] / 2))
	{
		while ((*a)->nbr != nbr)
		{
			write(1, "ra\n", 3);
			exec("ra", a, b);
		}
	}
	else
	{
		while (count[0] - i)
		{
			write(1, "rra\n", 4);			
			exec("rra", a, b);
			i++;
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
		while (count[0] - j)
		{
			write(1, "rra\n", 4);			
			exec("rra", a, b);
			if (((*a)->next->nbr == vector[i - 1]) && (i > 0))
			{
				write(1, "pb\n", 3);
				exec("pb", a, b);
			}
			j++;
		}
		i++;		
	}
}
