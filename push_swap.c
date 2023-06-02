/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 21:35:20 by jocaball          #+#    #+#             */
/*   Updated: 2023/06/02 22:16:50 by jocaball         ###   ########.fr       */
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

int	*sort_vector(t_stack *nodes, int count)
{
	int	*vector;
	int	i;
	int	tmp;

	vector = malloc(count * sizeof(int));
	i = 0;
	while (nodes)
	{
		vector[i++] = nodes->nbr;
		nodes = nodes->next;
	}
	i = 0;
	while ((i < count) && (count > 1))
	{
		if (vector[i] < vector[i + 1])
		{
			tmp = vector[i];
			vector[i] = vector[i + 1];
			vector[i + 1] = tmp;
			i = 0;
		}
		else
			i++;
	}
	return (vector);
}

int	main(int argc, char *argv[])
{
	t_stack	*nodes;
	t_stack	*a;
	t_stack	*b;
	int		*vector;

	argc = 6;
	argv[1] = "3";
	argv[2] = "1";
	argv[3] = "4";
	argv[4] = "5";
	argv[5] = "2";
	if (argc == 1)
		return (0);
	parse_argv(argc, argv);
	nodes = load_nodes(argc, argv);
	vector = sort_vector(nodes, argc - 1);
	a = nodes;
	b = NULL;
	sort(&a, &b, vector, argc - 1);
	if (check(&a, &b, argc - 1))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free(vector);
	free(nodes);
	return (0);
}
