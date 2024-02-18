/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalshafy <aalshafy@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 09:54:55 by aalshafy          #+#    #+#             */
/*   Updated: 2024/02/18 17:01:51 by aalshafy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	ps_rot_a(t_stack **stack_a, t_stack **stack_b, t_info info, int size)
{
	int	i;
	int	sec_value;

	sec_value = info.array[info.min_ind - (size / 3)];
	i = -1;
	if (stack_len(*stack_a) > size)
	{
		while (*stack_a && ++i < size)
		{
			if ((*stack_a)->num < info.array[info.min_ind])
				pb(stack_a, stack_b, 1);
			else
			{
				if ((*stack_b) && stack_len(*stack_b) < ((size / 3) * 2)
					&& (*stack_b)->num < sec_value)
					rr(stack_a, stack_b, 1);
				else
					ra(stack_a, 1);
			}
		}
	}
	else
		ps_rot_a_size(stack_a, stack_b, info, size);
}

void	ps_rot_a_size(t_stack **stack_a, t_stack **stack_b, t_info info,
		int size)
{
	int	count_pb;
	int	sec_value;
	int	i;

	count_pb = 0;
	sec_value = info.array[info.min_ind - (size / 3)];
	i = -1;
	while (*stack_a && count_pb < ((size / 3) * 2) && ++i < size)
	{
		if ((*stack_a)->num < info.array[info.min_ind])
		{
			pb(stack_a, stack_b, 1);
			count_pb++;
		}
		else
		{
			if ((*stack_b) && stack_len(*stack_b) < ((size / 3) * 2)
				&& (*stack_b)->num < sec_value)
				rr(stack_a, stack_b, 1);
			else
				ra(stack_a, 1);
		}
	}
}

void	ps_rev_rot_a(t_stack **stack_a, t_stack **stack_b, int min_value,
		int size)
{
	t_stack	*tmp;
	int		i;

	tmp = *stack_a;
	i = -1;
	if (stack_len(*stack_a) > size)
	{
		while (tmp && ++i < size)
		{
			rra(stack_a, 1);
			tmp = *stack_a;
			if (tmp->num < min_value)
				pb(stack_a, stack_b, 1);
			tmp = *stack_a;
		}
	}
	else
		ps_rev_rot_a_size(stack_a, stack_b, min_value, size);
}

void	ps_rev_rot_a_size(t_stack **stack_a, t_stack **stack_b, int min_value,
		int size)
{
	t_stack	*tmp;
	int		count_pb;

	count_pb = 0;
	tmp = *stack_a;
	while (tmp && count_pb < ((size / 3) * 2))
	{
		rra(stack_a, 1);
		tmp = *stack_a;
		if (tmp->num < min_value)
		{
			pb(stack_a, stack_b, 1);
			count_pb++;
		}
		tmp = *stack_a;
	}
}
