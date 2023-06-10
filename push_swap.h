/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 21:42:45 by jocaball          #+#    #+#             */
/*   Updated: 2023/06/09 23:41:18 by jocaball         ###   ########.fr       */
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

# define VER 1

# ifndef VER_CHECK
#  define VER_CHECK 0
# endif

int		parse_argv(int *argc, char ***argv);
t_stack	*load_nodes(int argc, char **argv);
int		exec(char *order, t_stack **a, t_stack **b, int ver);
void	push(t_stack **dst, t_stack **src, char *order, int ver);
void	swap(t_stack **p, char *order, int ver);
void	dswap(t_stack **a, t_stack **b, int ver);
void	rotate(t_stack **p, char *order, int ver);
void	drotate(t_stack **a, t_stack **b, int ver);
void	reverse(t_stack **p, char *order, int ver);
void	dreverse(t_stack **a, t_stack **b, int ver);
int		check_order(t_stack *a, t_stack *b);
void	sort(t_stack **a, t_stack **b, int *vector, int *count);
t_stack	*get_blast(t_stack *p);
int		steps_nbr(int count, int pos);
void	free_argv(char **argv);

#endif
