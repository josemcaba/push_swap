/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 21:35:20 by jocaball          #+#    #+#             */
/*   Updated: 2023/06/08 22:23:09 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	show(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*na;
	t_stack	*nb;

	na = stack_a;
	nb = stack_b;
	while (na || nb)
	{
		if (na)
		{
			ft_printf("\033[1;94m%11i", na->nbr);
			na = na->next;
			if (!nb)
				ft_printf("\n");
		}
		else
			ft_printf("%11s", "");
		if (nb)
		{
			ft_printf("\033[0;96m%14i\n", nb->nbr);
			nb = nb->next;
		}
	}
	ft_printf("\033[1;94m-----a-----   \033[0;96m-----b-----\033[0;39m\n");
}

static int	play(t_stack **a, t_stack **b, int ver)
{
	char	*order;
	int		err;

	err = 0;
	if (ver)
		show(*a, *b);
	order = get_next_line(0);
	while (order)
	{
		if (exec(order, a, b, ver))
			err = 1;
		if (ver)
			show(*a, *b);
		order = get_next_line(0);
	}
	free(order);
	return (err);
}

int	main(int argc, char *argv[])
{
	t_stack	*nodes;
	t_stack	*a;
	t_stack	*b;
	int		err;

	if (argc == 1)
		return (0);
	parse_argv(argc, argv);
	nodes = load_nodes(argc, argv);
	a = nodes;
	b = NULL;
	err = play(&a, &b, VER_CHECK);
	if (err)
		write(2, "\033[0;93mError\033[0;39m\n", 6);
	else if (check_order(a, b))
		ft_printf("\033[1;92mOK\033[0;39m\n");
	else
		ft_printf("\033[1;91mKO\033[0;39m\n");
	free(nodes);
	return (0);
}
