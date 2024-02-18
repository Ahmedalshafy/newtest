/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_less_9.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalshafy <aalshafy@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 08:21:51 by aalshafy          #+#    #+#             */
/*   Updated: 2024/02/07 15:06:32 by aalshafy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	ps_less_9(t_stack **stack_a, t_stack **stack_b, t_info info, int size)
{
	int	l;

	l = info.l + 1;
	if ((size == 3 && stack_len(*stack_a) == 3) || (size == 3 && (l % 2) > 0))
		ps_sort_three_last_a(stack_a, stack_b);
	else if (size == 3 && (l % 2) == 0)
		ps_rev_rot_sort_3_a(stack_a, stack_b, 0);
	else if (size < 9)
		ps_max_3(stack_a, stack_b, info, size);
}

void	ps_max_3(t_stack **stack_a, t_stack **stack_b, t_info info, int size)
{
	t_info	new_info;
	int		min_value;

	size = size - 3;
	new_info = ps_edit_info(info, size, 1);
	min_value = new_info.array[new_info.min_ind];
	if (stack_len(*stack_a) == (size + 3) || (new_info.l % 2) > 0)
	{
		if (size + 3 == 4)
		{
			ps_sort_4_a(stack_a, stack_b);
			return ;
		}
		ps_rot_a2(stack_a, stack_b, min_value, size);
	}
	else if (stack_len(*stack_a) > (size + 3) && (new_info.l % 2) == 0)
		ps_rev_rot_a2(stack_a, stack_b, min_value, size);
	if (stack_len(*stack_a) == 3 || (new_info.l % 2) == 0)
		ps_sort_three_last_a(stack_a, stack_b);
	else if (size == 3 && (new_info.l % 2) == 0)
		ps_rev_rot_sort_3_a(stack_a, stack_b, 0);
	ps_push_top_b(stack_a, stack_b, new_info, size);
}

void	ps_push_top_b(t_stack **stack_a, t_stack **stack_b, t_info info,
		int size)
{
	int	min_value;

	if (size > 3)
	{
		size = size - 3;
		min_value = info.array[info.min_ind - 3];
		ps_rot_b2(stack_a, stack_b, min_value, size);
		ps_sort_three_last_a(stack_a, stack_b);
	}
	else
	{
		ps_push_top_less_3_b(stack_a, stack_b, size);
		return ;
	}
}

void	ps_push_bottom_b(t_stack **stack_a, t_stack **stack_b, int size)
{
	if (size == 2)
	{
		rrb(stack_b, 1);
		if ((*stack_b)->num > ps_stack_last(*stack_b)->num)
		{
			pa(stack_a, stack_b, 1);
			rrb(stack_b, 1);
			pa(stack_a, stack_b, 1);
		}
		else
		{
			rrb(stack_b, 1);
			pa(stack_a, stack_b, 1);
			pa(stack_a, stack_b, 1);
		}
	}
	else if (size == 1)
	{
		rrb(stack_b, 1);
		pa(stack_a, stack_b, 1);
	}
}

void	ps_thrd_less_9(t_stack **stack_a, t_stack **stack_b, t_info info,
		int size)
{
	int		min_value;
	t_info	new_info;

	size = size - 3;
	new_info = ps_edit_info(info, -3, 0);
	min_value = new_info.array[new_info.min_ind];
	if (stack_len(*stack_b) == (size + 3))
		ps_rot_b2(stack_a, stack_b, min_value, size);
	else if (stack_len(*stack_b) > (size + 3))
		ps_rev_rot_b2(stack_a, stack_b, min_value, size);
	ps_sort_three_last_a(stack_a, stack_b);
	if (size == 3 && stack_len(*stack_b) == 3)
		ps_sort_three_last_b(stack_a, stack_b);
	else if (size <= 3)
		ps_push_top_less_3_b(stack_a, stack_b, size);
	else if (size > 3)
		ps_push_top_b(stack_a, stack_b, new_info, size);
}
