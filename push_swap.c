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

static int	*sort_vector(t_stack *nodes, int count)
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

	if (argc == 1)
		return (0);
	parse_argv(argc, argv);
	nodes = load_nodes(argc, argv);
	vector = sort_vector(nodes, argc - 1);
	a = nodes;
	b = NULL;
	sort(&a, &b, vector, argc - 1);
	free(vector);
	free(nodes);
	return (0);
}
