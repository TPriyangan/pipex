/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpriyang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:01:57 by tpriyang          #+#    #+#             */
/*   Updated: 2023/01/12 13:52:20 by tpriyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putchar(char c, int fd)
{
	write (fd, &c, 1);
}

static long long	prewrite(long long n2, int fd)
{
	if (n2 <= -2147483648)
	{
		write(fd, "-", 1);
		write(fd, "2", 1);
		n2 = 147483648;
	}
	if (n2 == 0)
		ft_putchar('0', fd);
	if (n2 < 0)
	{
		n2 = n2 * -1;
		ft_putchar('-', fd);
	}
	return (n2);
}

void	ft_putnbr_fd(int n, int fd)
{
	long long int	diviseur;
	long long int	n2;

	n2 = n;
	n2 = prewrite(n2, fd);
	diviseur = 1;
	while (diviseur <= n2)
		diviseur = diviseur * 10;
	while (diviseur > 1)
	{
		diviseur = diviseur / 10;
		ft_putchar((n2 / diviseur + '0'), fd);
		n2 = n2 % diviseur;
	}
}
