/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 13:06:27 by jocaball          #+#    #+#             */
/*   Updated: 2023/04/23 22:08:52 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Parametros  : s: La string a enviar.
//               fd: El file descriptor sobre el que escribir.
// Descripcion : Envía la string ’s’ al descriptor dado, seguido de un salto de
//               línea.

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
	write(fd, "\n", 1);
}
