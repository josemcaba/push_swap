/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 13:04:19 by jocaball          #+#    #+#             */
/*   Updated: 2023/04/20 13:04:22 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// The ft_memchr() function locates the first occurrence of c (converted to an
// unsigned char) in string s.
//
// The ft_memchr() function returns a pointer to the byte located, or NULL if
// no such byte exists within n bytes.

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (*((unsigned char *)s + i) == (unsigned char)c)
			return ((void *)(s + i));
		i++;
	}
	return (NULL);
}
