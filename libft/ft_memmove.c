/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 12:00:46 by jocaball          #+#    #+#             */
/*   Updated: 2023/04/23 19:14:37 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// The ft_memmove() function copies len bytes from string src to string dst.
// The two strings may overlap; the copy is always done in a non-destructive
// manner.
//
// The ft_memmove() function returns the original value of dst.

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	if (!((char *)dst || (char *)src))
		return (0);
	if (dst >= src)
		while (len--)
			*((unsigned char *)dst + len) = *((const unsigned char *)src + len);
	else
	{
		i = -1;
		while (++i < len)
			*((unsigned char *)dst + i) = *((const unsigned char *)src + i);
	}
	return (dst);
}
