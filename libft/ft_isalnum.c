/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 11:46:01 by jocaball          #+#    #+#             */
/*   Updated: 2023/04/23 19:05:14 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// The ft_isalnum() function tests for any character for which ft_isalpha() or 
// ft_isdigit() is true.  The value of the argument must be representable as an
// unsigned char or the value of EOF.
//
// The ft_isalnum() function returns zero if the character tests false and
// returns non-zero if the character tests true.

#include "libft.h"

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (1);
	return (0);
}
