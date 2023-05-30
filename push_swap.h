/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 21:42:45 by jocaball          #+#    #+#             */
/*   Updated: 2023/05/30 02:03:38 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"

typedef struct s_node
{
	int				nbr;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*stack;
	t_node	*last;
	t_node	*blast;                                                                                                                                                                                                                      
}	t_stack;

void	parse_argv(int argc, char **argv);
void	play(t_stack *a, t_stack *b);
void	push(t_stack *dst, t_stack *src);
void	swap(t_stack *stack);
void	dswap(t_stack *stack_a, t_stack *stack_b);
void	rotate(t_stack **stack, t_stack **last);
void	drotate(t_stack **stack_a, t_stack **stack_b, t_stack **last_a, t_stack **last_b);
void	reverse(t_stack **stack, t_stack **last);
void	dreverse(t_stack **stack_a, t_stack **stack_b, t_stack **last_a, t_stack **last_b);

#endif
