/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 11:49:43 by jocaball          #+#    #+#             */
/*   Updated: 2023/04/23 19:05:37 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// The ft_isascii() function tests for an ASCII character, which is any
// character between 0 and octal 0177 inclusive.

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 0177)
		return (1);
	return (0);
}
