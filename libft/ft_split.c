/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 13:07:50 by jocaball          #+#    #+#             */
/*   Updated: 2023/04/23 21:35:32 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Parametros  : s: La string a separar.
//               c: El carácter delimitador.
// Devuelve    : El array de nuevas strings resulatente de la separación.
//               NULL si falla la reserva de memoria.
// Descripcion : Reserva (utilizando malloc(3)) un array de strings resultante
//               de separar la string ’s’ en substrings utilizando el caracter
//               ’c’ como delimitador. El array debe terminar con un puntero
//               NULL.

#include "libft.h"

static char	**init_array(char const *str, char c)
{
	size_t	count;
	size_t	i;
	char	**array;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != c)
		{
			count++;
			while (str[i] && str[i] != c)
				i++;
		}
		else
			i++;
	}
	array = (char **)malloc((count + 1) * sizeof(char *));
	if (array)
		array[count] = NULL;
	return (array);
}

static size_t	str_length(const char *str, char c)
{
	size_t	i;

	i = 0;
	while (str[i] && (str[i] != c))
		i++;
	return (i);
}

static int	fill_array(char **array, const char *str, char c)
{
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] != c)
		{
			len = str_length(&str[i], c);
			array[j] = (char *)ft_calloc(len + 1, sizeof(char));
			if (!array[j])
				return (j + 1);
			ft_memcpy(array[j], &str[i], len);
			j++;
			i += (len - 1);
		}
		i++;
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	size_t	n;

	array = init_array(s, c);
	if (!array)
		return (NULL);
	n = fill_array(array, s, c);
	if (n != 0)
	{
		n--;
		while (n > 0)
			free(array[--n]);
		free(array);
		return (NULL);
	}
	return (array);
}
