#include "push_swap.h"

void	rotate(t_stack *stack)
{
	int	first;
	int	j;

	if (stack->i < 1)
		return ;
	first = *stack->layer[stack->i];
	j = stack->i;
	while (j > 0)
	{
		*stack->layer[j] = *stack->layer[j - 1];
		j--;
	}
	*stack->layer[j] = first;
}

void	drotate(t_stack *stack_a, t_stack *stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
}

void	reverse(t_stack *stack)
{
	int	last;
	int	j;

	if (stack->i < 1)
		return ;
	last = *stack->layer[0];
	j = 0;
	while (j < stack->i)
	{
		*stack->layer[j] = *stack->layer[j + 1];
		j++;
	}
	*stack->layer[j] = last;
}

void	dreverse(t_stack *stack_a, t_stack *stack_b)
{
	reverse(stack_a);
	reverse(stack_b);
}
