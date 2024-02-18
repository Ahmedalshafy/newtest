/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_merge.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalshafy <aalshafy@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 08:21:51 by aalshafy          #+#    #+#             */
/*   Updated: 2024/02/07 09:55:47 by aalshafy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	ps_max_chunck(t_stack **stack_a, t_stack **stack_b, t_info info,
		int size)
{
	t_info	new_info;
	int		b_size;
	int		a_size;
	int		min_value;
	int		l;

	if (size < 9)
	{
		ps_less_9(stack_a, stack_b, info, size);
		return ;
	}
	a_size = ((size / 3) + (size % 3));
	b_size = size - a_size;
	new_info = ps_edit_info(info, b_size, 1);
	min_value = new_info.array[new_info.min_ind];
	l = new_info.l;
	if (stack_len(*stack_a) == size || (l % 2) > 0)
		ps_rot_a(stack_a, stack_b, new_info, size);
	else if (stack_len(*stack_a) > size && (l % 2) == 0)
		ps_rev_rot_a(stack_a, stack_b, min_value, size);
	ps_max_chunck(stack_a, stack_b, new_info, a_size);
	ps_sec_chunck(stack_a, stack_b, new_info, (size / 3));
}

void	ps_sec_chunck(t_stack **stack_a, t_stack **stack_b, t_info info,
		int size)
{
	t_info	new_info;
	int		min_value;

	new_info = ps_edit_info(info, (size * -1), 2);
	min_value = new_info.array[new_info.min_ind];
	ps_rot_b(stack_a, stack_b, min_value, size);
	if (size == 3)
		ps_sort_three_a(stack_a, stack_b);
	if (size == 3 && stack_len(*stack_b) == 3)
	{
		ps_sort_three_last_b(stack_a, stack_b);
		return ;
	}
	else if (size == 3 && stack_len(*stack_b) > 3)
	{
		ps_push_bottom_3_b(stack_a, stack_b);
		return ;
	}
	ps_max_chunck(stack_a, stack_b, new_info, size);
	ps_thrd_chunck(stack_a, stack_b, new_info, size);
}

void	ps_thrd_chunck(t_stack **stack_a, t_stack **stack_b, t_info info,
		int size)
{
	t_info	new_info;
	int		min_value;
	int		a_size;
	int		b_size;

	if (size < 9)
	{
		ps_thrd_less_9(stack_a, stack_b, info, size);
		return ;
	}
	a_size = (size / 3) + (size % 3);
	b_size = size / 3;
	new_info = ps_edit_info(info, (a_size * -1), 3);
	min_value = new_info.array[new_info.min_ind];
	if (stack_len(*stack_b) == size)
		ps_rot_b_size(stack_a, stack_b, min_value, a_size);
	else if (stack_len(*stack_b) > size)
		ps_rev_rot_b(stack_a, stack_b, min_value, size);
	ps_max_chunck(stack_a, stack_b, new_info, a_size);
	ps_sec_chunck(stack_a, stack_b, new_info, b_size);
}
