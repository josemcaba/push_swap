/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 21:35:20 by jocaball          #+#    #+#             */
/*   Updated: 2023/06/02 19:40:46 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*load_nodes(int argc, char *argv[])
{
	t_stack	*nodes;
	int		i;

	nodes = malloc((argc - 1) * sizeof(t_stack));
	if (!nodes)
		exit (0);
	i = 0;
	while (i <= (argc - 2))
	{
		nodes[i].nbr = ft_atoi(argv[i + 1]);
		if (i == (argc - 2))
			nodes[i].next = NULL;
		else
			nodes[i].next = &nodes[i + 1];
		i++;
	}
	return (nodes);
}

int	check(t_stack **a, t_stack **b, int count)
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
	if (check(&a, &b, argc - 1))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free(nodes);
	return (0);
}
