/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 13:10:20 by jocaball          #+#    #+#             */
/*   Updated: 2023/04/23 19:24:26 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// The ft_strchr() function locates the first occurrence of c (converted to a
// char) in the string pointed to by s.  The terminating null character is
// considered to be part of the string; therefore if c is `\0', the func-
// tions locate the terminating `\0'.

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s && (*s != (char)c))
		s++;
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}
