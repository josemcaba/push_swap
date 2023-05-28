/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 12:22:57 by jocaball          #+#    #+#             */
/*   Updated: 2023/04/23 19:12:55 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// The ft_bzero() function writes n zeroed bytes to the string s. If n is zero, 
// ft_bzero() does nothing.

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
