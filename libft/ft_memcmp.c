/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 13:05:20 by jocaball          #+#    #+#             */
/*   Updated: 2023/04/23 19:27:34 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// The ft_memcmp() function compares byte string s1 against byte string s2. 
// Both strings are assumed to be n bytes long.
//
// The ft_memcmp() function returns zero if the two strings are identical,
// otherwise returns the difference between the first two differing bytes
// (treated as unsigned char values, so that `\200' is greater than `\0', for
// example). Zero-length strings are always identical.

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (*((unsigned char *)s1 + i) != *((unsigned char *)s2 + i))
			return (*((unsigned char *)s1 + i) - *((unsigned char *)s2 + i));
		i++;
	}
	return (0);
}
