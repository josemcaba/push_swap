/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_order.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 21:35:20 by jocaball          #+#    #+#             */
/*   Updated: 2023/06/02 19:40:46 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_order(t_stack *a, t_stack *b, int *count)
{
	int	order;
	
	order = 1;
	count[0] = 1;
	while (a->next)
	{
		if (a->nbr > a->next->nbr)
			order = 0;
		a = a->next;
		count[0]++;
	}
	count[1] = 0;
	if (b)
	{
		order = 0;
		count[1] = 1;
		while (b->next)
			count[1]++;
	}
	return (order);
}
