/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 21:35:20 by jocaball          #+#    #+#             */
/*   Updated: 2023/06/09 20:08:56 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	steps_nbr_to_top(int count, int pos)
{
	int	up;
	int	down;

	if (pos < 0)
		pos = -pos;
	up = pos - 1;
	down = count - pos + 1;
	if (up <= down)
		return (up);
	else
		return (-down);
}

int	find(int nbr, t_stack *a, t_stack *b)
{
	int	j;

	j = 0;
	while (a)
	{
		j++;
		if (a->nbr == nbr)
			return (j);
		a = a->next;
	}
	j = 0;
	while (b)
	{
		j++;
		if (b->nbr == nbr)
			return (-j);
		b = b->next;
	}
	return (0);
}

int	find_b_hole(int nbr, t_stack *b)
{
	int	min;
	int	max;
	int prev;
	int	next;
	t_stack *backup;

	backup = b;
	min = nbr;
	max = nbr;
	while (b)
	{
		if (b->nbr < min)
			min = b->nbr;
		if (b->nbr > max)
			max = b->nbr;
		b = b->next;
	}
	b = backup;
	prev = min;
	next = max;
	while (b)
	{
		if ((prev < b->nbr) && (b->nbr < nbr))
			prev = b->nbr;
		if ((nbr < b->nbr) && (b->nbr < next))
			next = b->nbr;
		b = b->next;
	}
	if (prev == nbr)
		return(max);
	return (prev);
}

void prepare_b(t_stack **a, t_stack **b, int count)
{
	int	pos;
	int	steps;

	if (count <= 1)
		return ;
	pos = find(find_b_hole((*a)->nbr, *b), *a, *b);
	steps = steps_nbr_to_top(count, pos);
	while (steps)
	{
		if (steps > 0)
		{
			exec("rb\n", a, b, VER);	
			steps--;
		}
		else
		{
			exec("rrb\n", a, b, VER);
			steps++;			
		}
	}
}

void	swap_heads(t_stack **a, t_stack **b, int *count)
{
	if ((count[0] > 1) && (count[1] > 1))
	{	
		if (((*a)->nbr > (*a)->next->nbr) && ((*b)->nbr < (*b)->next->nbr))
			exec("ss\n", a, b, VER);
	}
	else if ((count[0] > 1) && ((*a)->nbr > (*a)->next->nbr))
		exec("sa\n", a, b, VER);
	else if ((count[1] > 1) && ((*b)->nbr > (*b)->next->nbr))
		exec("sb\n", a, b, VER);
}

// void	insert_b(t_stack **a, t_stack **b, int idx, int *count)
// {
// 	int	steps;

// 	steps = steps_nbr_to_top(count[1], idx);
// 	if (steps > 0)
// 	{
// 		idx = 0;
// 		while (idx++ < steps)
// 			exec("rrb\n", a, b, VER);
// 		exec("pb\n", a, b, VER);
// 		idx = 0;
// 		while (idx++ < (steps + 1))
// 			exec("rb\n", a, b, VER);
// 	}
// 	else
// 	{
// 		while (idx--)
// 			exec("rb\n", a, b, VER);
// 		exec("pb\n", a, b, VER);
// 	}
// }

// void	sort_push_b(t_stack **a, t_stack **b, int *count)
// {
// 	t_stack	*tmp_b;
// 	int		i;

// 	i = 0;
// 	tmp_b = *b;
// 	while (tmp_b && tmp_b->nbr > (*a)->nbr)
// 	{
// 		i++;
// 		tmp_b = tmp_b->next;
// 	}
// 	if (i == count[1])
// 	{
// 		exec("pb\n", a, b, VER);
// 		exec("rb\n", a, b, VER);
// 	}
// 	else
// 		insert_b(a, b, i, count);
// }

// void	sort_push_b(t_stack **a, t_stack **b, int *count)
// {
// 	t_stack	*tmp_b;
// 	int		i;
// 	int		steps;

// 	tmp_b = *b;
// 	// if ((count[1] == 2) && ((tmp_b->nbr - 1) > tmp_b->next->nbr))
// 	// {
// 	// 	exec("rrb\n", a, b, VER);
// 	// 	exec("pb\n", a, b, VER);
// 	// }
// 	// else
// 	// {
// 		i = 1;
// 		while (tmp_b->next && (tmp_b->nbr > tmp_b->next->nbr))
// 		{
// 			i++;
// 			if ((*a)->nbr < tmp_b->nbr)
// 				break ;
// 			tmp_b = tmp_b->next;
// 		}
// 		steps = steps_nbr_to_top(count[1], i);
// 		while (steps)
// 		{
// 			if (steps > 0)
// 			{
// 				exec("rb\n", a, b, VER);
// 				steps--;
// 			}
// 			else
// 			{
// 				exec("rrb\n", a, b, VER);
// 				steps++;
// 			}
// 		}
// 		exec("pb\n", a, b, VER);
// 	// }
// }

void	move_to_top_a(t_stack **a, t_stack **b, int *count, int pos)
{
	int	i;

	if ((pos == 2) && (count[1] == 0))
		exec("sa\n", a, b, VER);
	else
	{
		i = count[0];
		while ((i - pos) >= 0)
		{
			// if ((count[1] > 1) && ((*b)->nbr < get_blast(*b)->next->nbr))
			// 	exec("rrr\n", a, b, VER);
			// else
			exec("rra\n", a, b, VER);
			if ((i - pos) > 0)
			{
				// if (count[1] < 1)
				// {
					prepare_b(a, b, count[1]);
					exec("pb\n", a, b, VER);
					count[0]--;
					count[1]++;
					// if ((count[1] > 1) && ((*b)->nbr < (*b)->next->nbr))
					// 	exec("sb\n", a, b, VER);
				// }
				// if (count[1] > 1)
				//	sort_push_b(a, b, count);
			}
			i--;
		}
	}
}

void	move_up_b(t_stack **a, t_stack **b, int *count, int pos)
{
	int	steps;

	if (pos > 1)
	{
		steps = steps_nbr_to_top(count[1], pos);
		while (steps)
		{
			if (steps > 0)
			{
				exec("rb\n", a, b, VER);
				steps--;
			}
			else
			{
					exec("rrb\n", a, b, VER);
				steps++;
			}
		}
	}
	exec("pa\n", a, b, VER);
	count[0]++;
	count[1]--;
}






void	place_first_nbr(t_stack **a, t_stack **b, int nbr, int *count)
{
	int	pos;
	int	steps;

	if (check_order(*a, *b))
		return ;
	pos = find(nbr, *a, *b);
	steps = steps_nbr_to_top(count[0], pos);
	while (steps)
	{
		if (steps > 0)
		{
			// prepare_b(a, b, count[1]);
			// exec("pb\n", a, b, VER);
			// if ((count[1] == 2) && ((*b)->nbr < (*b)->next->nbr))
			// 	exec("sb\n", a, b, VER);
			// count[0]--;
			// count[1]++;
			exec("ra\n", a, b, VER);
			steps--;			
		}
		else
		{
			exec("rra\n", a, b, VER);
			steps++;			
		}
	}
}
















void	ciclo(t_stack **a, t_stack **b, int *vector, int *count)
{
	int	i;
	int pivot1, pivot2, pivot3;
	int quantity;
	int	pos;
	int	steps;

	quantity = count[0];

	pivot1 = vector[(quantity / 2)];
    ft_printf("pivot1 = %d\n", pivot1);
	i = 0;
	while (i < (quantity / 2))
	{
		if ((*a)->nbr >= pivot1)
			exec("ra\n", a, b, VER);
		else
		{
			exec("pb\n", a, b, VER);
			count[1]++;
			i++;
		}
	}

	pos = find(pivot1, *a, *b);

		steps = steps_nbr_to_top(count[0], pos);
		while (steps)
		{
			if (steps > 0)
			{
				exec("ra\n", a, b, VER);
				steps--;
			}
			else
			{
					exec("rra\n", a, b, VER);
				steps++;
			}
		}
	
	pivot2 = vector[(quantity / 4)];
	ft_printf("pivot2 = %d\n", pivot2);
	// ft_printf("qty/4 = %d\n", quantity / 4);
	// ft_printf("qty%%2 = %d\n", quantity % 2);
	// ft_printf("pivot = %d\n", quantity / 4 + quantity % 2);
	i = 0;
	while (i < (quantity / 4))
	{
		// ft_printf("1");
		if ((*b)->nbr <= pivot2)
		{
			// ft_printf("2");
			exec("rb\n", a, b, VER);
		}
		else
		{
			// ft_printf("3");
			exec("pa\n", a, b, VER);
			count[1]--;
			i++;
		}
	}
		pos = find(pivot2, *a, *b);

		steps = steps_nbr_to_top(count[1], pos);
		while (steps)
		{
			if (steps > 0)
			{
				exec("rb\n", a, b, VER);
				steps--;
			}
			else
			{
					exec("rrb\n", a, b, VER);
				steps++;
			}
		}
	while (*b)
		exec("pa\n", a, b, VER);
	count[1] = 0;

	while (get_blast(*a)->next->nbr != pivot1)
	{
		exec("rra\n", a, b, VER);
		exec("pb\n", a, b, VER);
		count[1]++;
	}
/*********************************/
	pivot3 = vector[quantity - (quantity / 4) - 1];
	ft_printf("pivot3 = %d\n", pivot3);
	// ft_printf("qty/4 = %d\n", quantity / 4);
	// ft_printf("qty%%2 = %d\n", quantity % 2);
	// ft_printf("pivot = %d\n", quantity / 4 + quantity % 2);
	i = 0;
	while (i < (quantity / 4))
	{
		// ft_printf("1");
		if ((*b)->nbr <= pivot3)
		{
			// ft_printf("2");
			exec("rb\n", a, b, VER);
		}
		else
		{
			// ft_printf("3");
			exec("pa\n", a, b, VER);
			count[1]--;
			i++;
		}
	}
		pos = find(pivot3, *a, *b);

		steps = steps_nbr_to_top(count[1], pos);
		while (steps)
		{
			if (steps > 0)
			{
				exec("rb\n", a, b, VER);
				steps--;
			}
			else
			{
					exec("rrb\n", a, b, VER);
				steps++;
			}
		}
	while (*b)
		exec("pa\n", a, b, VER);
	count[1] = 0;
/*****************************/
	while ((*a)->nbr > pivot1)
		exec("ra\n", a, b, VER);

}

void	sort(t_stack **a, t_stack **b, int *vector, int *count)
{
	ciclo(a, b, vector, count);
}