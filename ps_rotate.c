/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalshafy <aalshafy@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 12:05:38 by aalshafy          #+#    #+#             */
/*   Updated: 2024/02/07 15:03:33 by aalshafy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	ps_rotate(t_stack **stack_t)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	if (*stack_t == NULL || (*stack_t)->next == NULL)
		return ;
	tmp = *stack_t;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp2 = *stack_t;
	*stack_t = (*stack_t)->next;
	(*stack_t)->prev = NULL;
	tmp->next = tmp2;
	tmp2->next = NULL;
	tmp2->prev = tmp;
}

void	ra(t_stack **stack_a, int print)
{
	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	ps_rotate(stack_a);
	if (print)
		ft_printf("ra\n");
}

void	rb(t_stack **stack_b, int print)
{
	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	ps_rotate(stack_b);
	if (print)
		ft_printf("rb\n");
}

void	rr(t_stack **stack_a, t_stack **stack_b, int print)
{
	ps_rotate(stack_a);
	ps_rotate(stack_b);
	if (print)
		ft_printf("rr\n");
}
