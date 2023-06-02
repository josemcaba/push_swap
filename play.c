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

static void	exec(char *order, t_stack **a, t_stack **b)
{
	if (!ft_strncmp("sa\n", order, ft_strlen(order)))
		swap(a);
	if (!ft_strncmp("sb\n", order, ft_strlen(order)))
		swap(b);
	if (!ft_strncmp("ss\n", order, ft_strlen(order)))
		dswap(a, b);
	if (!ft_strncmp("pa\n", order, ft_strlen(order)))
		push(a, b);
	if (!ft_strncmp("pb\n", order, ft_strlen(order)))
		push(b, a);
	if (!ft_strncmp("ra\n", order, ft_strlen(order)))
		rotate(a);
	if (!ft_strncmp("rb\n", order, ft_strlen(order)))
		rotate(b);
	if (!ft_strncmp("rr\n", order, ft_strlen(order)))
		drotate(a, b);
	if (!ft_strncmp("rra\n", order, ft_strlen(order)))
		reverse(a);
	if (!ft_strncmp("rrb\n", order, ft_strlen(order)))
		reverse(b);
	if (!ft_strncmp("rrr\n", order, ft_strlen(order)))
		dreverse(a, b);
}


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
