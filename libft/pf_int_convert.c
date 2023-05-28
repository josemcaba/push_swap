/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_int_convert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 19:23:04 by jocaball          #+#    #+#             */
/*   Updated: 2023/05/26 18:56:00 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	pf_add_prfx_int(char **pad, int *nbr_len, t_flags *flags, int no_zero)
{
	if ((flags->negative) && (no_zero))
	{
		ft_memmove(&(*pad)[1], *pad, *nbr_len);
		ft_memcpy(*pad, "-", 1);
		*nbr_len += 1;
	}
	if (flags->space && !flags->negative)
	{
		if (ft_strlen(*pad) > 1)
		{
			ft_memmove(&(*pad)[1], *pad, *nbr_len);
			*nbr_len += 1;
		}
		ft_memcpy(*pad, " ", 1);
	}
	if (flags->plus && !flags->negative)
	{
		if (ft_strlen(*pad) > 1)
		{
			ft_memmove(&(*pad)[1], *pad, *nbr_len);
			*nbr_len += 1;
		}
		ft_memcpy(*pad, "+", 1);
	}
}

void	pf_add_width_int(char **pad, int nbr_len, t_flags *flags)
{
	int	pad_len;

	pad_len = ft_strlen(*pad);
	if (flags->zero && !flags->dot)
	{
		ft_memset(*pad, '0', pad_len - nbr_len);
		if (ft_strchr(*pad, '-'))
		{
			*ft_strchr(*pad, '-') = '0';
			(*pad)[0] = '-';
		}
		if (ft_strchr(*pad, ' '))
		{
			*ft_strchr(*pad, ' ') = '0';
			(*pad)[0] = ' ';
		}
		if (ft_strchr(*pad, '+'))
		{
			*ft_strchr(*pad, '+') = '0';
			(*pad)[0] = '+';
		}
	}
}

void	pf_add_precision(char **pad, int *nbr_len, t_flags *flags, int zero)
{
	int	offset;

	offset = 0;
	if (flags->dot && (flags->precision > *nbr_len))
	{
		offset = flags->precision - *nbr_len;
		ft_memmove(&(*pad)[offset], *pad, *nbr_len);
		ft_memset(*pad, '0', offset);
		*nbr_len += offset;
	}
	if (flags->dot && (flags->precision == 0) && zero)
	{
		*ft_strchr(*pad, '0') = ' ';
		if (ft_strlen(*pad) > 1)
			*nbr_len = 0;
	}
}

int	pf_alloc_pad_int(char **pad, char *nbr, t_flags *flags)
{
	int	pad_len;
	int	no_zero;

	pad_len = ft_strlen(nbr);
	no_zero = ft_strncmp(nbr, "0", pad_len);
	if (flags->negative)
		pad_len--;
	if (flags->dot && (flags->precision > pad_len))
		pad_len = flags->precision;
	if (flags->dot && (flags->precision == 0) && !no_zero)
		pad_len--;
	if (flags->negative && no_zero)
		pad_len++;
	if (flags->space && !flags->negative)
		pad_len++;
	if (flags->plus && !flags->negative)
		pad_len++;
	if (flags->width > pad_len)
		pad_len = flags->width;
	*pad = (char *)ft_calloc(pad_len + 1, sizeof(char));
	if (!*pad)
		return (-1);
	ft_memset(*pad, ' ', pad_len);
	return (pad_len);
}

int	pf_int_convert(va_list *args, t_flags *flags)
{
	size_t	nbr;
	int		len;
	char	*str_nbr;
	char	*pad;

	nbr = va_arg(*args, int);
	str_nbr = ft_itoa(nbr);
	if (!str_nbr)
		return (-1);
	if (*str_nbr == '-')
		flags->negative = 1;
	len = pf_alloc_pad_int(&pad, str_nbr, flags);
	if (len != -1)
	{
		pf_fill_pad_int(&pad, str_nbr, flags);
		len = ft_putstr(pad);
		free(pad);
	}
	free(str_nbr);
	return (len);
}
