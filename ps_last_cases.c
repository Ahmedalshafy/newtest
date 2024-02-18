/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_last_cases.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalshafy <aalshafy@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 09:46:51 by aalshafy          #+#    #+#             */
/*   Updated: 2024/02/18 17:01:28 by aalshafy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	ps_sort_4_a(t_stack **stack_a, t_stack **stack_b)
{
	if ((*stack_a)->num > (*stack_a)->next->num)
		sa(stack_a, 1);
	pb(stack_a, stack_b, 1);
	ps_sort_three_last_a(stack_a, stack_b);
	ps_push_1_to_a(stack_a, stack_b);
}

void	ps_push_1_to_a(t_stack **stack_a, t_stack **stack_b)
{
	if ((*stack_b)->num < (*stack_a)->num)
		pa(stack_a, stack_b, 1);
	else if ((*stack_b)->num > ps_stack_last(*stack_a)->num)
	{
		pa(stack_a, stack_b, 1);
		ra(stack_a, 1);
	}
	else if ((*stack_b)->num > (*stack_a)->num
		&& (*stack_b)->num < (*stack_a)->next->num)
	{
		pa(stack_a, stack_b, 1);
		sa(stack_a, 1);
	}
	else
	{
		ra(stack_a, 1);
		pa(stack_a, stack_b, 1);
		sa(stack_a, 1);
		rra(stack_a, 1);
	}
}

void	ps_last_cases(t_stack **stack_a, t_stack **stack_b, int size,
		int count_rb)
{
	ps_sort_three_last_a(stack_a, stack_b);
	if (stack_len(*stack_b) == 3)
		ps_sort_three_last_b(stack_a, stack_b);
	else if (!count_rb)
		ps_push_top_less_3_b(stack_a, stack_b, size);
	else if (count_rb == 1 && size == 2)
	{
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
	else if (count_rb && count_rb < 3)
		ps_push_bottom_b(stack_a, stack_b, count_rb);
	else if (count_rb && count_rb == 3)
		ps_push_bottom_3_b(stack_a, stack_b);
}

void	ps_ss_condition(t_stack **stack_a, t_stack **stack_b)
{
	if (*stack_b && (*stack_b)->next && (*stack_b)->num < (*stack_b)->next->num)
		ss(stack_a, stack_b, 1);
	else
		sa(stack_a, 1);
}
