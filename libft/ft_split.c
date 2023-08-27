/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpriyang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 09:34:33 by tpriyang          #+#    #+#             */
/*   Updated: 2023/01/14 14:34:12 by tpriyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_nbr_mots(char const *s, char c)
{
	size_t	i;
	size_t	mot;

	i = 0;
	mot = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i])
		{
			while (s[i] != c && s[i])
				i++;
			mot++;
		}
	}
	return (mot);
}

static size_t	ft_lettres(char const *s, size_t start, char c)
{
	size_t	i;

	i = 0;
	while (s[start + i] && s[start + i] != c)
	{
		i++;
	}
	return (i);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	mots;
	char	**ptr;

	if (!s)
		return (NULL);
	ptr = malloc((ft_nbr_mots(s, c) + 1) * sizeof(ptr));
	if (!ptr)
		return (NULL);
	i = 0;
	mots = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i])
		{
			ptr[mots] = ft_substr(s, i, ft_lettres(s, i, c));
			i = i + ft_lettres(s, i, c);
			mots++;
		}
	}
	ptr[mots] = NULL;
	return (ptr);
}
