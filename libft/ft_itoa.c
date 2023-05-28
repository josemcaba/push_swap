/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 12:52:20 by jocaball          #+#    #+#             */
/*   Updated: 2023/04/23 21:49:06 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Parametros  : n: el entero a convertir.
// Devuelve    : La string que represente el número.
//               NULL si falla la reserva de memoria.
// Descripcion : Utilizando malloc(3), genera una string que represente el
//               valor entero recibido como argumento. Los números negativos
//               tienen que gestionarse.

#include "libft.h"

static int	ft_nbrlen(int n, int *sign)
{
	int	len;

	*sign = 1;
	len = 1;
	if (n < 0)
	{
		*sign = -1;
		len++;
	}
	n = n / 10;
	while (n)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

static void	ft_fillnbr(int n, int sign, char *str)
{
	if ((n < -9) || (n > 9))
		ft_fillnbr(n / 10, sign, str - 1);
	*str = sign * (n % 10) + '0';
}

char	*ft_itoa(int n)
{
	int		len;
	int		sign;
	char	*str;

	len = ft_nbrlen(n, &sign);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (sign == -1)
		str[0] = '-';
	ft_fillnbr(n, sign, &str[len - 1]);
	return (str);
}
