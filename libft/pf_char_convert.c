/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_char_convert.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 09:19:30 by jocaball          #+#    #+#             */
/*   Updated: 2023/05/26 18:55:33 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	padding_char(unsigned char c, t_flags *flags)
{
	int	len;
	int	cc;

	cc = ' ';
	if (flags->zero)
		cc = '0';
	len = flags->width;
	if (flags->minus)
	{
		if (ft_putchar(c) == -1)
			return (-1);
		while (--flags->width)
			if (ft_putchar(' ') == -1)
				return (-1);
	}
	else
	{
		while (--flags->width)
			if (ft_putchar(cc) == -1)
				return (-1);
		if (ft_putchar(c) == -1)
			return (-1);
	}
	return (len);
}

int	pf_char_convert_narg(t_flags *flags)
{
	int	len;

	if (flags->width)
		len = padding_char(flags->specifier, flags);
	else
		len = ft_putchar(flags->specifier);
	return (len);
}

int	pf_char_convert(va_list *args, t_flags *flags)
{
	unsigned int	c;
	int				len;

	c = va_arg(*args, unsigned int);
	if (flags->width)
		len = padding_char(c, flags);
	else
		len = ft_putchar(c);
	return (len);
}
