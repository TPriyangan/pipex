/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpriyang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 10:20:41 by tpriyang          #+#    #+#             */
/*   Updated: 2023/01/14 16:18:22 by tpriyang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_content;

	new_content = (t_list *)malloc(1 * sizeof(t_list));
	if (!new_content)
		return (NULL);
	new_content->content = content;
	new_content->next = NULL;
	return (new_content);
}
/*int	main(void)
{
	t_list	*valeur_de_base;
	t_list	*valeur_de_retour;

	valeur_de_base = (t_list*)malloc( 1 * sizeof(t_list));
	valeur_de_base->content = (void*)49;
	valeur_de_base->next = NULL;

	valeur_de_retour = ft_lstnew(valeur_de_base);
	printf("%s\n", (char*)valeur_de_retour->content);
}*/
/*int	main(void)
{
	t_list	*valeur_de_base;
	valeur_de_base = ft_lstnew("jean");
	printf("%s\n", (char*)valeur_de_base->content);
}*/
