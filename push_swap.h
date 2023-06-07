/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 21:42:45 by jocaball          #+#    #+#             */
/*   Updated: 2023/06/07 23:30:17 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"

typedef struct s_stack
{
	int				nbr;
	struct s_stack	*next;
}	t_stack;

# ifndef VER
#  define VER 0
# endif

void	parse_argv(int argc, char **argv);
t_stack	*load_nodes(int argc, char **argv);
void	exec(char *order, t_stack **a, t_stack **b);
void	push(t_stack **dst, t_stack **src);
void	swap(t_stack **p);
void	dswap(t_stack **a, t_stack **b);
void	rotate(t_stack **p);
void	drotate(t_stack **a, t_stack **b);
void	reverse(t_stack **p);
void	dreverse(t_stack **a, t_stack **b);
int		check_order(t_stack *a, t_stack *b);
void	sort(t_stack **a, t_stack **b, int *vector, int *count);
t_stack	*get_blast(t_stack *p);

#endif
