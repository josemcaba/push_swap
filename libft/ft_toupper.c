/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 12:41:15 by jocaball          #+#    #+#             */
/*   Updated: 2023/04/23 19:22:50 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// The ft_toupper() function converts a lower-case letter to the corresponding
// upper-case letter. The argument must be representable as an unsigned char
// or the value of EOF.

int	ft_toupper(int c)
{
	if ((c >= 'a') && (c <= 'z'))
		c = (c - 'a') + 'A';
	return (c);
}
