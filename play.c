/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
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
	int	i;

	(void)b;
	i = 0;
	while (a)
	{
		if (a->nbr == nbr)
			break ;
		a = a->next;
		i++;
	}
	return (i);
}

void	sort(t_stack **a, t_stack **b, int *vector, int count)
{
	int	i;

	(void)count;
	i = find(vector[0], *a, *b);
	while ((i >= (count / 2)) && (i <= (count - 2)))
	{
		exec("rra", a, b);
		write(1, "rra\n", 4);
		i++;
	}
}
