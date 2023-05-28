/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_htoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 12:52:20 by jocaball          #+#    #+#             */
/*   Updated: 2023/05/26 18:56:53 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Parametros  : n: el numero a convertir.
// Devuelve    : La string que represente el número.
//               NULL si falla la reserva de memoria.
// Descripcion : Utilizando malloc(3), genera una string que represente el
//               valor hexadecimal recibido como argumento.

#include "libft.h"

static void	fill_hnbr(size_t n, char *str, int specifier)
{
	char	*hex_base;

	hex_base = "0123456789abcdef";
	if (specifier == 'X')
		hex_base = "0123456789ABCDEF";
	if (n > 15)
		fill_hnbr(n / 16, str - 1, specifier);
	*str = hex_base[n % 16];
}

static int	hnbr_len(size_t n)
{
	int	len;

	len = 1;
	n = n / 16;
	while (n)
	{
		len++;
		n = n / 16;
	}
	return (len);
}

char	*ft_htoa(size_t n, int specifier)
{
	int		len;
	char	*str;

	len = hnbr_len(n);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (0);
	str[len] = '\0';
	fill_hnbr(n, &str[len - 1], specifier);
	return (str);
}
