/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 21:35:20 by jocaball          #+#    #+#             */
/*   Updated: 2023/07/05 16:41:05 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_argv(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}

t_stack	*load_nodes(int argc, char *argv[])
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
