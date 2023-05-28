/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_hex_convert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 19:23:04 by jocaball          #+#    #+#             */
/*   Updated: 2023/05/26 18:55:48 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	add_width_hex(char **pad, int nbr_len, t_flags *flags)
{
	int	pad_len;

	pad_len = ft_strlen(*pad);
	if (flags->zero && !flags->dot)
	{
		ft_memset(*pad, '0', pad_len - nbr_len);
		if (ft_strchr(*pad, flags->specifier))
		{
			*ft_strchr(*pad, flags->specifier) = '0';
			(*pad)[1] = flags->specifier;
		}
	}
}

static void	add_prfx_hex(char **pad, int *nbr_len, t_flags *flags, int no_zero)
{
	char	*prefix;

	prefix = "0x";
	if (flags->specifier == 'X')
		prefix = "0X";
	if ((flags->hash && no_zero) || (flags->specifier == 'p'))
	{
		ft_memmove(&(*pad)[2], *pad, *nbr_len);
		ft_memcpy(*pad, prefix, 2);
		*nbr_len += 2;
	}
}

static void	fill_pad_hex(char **pad, char *nbr, t_flags *flags)
{
	int	pad_len;
	int	nbr_len;
	int	no_zero;

	pad_len = ft_strlen(*pad);
	if (pad_len)
	{
		nbr_len = ft_strlen(nbr);
		no_zero = ft_strncmp(nbr, "0", nbr_len);
		ft_memcpy(*pad, nbr, nbr_len);
		pf_add_precision(&(*pad), &nbr_len, flags, !no_zero);
		add_prfx_hex(&(*pad), &nbr_len, flags, no_zero);
		if (!flags->minus)
		{
			ft_memmove(&(*pad)[pad_len - nbr_len], *pad, nbr_len);
			ft_memset(*pad, ' ', pad_len - nbr_len);
			add_width_hex(&(*pad), nbr_len, flags);
		}
	}
}

static int	alloc_pad_hex(char **pad, char *nbr, t_flags *flags)
{
	int	pad_len;
	int	no_zero;

	pad_len = ft_strlen(nbr);
	no_zero = ft_strncmp(nbr, "0", pad_len);
	if (flags->dot && (flags->precision > pad_len))
		pad_len = flags->precision;
	if (flags->dot && (flags->precision == 0) && !no_zero)
		pad_len--;
	if ((flags->hash && no_zero) || (flags->specifier == 'p'))
		pad_len += 2;
	if (flags->width > pad_len)
		pad_len = flags->width;
	*pad = (char *)ft_calloc(pad_len + 1, sizeof(char));
	if (!*pad)
		return (-1);
	ft_memset(*pad, ' ', pad_len);
	return (pad_len);
}

int	pf_hex_convert(va_list *args, t_flags *flags)
{
	size_t	nbr;
	int		len;
	char	*str_nbr;
	char	*pad;

	if (flags->specifier == 'p')
		nbr = (size_t)va_arg(*args, void *);
	else
		nbr = va_arg(*args, unsigned int);
	str_nbr = ft_htoa(nbr, flags->specifier);
	if (!str_nbr)
		return (-1);
	len = alloc_pad_hex(&pad, str_nbr, flags);
	if (len != -1)
	{
		fill_pad_hex(&pad, str_nbr, flags);
		len = ft_putstr(pad);
		free(pad);
	}
	free(str_nbr);
	return (len);
}
