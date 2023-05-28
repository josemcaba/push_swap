#include "push_swap.h"

void	sa(t_stack	*stack_a)
{
	int	*tmp;

	if (stack_a->i < 1)
		return ;
	tmp = stack_a->layer[stack_a->i];
	stack_a->layer[stack_a->i] = stack_a->layer[stack_a->i - 1];
	stack_a->layer[stack_a->i - 1] = tmp;
}

void	sb(t_stack	*stack_b)
{
	int	*tmp;

	if (stack_b->i < 1)
		return ;
	tmp = stack_b->layer[stack_b->i];
	stack_b->layer[stack_b->i] = stack_b->layer[stack_b->i - 1];
	stack_b->layer[stack_b->i - 1] = tmp;
}

void	ss(t_stack	*stack_a, t_stack *stack_b)
{
	sa(stack_a);
	sb(stack_b);
}
