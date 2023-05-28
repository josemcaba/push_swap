/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 12:46:19 by jocaball          #+#    #+#             */
/*   Updated: 2023/04/23 19:25:29 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// The ft_strncmp() function lexicographically compares the null-terminated
// strings s1 and s2.
//
// The ft_strncmp() function compares not more than n characters. Because 
// ft_strncmp() is designed for comparing strings rather than binary data,
// characters that appear after a `\0' character are not compared.
//
// The ft_strncmp() function returns an integer greater than, equal to, or less
// than 0, according as the string s1 is greater than, equal to, or less than 
// the string s2.  The comparison is done using unsigned characters, so that 
// `\200' is greater than `\0'.

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (s1[i] && s2[i] && (s1[i] == s2[i]) && (i < (n - 1)))
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
