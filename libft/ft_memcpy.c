/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 11:59:03 by jocaball          #+#    #+#             */
/*   Updated: 2023/04/23 19:14:05 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// The ft_memcpy() function copies n bytes from memory area src to memory area
// dst. If dst and src overlap, behavior is undefined.  Applications in which
// dst and src might overlap should use ft_memmove() instead.
//
// The ft_memcpy() function returns the original value of dst.

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	if (!((char *)dst || (char *)src))
		return (0);
	while (n--)
		*((unsigned char *)dst + n) = *((const unsigned char *)src + n);
	return (dst);
}
