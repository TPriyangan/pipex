/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpriyang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:10:22 by tpriyang          #+#    #+#             */
/*   Updated: 2023/01/14 16:21:37 by tpriyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dup;
	int		i;
	int		j;

	i = ft_strlen(s);
	dup = (char *)malloc((i + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	j = 0;
	while (s[j] != '\0')
	{
		dup[j] = s[j];
		j++;
	}
	dup[j] = '\0';
	return (dup);
}
/*int	main(void)
{
	char	*alphabet;
	char	*vide;

	alphabet = "abcdefghijklmnopqrstuvwxyz";
	vide = "";
	printf("ft_strdup: %s\n", ft_strdup(alphabet));
	printf("strdup:   %s\n", strdup(alphabet));
	printf("ft_strdup: %s\n", ft_strdup(vide));
	printf("strdup:   %s\n", strdup(vide));
}*/
