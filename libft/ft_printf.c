/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 08:36:56 by jocaball          #+#    #+#             */
/*   Updated: 2023/05/11 20:29:30 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	convert(va_list *args, t_flags *flags)
{
	int		len;

	len = 0;
	if (flags->specifier == 'c')
		len = pf_char_convert(args, flags);
	else if (flags->specifier == 's')
		len = pf_str_convert(args, flags);
	else if (flags->specifier == 'p')
		len = pf_hex_convert(args, flags);
	else if ((flags->specifier == 'x') || (flags->specifier == 'X'))
		len = pf_hex_convert(args, flags);
	else if ((flags->specifier == 'd') || (flags->specifier == 'i'))
		len = pf_int_convert(args, flags);
	else if (flags->specifier == 'u')
		len = pf_uint_convert(args, flags);
	else if ((flags->specifier == '%') && (!flags->nflags))
		len = ft_putchar(flags->specifier);
	else if (flags->nflags)
		len = pf_char_convert_narg(flags);
	return (len);
}

static int	parse_and_print(char const *format, t_flags *flags, va_list *args)
{
	int	len;

	if (*format == '%')
	{
		pf_flags_read(flags, ++format);
		len = convert(args, flags);
		if (len == -1)
			return (-1);
	}
	else
	{
		len = ft_putchar(*format);
		if (len == -1)
			return (-1);
	}
	return (len);
}

int	ft_printf(char const *format, ...)
{
	va_list	args;
	int		len;
	int		t_len;
	t_flags	flags;

	va_start (args, format);
	len = 0;
	while (*format)
	{
		flags.nflags = 0;
		t_len = parse_and_print(format, &flags, &args);
		if (t_len == -1)
			return (-1);
		len += t_len;
		if (*format == '%')
			format += 2;
		else
			format += 1;
		format += flags.nflags;
	}
	va_end(args);
	return (len);
}
