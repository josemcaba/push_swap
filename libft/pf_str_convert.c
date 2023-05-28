/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_str_convert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 09:19:30 by jocaball          #+#    #+#             */
/*   Updated: 2023/05/26 18:56:07 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	padding_str(char *str, t_flags *flags)
{
	char	*s;
	int		str_len;
	int		pad_len;

	str_len = ft_strlen(str);
	if ((flags->dot) && (flags->precision < str_len))
		str_len = flags->precision;
	pad_len = str_len;
	if (flags->width > pad_len)
		pad_len = flags->width;
	s = (char *)malloc(pad_len * sizeof(char) + 1);
	if (!s)
		return (-1);
	ft_memset(s, ' ', pad_len);
	s[pad_len] = '\0';
	if (flags->minus)
		ft_memcpy(s, str, str_len);
	else
		ft_memcpy(s + pad_len - str_len, str, str_len);
	if (ft_putstr(s) == -1)
		pad_len = -1;
	free(s);
	return (pad_len);
}

int	pf_str_convert(va_list *args, t_flags *flags)
{
	char	*str;
	int		len;

	str = va_arg(*args, char *);
	if (!str)
		str = "(null)";
	if (flags->nflags)
		len = padding_str(str, flags);
	else
		len = ft_putstr(str);
	return (len);
}
