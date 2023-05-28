/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 11:51:41 by jocaball          #+#    #+#             */
/*   Updated: 2023/04/23 19:06:11 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// The ft_isprint() function tests for any printing character, including space
// (' ').  The value of the argument must be representable as an unsigned char
// or the value of EOF.
//
// In the ASCII character set, this includes any character between 040 and 
// 0176 in octal.

int	ft_isprint(int c)
{
	if (c >= 040 && c <= 0176)
		return (1);
	return (0);
}
