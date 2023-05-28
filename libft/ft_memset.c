/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 11:57:56 by jocaball          #+#    #+#             */
/*   Updated: 2023/04/23 19:08:20 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// The ft_memset() function writes len bytes of value c (converted to an
// unsigned char) to the string b.
//
// The memset() function returns its first argument.

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		*((unsigned char *)b + i) = (unsigned char)c;
		i++;
	}
	return (b);
}
