#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"

typedef struct s_stack
{
	int		**layer;
	ssize_t	i;
}	t_stack;

void	parse_argv(int argc, char **argv);
void	push(t_stack *stack_dst, t_stack *stack_org);
void	swap(t_stack *stack);
void	dswap(t_stack *stack_a, t_stack *stack_b);
void	rotate(t_stack *stack);
void	drotate(t_stack *stack_a, t_stack *stack_b);
void	reverse(t_stack *stack);
void	dreverse(t_stack *stack_a, t_stack *stack_b);

#endif
