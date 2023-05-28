/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 14:12:47 by jocaball          #+#    #+#             */
/*   Updated: 2023/04/23 20:07:51 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// The ft_atoi() function converts the initial portion of the string pointed to
// by str to int representation.

int	ft_atoi(const char *str)
{
	int	sign;
	int	number;

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
		number = (number * 10) + *str - '0';
		str++;
	}
	number = sign * number;
	return (number);
}
