/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 19:57:30 by jocaball          #+#    #+#             */
/*   Updated: 2023/06/08 20:50:58 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	exec(char *order, t_stack **a, t_stack **b, int ver)
{
	if (!ft_strncmp("sa\n", order, 3))
		swap(a, order, ver);
	else if (!ft_strncmp("sb\n", order, 3))
		swap(b, order, ver);
	else if (!ft_strncmp("ss\n", order, 3))
		dswap(a, b, ver);
	else if (!ft_strncmp("pa\n", order, 3))
		push(a, b, order, ver);
	else if (!ft_strncmp("pb\n", order, 3))
		push(b, a, order, ver);
	else if (!ft_strncmp("ra\n", order, 3))
		rotate(a, order, ver);
	else if (!ft_strncmp("rb\n", order, 3))
		rotate(b, order, ver);
	else if (!ft_strncmp("rr\n", order, 3))
		drotate(a, b, ver);
	else if (!ft_strncmp("rra\n", order, 4))
		reverse(a, order, ver);
	else if (!ft_strncmp("rrb\n", order, 4))
		reverse(b, order, ver);
	else if (!ft_strncmp("rrr\n", order, 4))
		dreverse(a, b, ver);
	else
		return (1);
	return (0);
}
