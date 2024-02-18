/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_less_9_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalshafy <aalshafy@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 09:41:55 by aalshafy          #+#    #+#             */
/*   Updated: 2024/02/07 15:06:03 by aalshafy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	ps_push_top_less_3_b(t_stack **stack_a, t_stack **stack_b, int size)
{
	if (!(*stack_b))
		return ;
	if (size == 3)
	{
		ps_sort_top_3_b(stack_a, stack_b);
		return ;
	}
	else if (size == 2)
	{
		if ((*stack_b)->num < (*stack_b)->next->num)
			sb(stack_b, 1);
		pa(stack_a, stack_b, 1);
		pa(stack_a, stack_b, 1);
	}
	else if (size == 1)
		pa(stack_a, stack_b, 1);
}

void	ps_rot_a2(t_stack **stack_a, t_stack **stack_b, int min_value, int size)
{
	int	count_pb;
	int	count_ra;

	count_pb = 0;
	count_ra = 0;
	while (stack_a && count_pb < size)
	{
		if ((*stack_a)->num < min_value)
		{
			pb(stack_a, stack_b, 1);
			count_pb++;
		}
		else
		{
			ra(stack_a, 1);
			count_ra++;
		}
	}
	if (stack_len(*stack_a) == 3 || count_ra == 0)
		ps_sort_three_last_a(stack_a, stack_b);
	else if (count_ra && count_ra <= 3)
		ps_rev_rot_sort_3_a(stack_a, stack_b, count_ra);
}

void	ps_rev_rot_a2(t_stack **stack_a, t_stack **stack_b, int min_value,
		int size)
{
	t_stack	*tmp;
	int		i;

	tmp = *stack_a;
	i = -1;
	while (tmp && ++i < size + 3)
	{
		rra(stack_a, 1);
		tmp = *stack_a;
		if (tmp->num < min_value)
			pb(stack_a, stack_b, 1);
		tmp = *stack_a;
	}
}

void	ps_rot_b2(t_stack **stack_a, t_stack **stack_b, int min_value, int size)
{
	t_stack	*tmp;
	int		count_pa;
	int		count_rb;

	count_pa = 0;
	count_rb = 0;
	tmp = *stack_b;
	while (tmp && count_pa < 3)
	{
		if (tmp->num >= min_value)
		{
			pa(stack_a, stack_b, 1);
			count_pa++;
		}
		else
		{
			rb(stack_b, 1);
			count_rb++;
		}
		tmp = *stack_b;
	}
	ps_last_cases(stack_a, stack_b, size, count_rb);
}

void	ps_rev_rot_b2(t_stack **stack_a, t_stack **stack_b, int min_value,
		int size)
{
	t_stack		*tmp;
	int			i;

	tmp = *stack_b;
	i = -1;
	while (tmp && ++i < (size + 3))
	{
		rrb(stack_b, 1);
		tmp = *stack_b;
		if (tmp->num >= min_value)
			pa(stack_a, stack_b, 1);
		tmp = *stack_b;
	}
}
