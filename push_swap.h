#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"

typedef struct s_stack
{
	int		**layer;
	size_t	i;
}	t_stack;

void	parse_argv(int argc, char **argv);
void	sa(t_stack	*stack_a);
void	sb(t_stack	*stack_b);
void	ss(t_stack	*stack_a, t_stack *stack_b);

#endif
