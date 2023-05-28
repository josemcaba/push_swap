/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_uint_convert.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 19:23:04 by jocaball          #+#    #+#             */
/*   Updated: 2023/05/26 18:56:16 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	pf_fill_pad_int(char **pad, char *nbr, t_flags *flags)
{
	int	pad_len;
	int	nbr_len;
	int	no_zero;

	pad_len = ft_strlen(*pad);
	if (pad_len)
	{
		nbr_len = ft_strlen(nbr) - flags->negative;
		no_zero = ft_strncmp(nbr, "0", nbr_len);
		ft_memcpy(*pad, nbr + flags->negative, nbr_len);
		pf_add_precision(&(*pad), &nbr_len, flags, !no_zero);
		pf_add_prfx_int(&(*pad), &nbr_len, flags, no_zero);
		if (!flags->minus)
		{
			ft_memmove(&(*pad)[pad_len - nbr_len], *pad, nbr_len);
			ft_memset(*pad, ' ', pad_len - nbr_len);
			pf_add_width_int(&(*pad), nbr_len, flags);
		}
	}
}

int	pf_uint_convert(va_list *args, t_flags *flags)
{
	size_t	nbr;
	int		len;
	char	*str_nbr;
	char	*pad;

	nbr = va_arg(*args, unsigned int);
	str_nbr = ft_uitoa(nbr);
	if (!str_nbr)
		return (-1);
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
