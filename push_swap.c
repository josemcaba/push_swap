/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 21:35:20 by jocaball          #+#    #+#             */
/*   Updated: 2023/05/31 00:41:50 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*load_nodes(int argc, char *argv[], t_stack *a)
{
	t_node	*nodes;
	int		i;

	nodes = malloc((argc - 1) * sizeof(t_node));
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
	a->last = &(nodes[i - 1]);
	a->blast = &(nodes[i - 2]);
	return (nodes);
}

int	main(int argc, char *argv[])
{
	t_node	*nodes;
	t_stack	a;
	t_stack	b;

	parse_argv(argc, &(*argv));
	nodes = load_nodes(argc, &(*argv), &a);
	a.stack = nodes;
	b.stack = NULL;
	play(&a, &b);
	free(nodes);
	return (0);
}
