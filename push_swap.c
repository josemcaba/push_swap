/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 21:35:20 by jocaball          #+#    #+#             */
/*   Updated: 2023/07/04 16:04:27 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*nodes;
	t_stack	*a;
	t_stack	*b;
	int		count[2];
	int		flag_str_argv;

	if (argc == 1)
		return (0);
	flag_str_argv = parse_argv(&argc, &argv);
	nodes = load_nodes(argc, argv);
	if (flag_str_argv)
		free_argv(argv);
	a = nodes;
	b = NULL;
	count[0] = argc - 1;
	count[1] = 0;
	if (!check_order(a, b))
		sort(&a, &b, count);
	free(nodes);
	return (0);
}
