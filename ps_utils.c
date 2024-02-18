/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalshafy <aalshafy@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 12:12:51 by aalshafy          #+#    #+#             */
/*   Updated: 2024/02/07 12:12:53 by aalshafy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	ps_is_sorted(t_stack *stack)
{
	t_stack	*node;

	node = stack;
	while (node->next != NULL)
	{
		if (node->num > node->next->num)
			return (0);
		node = node->next;
	}
	return (1);
}

int	stack_len(t_stack *stack)
{
	int		i;
	t_stack	*node;

	i = 0;
	node = stack;
	while (node != NULL)
	{
		i++;
		node = node->next;
	}
	return (i);
}

t_stack	*ps_stack_last(t_stack *stack)
{
	t_stack	*node;

	node = stack;
	while (node->next != NULL)
		node = node->next;
	return (node);
}

t_info	ps_edit_info(t_info info, int size, int l)
{
	t_info	new_info;

	new_info = info;
	if (l == 1)
		new_info.l = info.l + 1;
	else
		new_info.l = 0;
	new_info.min_ind = info.min_ind + size;
	return (new_info);
}
