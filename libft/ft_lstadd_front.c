/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpriyang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 11:18:58 by tpriyang          #+#    #+#             */
/*   Updated: 2023/01/14 16:12:06 by tpriyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}
/*int	main(void)
{
	t_list *t1;
	t_list *t2;
	t_list *t3;
	t_list *tfirst;

	t1 = (t_list*)malloc(1 * sizeof(t_list));
	t2 = (t_list*)malloc(1 * sizeof(t_list));
	t3 = (t_list*)malloc(1 * sizeof(t_list));
	tfirst = (t_list*)malloc(1 * sizeof(t_list));
	t1->content = "ancienne tete";
	t1->next = t2;
	t2->content = "t2";
	t2->next = t3;
	t3->content = "t3";
	t3->next = NULL;
	tfirst->content = "nouvelle tete";
	tfirst->next = NULL;
	ft_lstadd_front(&t1 ,tfirst);
	while(t1 != NULL)
	{
		printf(" - %s",(char *)t1->content);
		t1 = t1->next;
	}
}*/
