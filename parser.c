/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 21:32:02 by jocaball          #+#    #+#             */
/*   Updated: 2023/06/09 23:44:10 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_int_nbrs(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{	
		j = 0;
		if ((argv[i][j] == '+') || (argv[i][j] == '-'))
			j++;
		if (!argv[i][j])
			return (1);
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
				return (1);
			j++;
		}
		if (ft_atoi(argv[i]) != ft_atol(argv[i]))
			return (1);
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

char	**split_argv(int *argc, char **argv)
{
	char	*new_argv;

	new_argv = ft_strjoin("push_swap ", argv[1]);
	if (!new_argv)
		return (NULL);
	argv = ft_split(new_argv, ' ');
	if (!argv)
	{
		free(new_argv);
		return (NULL);
	}
	free(new_argv);
	*argc = 0;
	while (argv[*argc])
		(*argc)++;
	return (argv);
}

void	free_argv(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}

int	parse_argv(int *argc, char ***argv)
{
	int	err;
	int	flag_str_argv;

	flag_str_argv = 0;
	if (*argc == 2)
	{
		flag_str_argv = 1;
		*argv = split_argv(argc, *argv);
		if (!(*argv))
			exit (0);
	}
	err = check_int_nbrs(*argc, *argv);
	if (!err)
		err = check_dup(*argc, *argv);
	if (err)
	{
		if (flag_str_argv)
			free_argv(*argv);
		write(2, "Error\n", 6);
		exit (0);
	}
	return (flag_str_argv);
}
