/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_median.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 19:00:11 by jocaball          #+#    #+#             */
/*   Updated: 2023/07/04 20:16:51 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	load_array(int *array, t_stack *a, int count)
{
	while (--count >= 0)
	{
		array[count] = a->nbr;
		a = a->next;
	}
}

void	swap_nbrs(int *a, int *b)
{
	int	c;

	c = *a;
	*a = *b;
	*b = c;
}

int	find_median(t_stack *a, int count)
{
	int	*array;
	int	i;
	int	j;
	int	median;

	array = (int *)malloc(count * sizeof(int));
	if (!array)
		exit(0);
	load_array(array, a, count);
	j = count - 1;
	while (j > 0)
	{
		i = 0;
		while (i < j)
		{
			if (array[i] > array[j])
				swap_nbrs(&array[i], &array[j]);
			i++;
		}
		j--;
	}
	median = array[count / 2];
	free(array);
	return (median);
}
