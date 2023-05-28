/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 13:06:05 by jocaball          #+#    #+#             */
/*   Updated: 2023/04/23 22:03:01 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Parametros  : c: El carácter a enviar.
//               fd: El file descriptor sobre el que escribir.
// Descripcion : Envía el carácter ’c’ al file descriptor especificado.

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
