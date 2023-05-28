/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 12:47:18 by jocaball          #+#    #+#             */
/*   Updated: 2023/04/20 12:47:41 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Parametros  : s: La string que iterar.
//               f: La función a aplicar sobre cada carácter.
// Devuelve    : La string creada tras el correcto uso de ’f’ sobre cada
//               carácter.
//               NULL si falla la reserva de memoria.
// Descripcion : A cada carácter de la string ’s’, aplica la función ’f’ dando
//               como parámetros el índice de cada carácter dentro de ’s’ y el
//               propio carácter. Genera una nueva string con el resultado del
//               uso sucesivo de ’f’

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	len;
	char	*ptr;
	size_t	i;

	len = ft_strlen(s);
	ptr = (char *)malloc((len + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < len)
	{
		ptr[i] = f(i, s[i]);
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
