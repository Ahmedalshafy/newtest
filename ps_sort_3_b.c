/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_3_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalshafy <aalshafy@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 09:44:05 by aalshafy          #+#    #+#             */
/*   Updated: 2024/02/07 15:09:49 by aalshafy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	ps_sort_three_last_b(t_stack **stack_a, t_stack **stack_b)
{
	if ((*stack_b)->num > (*stack_b)->next->num
		&& (*stack_b)->num > ps_stack_last(*stack_b)->num)
	{
		pa(stack_a, stack_b, 1);
		if ((*stack_b)->num < ps_stack_last(*stack_b)->num)
			sb(stack_b, 1);
	}
	else if ((*stack_b)->next->num > (*stack_b)->num
		&& (*stack_b)->next->num > ps_stack_last(*stack_b)->num)
	{
		if ((*stack_b)->num > ps_stack_last(*stack_b)->num)
			sb(stack_b, 1);
		else
			rb(stack_b, 1);
	}
	else if (ps_stack_last(*stack_b)->num > (*stack_b)->num
		&& ps_stack_last(*stack_b)->num > (*stack_b)->next->num)
	{
		if ((*stack_b)->next->num > (*stack_b)->num)
			sb(stack_b, 1);
		rrb(stack_b, 1);
	}
	while ((*stack_b))
		pa(stack_a, stack_b, 1);
}

void	ps_sort_top_3_b(t_stack **stack_a, t_stack **stack_b)
{
	int		i;
	t_stack	*tmp;

	i = -1;
	tmp = *stack_b;
	while (++i < 3)
	{
		if (tmp->next && tmp->num < tmp->next->num)
			sb(stack_b, 1);
		pa(stack_a, stack_b, 1);
		tmp = *stack_b;
		if ((*stack_a)->next && (*stack_a)->num > (*stack_a)->next->num)
			sa(stack_a, 1);
	}
}

void	ps_push_bottom_3_b(t_stack **stack_a, t_stack **stack_b)
{
	int	i;

	i = -1;
	while (++i < 3)
		rrb(stack_b, 1);
	ps_sort_top_3_b(stack_a, stack_b);
}
