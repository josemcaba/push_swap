/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 12:41:47 by jocaball          #+#    #+#             */
/*   Updated: 2023/04/23 19:22:39 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// The ft_tolower() function converts an upper-case letter to the corresponding
// lower-case letter.  The argument must be representable as an unsigned char
// or the value of EOF.

int	ft_tolower(int c)
{
	if ((c >= 'A') && (c <= 'Z'))
		c = (c - 'A') + 'a';
	return (c);
}
