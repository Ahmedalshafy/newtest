/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rev_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalshafy <aalshafy@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 12:10:03 by aalshafy          #+#    #+#             */
/*   Updated: 2024/02/07 15:02:53 by aalshafy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	ps_rev_rotate(t_stack **stack_t)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	if (*stack_t == NULL || (*stack_t)->next == NULL)
		return ;
	tmp = *stack_t;
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	tmp2 = tmp->next;
	tmp->next = NULL;
	tmp2->next = *stack_t;
	*stack_t = tmp2;
	(*stack_t)->prev = NULL;
	(*stack_t)->next->prev = *stack_t;
}

void	rra(t_stack **stack_a, int print)
{
	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	ps_rev_rotate(stack_a);
	if (print)
		ft_printf("rra\n");
}

void	rrb(t_stack **stack_b, int print)
{
	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	ps_rev_rotate(stack_b);
	if (print)
		ft_printf("rrb\n");
}

void	rrr(t_stack **stack_a, t_stack **stack_b, int print)
{
	ps_rev_rotate(stack_a);
	ps_rev_rotate(stack_b);
	if (print)
		ft_printf("rrr\n");
}
