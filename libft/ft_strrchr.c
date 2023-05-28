/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 12:45:01 by jocaball          #+#    #+#             */
/*   Updated: 2023/04/20 13:24:57 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// The ft_strrchr() function locates the last occurrence of c (converted to a
// char) in the string pointed to by s.  The terminating null character is
// considered to be part of the string; therefore if c is `\0', the func-
// tions locate the terminating `\0'.

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	i = ft_strlen(s);
	while ((i > 0) && (*(s + i) != (char)c))
		i--;
	if (*(s + i) == (char)c)
		return ((char *)(s + i));
	return (0);
}
