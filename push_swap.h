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

typedef struct s_stack
{
	int		**layer;
	ssize_t	i;
}	t_stack;

void	parse_argv(int argc, char **argv);
void	play(t_stack *stack_a, t_stack *stack_b);
void	push(t_stack *stack_dst, t_stack *stack_org);
void	swap(t_stack *stack);
void	dswap(t_stack *stack_a, t_stack *stack_b);
void	rotate(t_stack *stack);
void	drotate(t_stack *stack_a, t_stack *stack_b);
void	reverse(t_stack *stack);
void	dreverse(t_stack *stack_a, t_stack *stack_b);

#endif
