/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpriyang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:04:50 by tpriyang          #+#    #+#             */
/*   Updated: 2023/01/12 10:55:17 by tpriyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	tdst;
	size_t	tsrc;
	size_t	i;

	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	tdst = ft_strlen(dst);
	tsrc = ft_strlen(src);
	while (tdst + i < size -1 && src[i])
	{
		dst[tdst + i] = src[i];
		i++;
	}
	if (tdst > size)
		return (tsrc + size);
	dst[tdst + i] = '\0';
	return (tdst + tsrc);
}
