/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 21:35:20 by jocaball          #+#    #+#             */
/*   Updated: 2023/06/02 19:40:46 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ver(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*na;
	t_stack	*nb;

	na = stack_a;
	nb = stack_b;
	while (na || nb)
	{
		if (na)
		{
			ft_printf("%11i", na->nbr);
			na = na->next;
			if (!nb)
				ft_printf("\n");
		}
		else
			ft_printf("%11s", "");
		if (nb)
		{
			ft_printf("%14i\n", nb->nbr);
			nb = nb->next;
		}
	}
	ft_printf("-----a-----   -----b-----\n");
}

static void	play(t_stack **a, t_stack **b)
{
	char	*order;

	if (VER)
		ver(*a, *b);
	order = get_next_line(0);
	while (order && order[0] != 'q')
	{
		exec(order, a, b);
		if (VER)
		{
			ft_printf("%s", order);
			ver(*a, *b);
		}
		order = get_next_line(0);
	}
	free(order);
}

static int	final_check(t_stack **a, t_stack **b, int count)
{
	int	i;

	if (*b)
		return (0);
	i = 1;
	while ((*a)->next)
	{
		if ((*a)->nbr > (*a)->next->nbr)
			return (0);
		*a = (*a)->next;
		i++;
	}
	if (i != count)
		return (0);
	return (1);
}

int	main(int argc, char *argv[])
{
	t_stack	*nodes;
	t_stack	*a;
	t_stack	*b;

	if (argc == 1)
		return (0);
	parse_argv(argc, argv);
	nodes = load_nodes(argc, argv);
	a = nodes;
	b = NULL;
	play(&a, &b);
	if (final_check(&a, &b, argc - 1))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free(nodes);
	return (0);
}
