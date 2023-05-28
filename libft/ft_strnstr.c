/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 12:45:38 by jocaball          #+#    #+#             */
/*   Updated: 2023/04/20 12:45:59 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// The ft_strnstr() function locates the first occurrence of the 
// null-terminated string needle in the string haystack, where not more than
// len characters are searched.  Characters that appear after a `\0' character
// are not searched.
//
// If needle is an empty string, haystack is returned; if needle occurs
// nowhere in haystack, NULL is returned; otherwise a pointer to the first
// character of the first occurrence of needle is returned.

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	n_len;

	n_len = ft_strlen(needle);
	if (n_len == 0)
		return ((char *)haystack);
	if (len == 0)
		return (NULL);
	i = 0;
	while ((i <= (len - n_len)) && haystack[i])
	{
		j = 0;
		while ((haystack[i + j] == needle[j]) && needle[j])
			j++;
		if (j == n_len)
		{
			if (n_len > len)
				return (NULL);
			else
				return ((char *)haystack + i);
		}
		i++;
	}
	return (NULL);
}
