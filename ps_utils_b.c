/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalshafy <aalshafy@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 08:42:08 by aalshafy          #+#    #+#             */
/*   Updated: 2024/02/19 11:15:10 by aalshafy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// rotate stack a and push any element less than the pivot to stack b

#include "ps.h"

void	ps_rot_b(t_stack **stack_a, t_stack **stack_b, int min_value, int size)
{
	t_stack	*tmp;
	int		i;

	tmp = *stack_b;
	i = -1;
	if (stack_len(*stack_b) > (size * 2))
	{
		while (tmp && ++i < (size * 2))
		{
			if (tmp->num >= min_value)
				pa(stack_a, stack_b, 1);
			else
				rb(stack_b, 1);
			tmp = *stack_b;
		}
	}
	else
		ps_rot_b_size(stack_a, stack_b, min_value, size);
}

void	ps_rot_b_size(t_stack **stack_a, t_stack **stack_b, int min_value,
		int size)
{
	t_stack	*tmp;
	int		count_pa;

	count_pa = 0;
	tmp = *stack_b;
	while (tmp && count_pa < size)
	{
		if (tmp->num >= min_value)
		{
			pa(stack_a, stack_b, 1);
			count_pa++;
		}
		else
			rb(stack_b, 1);
		tmp = *stack_b;
	}
}

void	ps_rev_rot_b(t_stack **stack_a, t_stack **stack_b, int min_value,
		int size)
{
	t_stack	*tmp;
	int		i;

	tmp = *stack_b;
	i = -1;
	while (tmp && ++i < size)
	{
		rrb(stack_b, 1);
		tmp = *stack_b;
		if (tmp->num >= min_value)
			pa(stack_a, stack_b, 1);
		tmp = *stack_b;
	}
}
