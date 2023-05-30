/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_rot_rev.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 21:45:48 by jocaball          #+#    #+#             */
/*   Updated: 2023/05/30 01:58:29 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **stack, t_stack **last)
{
	if (!(*stack))
		return ;
	if ((*stack)->next == NULL)
		return ;
	(*last)->next = *stack;
	*stack = (*stack)->next;
	*last = (*last)->next;
	(*last)->next = NULL;
}

void	drotate(t_stack **stack_a, t_stack **stack_b, t_stack **last_a, t_stack **last_b)
{
	rotate(stack_a, last_a);
	rotate(stack_b, last_b);
}

void	reverse(t_stack **stack, t_stack **last)
{
	t_stack	*tn;

	if (!(*stack))
		return ;
	if ((*stack)->next == NULL)
		return ;
	tn = *last;
	(*last)->next = *stack;
	*last = NULL;
	tn++;
	tn--;


	*stack = (*stack)->next;
	*last = (*last)->next;
	(*last)->next = NULL;
}

void	dreverse(t_stack **stack_a, t_stack **stack_b, t_stack **last_a, t_stack **last_b)
{
	reverse(stack_a, last_a);
	reverse(stack_b, last_b);
}
