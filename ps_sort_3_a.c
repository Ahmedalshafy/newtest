/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_3_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalshafy <aalshafy@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 11:27:47 by aalshafy          #+#    #+#             */
/*   Updated: 2024/02/18 17:02:32 by aalshafy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	ps_sort_three_last_a(t_stack **stack_a, t_stack **stack_b)
{
	int	sec;
	int	thrd;

	if (stack_len(*stack_a) != 3)
	{
		ps_sort_three_a(stack_a, stack_b);
		return ;
	}
	sec = (*stack_a)->next->num;
	thrd = (*stack_a)->next->next->num;
	if ((thrd < sec && thrd > (*stack_a)->num) || (thrd > sec
			&& thrd < (*stack_a)->num))
	{
		if (thrd < sec)
			ps_ss_condition(stack_a, stack_b);
		ra(stack_a, 1);
	}
	else
		ps_sort_last_3_a2(stack_a, stack_b);
}

void	ps_sort_last_3_a2(t_stack **stack_a, t_stack **stack_b)
{
	int	sec;
	int	thrd;

	sec = (*stack_a)->next->num;
	thrd = (*stack_a)->next->next->num;
	if (thrd < sec && thrd < (*stack_a)->num)
	{
		if ((*stack_a)->num > sec)
			ps_ss_condition(stack_a, stack_b);
		rra(stack_a, 1);
	}
	else if (thrd > sec && thrd > (*stack_a)->num && sec < (*stack_a)->num)
		ps_ss_condition(stack_a, stack_b);
}

void	ps_sort_three_a(t_stack **stack_a, t_stack **stack_b)
{
	int	sec;
	int	thrd;

	sec = (*stack_a)->next->num;
	thrd = (*stack_a)->next->next->num;
	if ((thrd < sec && thrd > (*stack_a)->num) || (thrd > sec
			&& thrd < (*stack_a)->num))
	{
		if (thrd < (*stack_a)->num)
			ps_ss_condition(stack_a, stack_b);
		ra(stack_a, 1);
		sa(stack_a, 1);
		rra(stack_a, 1);
	}
	else if (thrd < sec && thrd < (*stack_a)->num)
	{
		if ((*stack_a)->num > sec)
			ps_ss_condition(stack_a, stack_b);
		ra(stack_a, 1);
		ps_ss_condition(stack_a, stack_b);
		rra(stack_a, 1);
		sa(stack_a, 1);
	}
	else if (thrd > sec && thrd > (*stack_a)->num && sec < (*stack_a)->num)
		ps_ss_condition(stack_a, stack_b);
}

void	ps_rev_rot_sort_3_a(t_stack **stack_a, t_stack **stack_b, int size)
{
	int	i;

	if (size == 0)
		size = 3;
	if (size == 1 && (*stack_a)->num > (*stack_a)->next->num)
		ps_ss_condition(stack_a, stack_b);
	i = -1;
	while (++i < size)
	{
		if (i == (size - 1)
			&& ps_stack_last(*stack_a)->num > (*stack_a)->next->num)
		{
			pb(stack_a, stack_b, 1);
			rra(stack_a, 1);
			ps_ss_condition(stack_a, stack_b);
			pa(stack_a, stack_b, 1);
		}
		else
			rra(stack_a, 1);
		if ((*stack_a)->num > (*stack_a)->next->num)
			ps_ss_condition(stack_a, stack_b);
	}
}
