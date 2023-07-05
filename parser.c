/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 21:32:02 by jocaball          #+#    #+#             */
/*   Updated: 2023/07/05 16:39:15 by jocaball         ###   ########.fr       */
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

char	*join_new_vals(char **new_vals, char *cmd_line)
{
	int		j;
	char	*tmp_line;

	j = 0;
	while (new_vals[j])
	{
		tmp_line = ft_strjoin(cmd_line, new_vals[j]);
		if (!tmp_line)
			exit(0);
		free(cmd_line);
		free(new_vals[j]);
		cmd_line = ft_strjoin(tmp_line, " ");
		if (!cmd_line)
			exit(0);
		free(tmp_line);
		j++;
	}
	return (cmd_line);
}

void	split_argv(int argc, char ***argv)
{
	char	*cmd_line;
	int		i;
	char	**new_vals;

	cmd_line = ft_strjoin("push_swap", " ");
	if (!cmd_line)
		exit(0);
	i = 0;
	while (++i < argc)
	{
		new_vals = ft_split((*argv)[i], ' ');
		if (!new_vals)
			exit(0);
		cmd_line = join_new_vals(new_vals, cmd_line);
		free(new_vals);
	}
	*argv = ft_split(cmd_line, ' ');
	if (!(*argv))
		exit(0);
	free(cmd_line);
}

void	parse_argv(int *argc, char ***argv)
{
	int		err;

	split_argv(*argc, argv);
	*argc = 0;
	while ((*argv)[*argc])
		(*argc)++;
	err = check_int_nbrs(*argc, *argv);
	if (!err)
		err = check_dup(*argc, *argv);
	if (err)
	{
		free_argv(*argv);
		write(2, "Error\n", 6);
		exit (0);
	}
}
