/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpriyang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 11:34:00 by tpriyang          #+#    #+#             */
/*   Updated: 2023/01/12 11:37:49 by tpriyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*return_value;

	i = 0;
	return_value = NULL;
	while (s[i])
	{
		if (s[i] == (char)c)
			return_value = (char *)&(s[i]);
		i++;
	}
	if (s[i] == (char)c)
		return_value = (char *)&(s[i]);
	return (return_value);
}
