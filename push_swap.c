/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 21:35:20 by jocaball          #+#    #+#             */
/*   Updated: 2023/06/08 01:14:21 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	load_vector(int **vector, t_stack *nodes)
{
	int	i;

	i = 0;
	while (nodes)
	{
		(*vector)[i] = nodes->nbr;
		nodes = nodes->next;
		i++;
	}
}

static int	*sort_vector(t_stack *nodes, int count)
{
	int	*vector;
	int	i;
	int	tmp;

	vector = malloc(count * sizeof(int));
	if (!vector)
		return (NULL);
	load_vector(&vector, nodes);
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
	int		count[2];

	// argc = 11;
	// argv[1] = "65";
	// argv[2] = "59";
	// argv[3] = "68";
	// argv[4] = "23";
	// argv[5] = "60";
	// argv[6] = "56";
	// argv[7] = "48";
	// argv[8] = "90";
	// argv[9] = "27";
	// argv[10] = "98";

//	./push_swap 55 6 47 23 41 61 37 28 58 66

	if (argc == 1)
		return (0);
	parse_argv(argc, argv);
	nodes = load_nodes(argc, argv);
	vector = sort_vector(nodes, argc - 1);
	if (vector)
	{
		a = nodes;
		b = NULL;
		count[0] = argc - 1;
		count[1] = 0;
		sort(&a, &b, vector, count);
		free(vector);
	}
	free(nodes);
	return (0);
}
