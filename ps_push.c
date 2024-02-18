/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalshafy <aalshafy@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 16:15:35 by aalshafy          #+#    #+#             */
/*   Updated: 2024/02/07 14:58:07 by aalshafy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	push(t_stack **stack_1, t_stack **stack_2)
{
	t_stack	*tmp;

	if (*stack_2 == NULL)
		return ;
	tmp = *stack_2;
	*stack_2 = (*stack_2)->next;
	if (*stack_2)
		(*stack_2)->prev = NULL;
	tmp->next = *stack_1;
	if (*stack_1)
		(*stack_1)->prev = tmp;
	*stack_1 = tmp;
}

void	pa(t_stack **stack_a, t_stack **stack_b, int print)
{
	if (*stack_b == NULL)
		return ;
	push(stack_a, stack_b);
	if (print)
		ft_printf("pa\n");
}

void	pb(t_stack **stack_a, t_stack **stack_b, int print)
{
	if (*stack_a == NULL)
		return ;
	push(stack_b, stack_a);
	if (print)
		ft_printf("pb\n");
}
