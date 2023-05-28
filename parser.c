#include "push_swap.h"

// The ft_atol() function converts the initial portion of the string pointed to
// by str to long representation.

long long	ft_atol(const char *str)
{
	long long	sign;
	long long	number;

	while (((*str >= '\t') && (*str <= '\r')) || (*str == ' '))
		str++;
	sign = 1;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	number = 0;
	while ((*str >= '0') && (*str <= '9'))
	{
		number = (number * 10) + (*str - '0');
		str++;
	}
	number = sign * number;
	return (number);
}

static int	check_int_nbrs(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{	
		if (ft_atoi(argv[i]) != ft_atol(argv[i]))
			return (1);
		if (ft_atoi(argv[i]) == 0)
		{
			j = 0;
			while ((argv[i][j] == '0') && (argv[i][j] != '\0'))
				j++;
			if (argv[i][j] != '\0')
				return (1);
		}
		i++;
	}
	return (0);
}

static int	check_dup(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{	
		j = 1;
		while (j < i)
		{
			if (ft_atoi(argv[j]) == ft_atoi(argv[i]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	parse_argv(int argc, char **argv)
{
	int	err;

	err = check_int_nbrs(argc, &(*argv));
	if (!err)
		err = check_dup(argc, &(*argv));
	if (err)
	{
		ft_printf("Error\n");
		exit (0);
	}
}
