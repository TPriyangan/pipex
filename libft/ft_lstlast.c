/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpriyang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 13:07:24 by tpriyang          #+#    #+#             */
/*   Updated: 2023/01/14 16:15:21 by tpriyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	while (lst != NULL && lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}
/*int	main(void)
{
	t_list	*t1, *t2, *t3 ,*treturn;

	t1 = (t_list *)malloc(1 * sizeof(t_list));
	t2 = (t_list *)malloc(1 * sizeof(t_list));
        t3= (t_list *)malloc(1 * sizeof(t_list));
	treturn = (t_list *)malloc(1 * sizeof(t_list));

	t1->content = "1";
	t1->next = t2;
	t2->content = "1";
        t2->next = t3;
	t3->content = "lasttt";
        t3->next = NULL;

	treturn = ft_lstlast(t1);

	printf("%s\n", (char*)treturn->content);
}*/
