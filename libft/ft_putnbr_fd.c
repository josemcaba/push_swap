/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 12:50:26 by jocaball          #+#    #+#             */
/*   Updated: 2023/04/23 22:12:43 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Parametros  : n : El número que enviar.
//               fd: El file descriptor sobre el que escribir.
// Descripcion : Envía el número ’n’ al file descriptor dado.

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int	digit;
	int	sign;

	sign = 1;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		sign = -1;
	}
	if ((n < -9) || (n > 9))
		ft_putnbr_fd(sign * (n / 10), fd);
	digit = sign * (n % 10) + '0';
	ft_putchar_fd(digit, fd);
}
