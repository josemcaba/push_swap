/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 11:33:57 by jocaball          #+#    #+#             */
/*   Updated: 2023/04/23 19:04:23 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// The ft_isalpha() function tests for any character for which ft_isupper or 
// ft_islower is true.  The value of the argument must be representable as an
// unsigned char or the value of EOF.
//
// The ft_isalpha() function returns zero if the character tests false and
// returns non-zero if the character tests true.

static int	ft_isupper(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}

static int	ft_islower(int c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	return (0);
}

int	ft_isalpha(int c)
{
	return (ft_isupper(c) + ft_islower(c));
}
