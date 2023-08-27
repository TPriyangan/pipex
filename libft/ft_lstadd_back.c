/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpriyang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 13:45:30 by tpriyang          #+#    #+#             */
/*   Updated: 2023/01/14 16:11:51 by tpriyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (lst)
	{
		if ((*lst) == NULL)
			(*lst) = new;
		else
		{
			temp = (*lst);
			while (temp->next != NULL)
			{
				temp = temp->next;
			}
			temp->next = new;
		}
	}
}
/*int	main(void)
{
	t_list	*t1,*t2,*t3, *tlast;

	t1=(t_list*)malloc(1*sizeof(t_list));
	t2=(t_list*)malloc(1*sizeof(t_list));
	t3=(t_list*)malloc(1*sizeof(t_list));
	tlast=(t_list*)malloc(1*sizeof(t_list));


	t1->content = "1";
	t1->next = t2;
	t2->content = "2";
	t2->next = t3;
	t3->content = "3";
	t3->next = NULL;

	tlast->content = "thelast";
        tlast->next = NULL;
	ft_lstadd_back(&t1, tlast);
	while (t1 != NULL)
	{
		printf(" - %s", (char*)t1->content);
		t1 = t1->next;
	}
}*/
