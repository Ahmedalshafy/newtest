/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalshafy <aalshafy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 17:02:21 by aalshafy          #+#    #+#             */
/*   Updated: 2023/12/21 16:40:13 by aalshafy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *to_add)
{
	t_list	*n;

	if (!to_add || !lst)
		return ;
	if (!(*(lst)))
	{
		*lst = to_add;
		return ;
	}
	n = *lst;
	while (n->next != NULL)
		n = n->next;
	n->next = to_add;
}
