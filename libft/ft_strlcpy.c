/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 12:38:54 by jocaball          #+#    #+#             */
/*   Updated: 2023/04/23 19:16:15 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// The ft_strlcpy() function copies strings with the same input parameters and
// output result as snprintf(3).
//
// ft_strlcpy() takes the full size of the destination buffer and guarantee
// NUL-termination if there is room.  Note that room for the NUL should be 
// included in dstsize.
//
// ft_strlcpy() copies up to dstsize - 1 characters from the string src to dst,
// NUL-terminating the result if dstsize is not 0.
//
// If the src and dst strings overlap, the behavior is undefined.
//
// The ft_strlcpy() function returns the total length of the string they tried
// to create.  For ft_strlcpy() that means the length of src.

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	while ((i < (dstsize - 1)) && src[i] && dstsize)
	{
		dst[i] = src[i];
		i++;
	}
	if (dstsize > 0)
		dst[i] = '\0';
	return (ft_strlen(src));
}
