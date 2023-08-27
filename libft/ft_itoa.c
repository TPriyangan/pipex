/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpriyang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 09:07:40 by tpriyang          #+#    #+#             */
/*   Updated: 2023/01/14 15:18:44 by tpriyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_charfinal(char *str, unsigned int nombre, long long taille)
{
	while (nombre > 0)
	{
		str[taille] = 48 + (nombre % 10);
		nombre = nombre / 10;
		taille--;
	}
	return (str);
}

static long long	ft_taille(int n)
{
	long	taille;

	taille = 0;
	if (n <= 0)
		taille = 1;
	while (n != 0)
	{
		n = n / 10;
		taille++;
	}
	return (taille);
}

char	*ft_itoa(int n)
{
	long long		taille;
	long long		negatif;
	unsigned int	nombre;
	char			*str;

	negatif = 1;
	taille = ft_taille(n);
	str = (char *)malloc((taille + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[taille--] = '\0';
	if (n == 0)
		str[0] = '0';
	if (n < 0)
	{
		negatif = negatif * -1;
		nombre = n * -1;
		str[0] = '-';
	}
	else
		nombre = n;
	str = ft_charfinal(str, nombre, taille);
	return (str);
}
