/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 12:06:53 by jocaball          #+#    #+#             */
/*   Updated: 2023/04/23 19:06:56 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// The ft_strlen() function computes the length of the string s.
//
// The strlen() function returns the number of characters that precede the 
// terminating NUL character.

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
