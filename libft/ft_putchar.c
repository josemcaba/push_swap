/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 13:06:05 by jocaball          #+#    #+#             */
/*   Updated: 2023/05/26 18:57:38 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Parametros  : c: El carácter a enviar.
// Devuelve	   : Longitud de lo enviado a la salida estandar (fd = 1).
//               Si se produce un error devuelve -1
// Descripcion : Envía el carácter ’c’ a la salida estandard.

#include "libft.h"

ssize_t	ft_putchar(char c)
{
	ssize_t	len;

	len = write(1, &c, 1);
	return (len);
}
