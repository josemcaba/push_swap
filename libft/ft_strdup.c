/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 13:10:41 by jocaball          #+#    #+#             */
/*   Updated: 2023/04/23 20:18:02 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// The ft_strdup() function allocates sufficient memory for a copy of the 
// string s1, does the copy, and returns a pointer to it.  The pointer may
// subsequently be used as an argument to the function free(3).
//
// If insufficient memory is available, NULL is returned and errno is set to
// ENOMEM.

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;
	size_t	len;

	len = ft_strlen(s1);
	s2 = (char *)malloc(len + 1);
	if (!s2)
		return (NULL);
	ft_memcpy(s2, s1, len + 1);
	return (s2);
}
