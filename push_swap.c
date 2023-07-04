/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 21:35:20 by jocaball          #+#    #+#             */
/*   Updated: 2023/07/04 13:53:24 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*nodes;
	t_stack	*a;
	t_stack	*b;
	int		count[2];

	if (argc == 1)
		return (0);
	parse_argv(&argc, &argv);
	nodes = load_nodes(argc, argv);
	a = nodes;
	b = NULL;
	count[0] = argc - 1;
	count[1] = 0;
	sort(&a, &b, count);
	free(nodes);
	return (0);
}
