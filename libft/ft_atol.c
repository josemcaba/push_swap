/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 20:29:47 by jocaball          #+#    #+#             */
/*   Updated: 2023/06/09 20:32:13 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// The ft_atol() function converts the initial portion of the string pointed to
// by str to long representation.

long	ft_atol(const char *str)
{
	long	sign;
	long	number;

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
