/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 21:42:45 by jocaball          #+#    #+#             */
/*   Updated: 2023/07/04 13:57:03 by jocaball         ###   ########.fr       */
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

# ifndef VER_CHECK
#  define VER_CHECK 1
# endif

# define VER 1
# define NVER 0

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
void	sort(t_stack **a, t_stack **b, int *count);
t_stack	*get_blast(t_stack *p);
int		steps_to_top(int count, int pos);
void	free_argv(char **argv);
int		find_a_hole(int nbr, t_stack *b);
int		get_next_nbr(t_stack *a, t_stack *b, int *count);
int		find_pos_nbr(int nbr, t_stack *a, t_stack *b);
void	find_min_max(int nbr, t_stack *b, int *min, int *max);
void	set_up(t_stack **a, t_stack **b, int *count);
void	move_up_a(t_stack **a, t_stack **b, int *count, int pos);
void	finish(t_stack **a, t_stack **b, int *count);

#endif
