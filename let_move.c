/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   let_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 17:26:48 by jocaball          #+#    #+#             */
/*   Updated: 2023/07/04 17:29:33 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	let_move_ab(t_stack **a, t_stack **b, int *move)
{
	while (((move[0]) * move[1]) > 0)
	{
		if (move[0] > 0)
		{
			exec("rr\n", a, b, VER);
			move[0]--;
			move[1]--;
		}
		else
		{
			exec("rrr\n", a, b, VER);
			move[0]++;
			move[1]++;
		}
	}
}

void	let_move_a(t_stack **a, t_stack **b, int *move)
{
	while (move[0])
	{
		if (move[0] > 0)
		{
			exec("ra\n", a, b, VER);
			move[0]--;
		}
		else
		{
			exec("rra\n", a, b, VER);
			move[0]++;
		}
	}
}

void	let_move_b(t_stack **a, t_stack **b, int *move)
{
	while (move[1])
	{
		if (move[1] > 0)
		{
			exec("rb\n", a, b, VER);
			move[1]--;
		}
		else
		{
			exec("rrb\n", a, b, VER);
			move[1]++;
		}
	}
}

void	let_move(t_stack **a, t_stack **b, int *move)
{
	let_move_ab(a, b, move);
	let_move_a(a, b, move);
	let_move_b(a, b, move);
	exec("pa\n", a, b, VER);
}
