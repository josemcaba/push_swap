/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 13:01:52 by jocaball          #+#    #+#             */
/*   Updated: 2023/04/23 19:18:57 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// The ft_strlcat() function concatenates strings with the same input
// parameters and output result as snprintf(3).
//
// ft_strlcat() takes the full size of the destination buffer and guarantee 
// NUL-termination if there is room.  Note that room for the NUL should be
// included in dstsize.
//
// ft_strlcat() appends string src to the end of dst.  It will append at most 
// dstsize - strlen(dst) - 1 characters.  It will then NUL-terminate, unless 
// dstsize is 0 or the original dst string was longer than dstsize (in practice
// this should not happen as it means that either dstsize is incorrect or that
// dst is not a proper string).
//
// If the src and dst strings overlap, the behavior is undefined.
//
// The ft_strlcat() function returns the total length of the string it tried
// to create. For ft_strlcat() that means the initial length of dst plus the
// length of src.

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	src_len;
	size_t	dst_len;
	size_t	i;

	src_len = ft_strlen(src);
	if (dstsize == 0)
		return (src_len);
	dst_len = ft_strlen(dst);
	if (dst_len >= dstsize)
		return (src_len + dstsize);
	i = 0;
	while (src[i] && (i < (dstsize - dst_len - 1)))
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}
