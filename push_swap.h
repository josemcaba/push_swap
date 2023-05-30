/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 21:42:45 by jocaball          #+#    #+#             */
/*   Updated: 2023/05/31 01:08:16 by jocaball         ###   ########.fr       */
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
void	swap(t_stack *p);
void	dswap(t_stack *a, t_stack *b);
void	rotate(t_stack *p);
void	drotate(t_stack *a, t_stack *b);
void	reverse(t_stack *p);
void	dreverse(t_stack *a, t_stack *b);

#endif
