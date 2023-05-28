/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 12:52:20 by jocaball          #+#    #+#             */
/*   Updated: 2023/05/11 20:32:22 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Parametros  : n: el entero sin signo a convertir.
// Devuelve    : La string que represente el número.
//               NULL si falla la reserva de memoria.
// Descripcion : Utilizando malloc(3), genera una string que represente el
//               valor entero sin signo recibido como argumento.

#include "libft.h"

static int	nbr_len(unsigned int n)
{
	int	len;

	len = 0;
	while (n)
	{
		len++;
		n = n / 10;
	}
	if (len == 0)
		len++;
	return (len);
}

static void	fill_nbr(unsigned int n, char *str)
{
	if (n > 9)
		fill_nbr(n / 10, str - 1);
	*str = (n % 10) + '0';
}

char	*ft_uitoa(unsigned int n)
{
	int		len;
	char	*str;

	len = nbr_len(n);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[len] = '\0';
	fill_nbr(n, &str[len - 1]);
	return (str);
}
