/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpriyang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 11:43:26 by tpriyang          #+#    #+#             */
/*   Updated: 2023/01/14 16:22:34 by tpriyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	taille_src;

	i = 0;
	taille_src = 0;
	while (src[taille_src])
		taille_src++;
	if (size > 0)
	{
		while (i < size - 1 && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (taille_src);
}
/*int	main(void)
{
	char	dest[10];
	char	*source;

	source = "Pierre";
	printf("%ld\n" ,ft_strlcpy(dest,source,3*sizeof(char)));
	printf("%ld\n" ,strlcpy(dest,source,3*sizeof(char)));	
}*/
