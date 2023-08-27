/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpriyang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 12:33:14 by tpriyang          #+#    #+#             */
/*   Updated: 2023/01/14 16:19:16 by tpriyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*temp;

	temp = lst;
	i = 0;
	while (temp != NULL)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}
/*int	main(void)
{
	t_list	*t1, *t2, *t3, *t4;

	t1 = (t_list*)malloc(1 * sizeof(t_list));
	t2 = (t_list*)malloc(1 * sizeof(t_list));
	t3 = (t_list*)malloc(1 * sizeof(t_list));
	t4 = (t_list*)malloc(1 * sizeof(t_list));

	t1->content = "jean";
	t1->next = t2;
        t2->content = "jean";
        t2->next = t3;
        t3->content = "jean";
        t3->next = t4;
        t4->content = "jean";
        t4->next = NULL;
	printf("%d\n", ft_lstsize(t1));
}*/
