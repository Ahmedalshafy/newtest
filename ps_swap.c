/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalshafy <aalshafy@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 12:04:08 by aalshafy          #+#    #+#             */
/*   Updated: 2024/02/07 15:04:25 by aalshafy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	ps_swap(t_stack **stack_t)
{
	t_stack	*tmp;

	if (*stack_t == NULL || (*stack_t)->next == NULL)
		return ;
	tmp = (*stack_t)->next;
	tmp->prev = NULL;
	(*stack_t)->next = tmp->next;
	tmp->next = *stack_t;
	*stack_t = tmp;
	(*stack_t)->next->prev = *stack_t;
}

void	sa(t_stack **stack_a, int print)
{
	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	ps_swap(stack_a);
	if (print)
		ft_printf("sa\n");
}

void	sb(t_stack **stack_b, int print)
{
	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	ps_swap(stack_b);
	if (print)
		ft_printf("sb\n");
}

void	ss(t_stack **stack_a, t_stack **stack_b, int print)
{
	ps_swap(stack_a);
	ps_swap(stack_b);
	if (print)
		ft_printf("ss\n");
}
