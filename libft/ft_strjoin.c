/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpriyang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:10:45 by tpriyang          #+#    #+#             */
/*   Updated: 2023/01/14 16:22:11 by tpriyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		k;
	char	*ptr;

	k = 0;
	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	ptr = (char *)malloc((i + j + 1) * sizeof(char const));
	if (!ptr)
		return (NULL);
	while (k < i)
	{
		ptr[k] = s1[k];
		k++;
	}
	while (k < i + j)
	{
		ptr[k] = s2[k - i];
		k++;
	}
	ptr[k] = '\0';
	return (ptr);
}
/*int	main(void)
{
	char	*jean;
	char	*jacques;

	jean = "";
       	jacques = "Jacques";
	printf("%p\n", ft_strjoin(jean,jacques));
}*/
