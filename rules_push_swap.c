#include "push_swap.h"

void	push(t_stack *stack_dst, t_stack *stack_org)
{
	if (stack_org->i == -1)
		return ;
	*stack_dst->layer[++stack_dst->i] = *stack_org->layer[stack_org->i];
	stack_org->i--;
}

void	swap(t_stack *stack)
{
	int	tmp;

	if (stack->i < 1)
		return ;
	tmp = *stack->layer[stack->i];
	*stack->layer[stack->i] = *stack->layer[stack->i - 1];
	*stack->layer[stack->i - 1] = tmp;
}

void	dswap(t_stack *stack_a, t_stack *stack_b)
{
	swap(stack_a);
	swap(stack_b);
}
