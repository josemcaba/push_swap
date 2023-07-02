/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 21:32:02 by jocaball          #+#    #+#             */
/*   Updated: 2023/06/09 23:44:10 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3_nbr(t_stack **a, t_stack **b)
{
	int		max;
	t_stack	*a_tmp;

	a_tmp = *a;
	max = a_tmp->nbr;
	while (a_tmp)
	{
		if (a_tmp->nbr > max)
			max = a_tmp->nbr;
		a_tmp = a_tmp->next;
	}
	if ((*a)->nbr == max)
		exec("ra\n", a, b, VER);
	if ((*a)->next->nbr == max)
		exec("rra\n", a, b, VER);
	if ((*a)->nbr > (*a)->next->nbr)
		exec("sa\n", a, b, VER);
}

void	set_up(t_stack **a, t_stack **b, int *count)
{
	if (!check_order(*a, *b) && (count[0] == 2))
		exec("sa\n", a, b, VER);

	while (!check_order(*a, *b) && (count[0] > 3))
	{
		exec("pb\n", a, b, VER);
		count[0]--;
		count[1]++;
	}
	sort_3_nbr(a, b);
}