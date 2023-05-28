/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 12:42:27 by jocaball          #+#    #+#             */
/*   Updated: 2023/04/23 20:41:26 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Parametros : s     : La string desde la que crear la substring. 
//              start : El índice del caracter en ’s’ desde el que empezar la
//                      substring.
//              len   : La longitud máxima de la substring.
// Devuelve   : La substring resultante.
//              NULL si falla la reserva de memoria.
// Decripcion : Reserva (con malloc) y devuelve una substring de la string 's'.
//              La substring empieza desde el indice 'start' y tiene una
//              longitud máxima 'len'.

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	char	*ptr;

	s_len = ft_strlen(s);
	if (start > s_len)
		s_len = 0;
	else
		s_len = s_len - start;
	if (len < s_len)
		s_len = len;
	ptr = (char *)malloc(s_len * sizeof(char) + 1);
	if (!ptr)
		return (NULL);
	ft_memcpy(ptr, s + start, s_len);
	*(ptr + s_len) = '\0';
	return (ptr);
}
