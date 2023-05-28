/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 12:35:56 by jocaball          #+#    #+#             */
/*   Updated: 2023/04/23 20:11:54 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// The ft_calloc() function contiguously allocates enough space for count
// objects that are size bytes of memory each and returns a pointer to the
// allocated memory.  The allocated memory is filled with bytes of value zero.

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;
	size_t	total_size;

	total_size = count * size;
	ptr = (char *)malloc(total_size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, total_size);
	return ((void *)ptr);
}
