/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 11:38:00 by jocaball          #+#    #+#             */
/*   Updated: 2023/04/23 19:04:46 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// The ft_isdigit() function tests for a decimal digit character.  Regardless
// of locale, this includes the following characters only:
//     '0'    '1'    '2'    '3'    '4'    '5'    '6'    '7'    '8'    '9'
//
// The ft_isdigit() function returns zero if the character tests false and
// return non-zero if the character tests true.

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
