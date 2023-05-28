/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 13:11:52 by jocaball          #+#    #+#             */
/*   Updated: 2023/04/23 22:01:12 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Parametros  : s: La string que iterar.
//               f: La función a aplicar sobre cada carácter.
// Descripcion : A cada carácter de la string ’s’, aplica la función ’f’ dando
//               como parámetros el índice de cada carácter dentro de ’s’ y la 
//               dirección del propio carácter, que podrá modificarse si es 
//               necesario.

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
