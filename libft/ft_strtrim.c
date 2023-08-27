/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpriyang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 09:57:56 by tpriyang          #+#    #+#             */
/*   Updated: 2023/01/12 14:32:07 by tpriyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	c_in_chain(char	*chain, char c)
{
	int	i;

	i = 0;
	while (chain[i])
	{
		if (chain[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static size_t	preshotdebut(char const *s1, char const *set)
{
	size_t	debut;

	debut = 0;
	while (s1[debut])
	{
		if (c_in_chain((char *)set, s1[debut]))
			debut++;
		else
			break ;
	}
	return (debut);
}

static size_t	preshot(char const *s1, char const *set, size_t fin)
{
	size_t	debut;

	debut = preshotdebut(s1, set);
	while (fin > debut)
	{
		if (c_in_chain((char *)set, s1[fin - 1]))
			fin--;
		else
			break ;
	}
	return (fin);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	debut;
	size_t	fin;
	char	*trimed;

	if (!s1)
		return (NULL);
	fin = ft_strlen((char *)s1);
	debut = preshotdebut(s1, set);
	fin = preshot(s1, set, fin);
	i = 0;
	trimed = (char *)malloc(((fin - debut) + 1) * sizeof(char));
	if (!trimed)
		return (NULL);
	while (debut + i < fin)
	{
		trimed[i] = s1[debut + i];
		i++;
	}
	trimed[i] = '\0';
	return (trimed);
}
