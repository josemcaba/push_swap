#include "push_swap.h"

void	load_stacks(t_stack *stack_a, t_stack *stack_b, int argc, char **argv)
{
	int	i;

	i = 0;
	while (i < (argc - 1))
	{
		stack_b->layer[i] = (int *)malloc(sizeof(int));
		stack_a->layer[i] = (int *)malloc(sizeof(int));
		*stack_a->layer[i] = ft_atoi(argv[argc - 1 - i]);
		stack_a->i = i;
		i++;
	}
}

void	build_stacks(t_stack *stack_a, t_stack *stack_b, int argc)
{
	stack_a->layer = (int **)malloc(sizeof(int *) * (argc - 1));
	if (!stack_a->layer)
		exit(0);
	stack_b->layer = (int **)malloc(sizeof(int *) * (argc - 1));
	if (!stack_b->layer)
	{
		free(stack_a->layer);
		exit(0);
	}
	stack_a->i = -1;
	stack_b->i = -1;	
}

int	main(int argc, char *argv[])
{
	int	i;
	t_stack	stack_a;
	t_stack	stack_b;

	parse_argv(argc, &(*argv));
	build_stacks(&stack_a, &stack_b, argc);
	load_stacks(&stack_a, &stack_b, argc, &(*argv));
	i = stack_a.i;
	while (i >= 0)
	{
		ft_printf("%11i\n", stack_a.layer[i][0]);
		i--;
	}
	ft_printf("-----a-----   -----b-----\n");
	sa(&stack_a);
	i = stack_a.i;
	while (i >= 0)
	{
		ft_printf("%11i\n", stack_a.layer[i][0]);
		i--;
	}
	ft_printf("-----a-----   -----b-----\n");
	free(stack_a.layer);
	free(stack_b.layer);
	return (0);
}
