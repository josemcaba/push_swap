/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 12:50:55 by jocaball          #+#    #+#             */
/*   Updated: 2023/04/23 20:45:03 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Parametros  : s1: La primera string.
//               s2: La string a añadir a ’s1’.
// Devuelve    : La nueva string.
// 				 NULL si falla la reserva de memoria.
// Descripcion : Reserva (con malloc(3)) y devuelve una nueva string, formada
//               por la concatenación de 's1' y 's2'.

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	s1_len;
	size_t	str_len;

	s1_len = ft_strlen(s1);
	str_len = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc(str_len * sizeof(char) + 1);
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, s1_len + 1);
	ft_strlcat(str, s2, str_len + 1);
	return (str);
}
