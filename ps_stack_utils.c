/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalshafy <aalshafy@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 18:49:08 by aalshafy          #+#    #+#             */
/*   Updated: 2024/02/18 17:36:29 by aalshafy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

t_stack	*ps_stack(char **args)
{
	t_stack	*stack_a;
	int		i;
	int		j;

	i = 0;
	stack_a = ps_stack_first(args[i]);
	if (!stack_a)
		return (NULL);
	while (args[++i])
	{
		if (ps_check_0(args[i]) == 0)
			j = 0;
		else
		{
			j = ft_atoi(args[i]);
			if (j == 0)
				return (ps_free_stack(stack_a), NULL);
		}
		add_to_stack(stack_a, j);
		if (!stack_a)
			return (NULL);
	}
	return (stack_a);
}

t_stack	*ps_stack_first(char *str)
{
	t_stack	*head;

	head = malloc(sizeof(t_stack));
	if (!head)
		return (NULL);
	if (ps_check_0(str) == 0)
		head->num = 0;
	else
	{
		head->num = ft_atoi(str);
		if (head->num == 0)
			return (free(head), NULL);
	}
	head->next = NULL;
	head->prev = NULL;
	return (head);
}

void	add_to_stack(t_stack *stack, int num)
{
	t_stack	*head;
	t_stack	*to_add;

	head = stack;
	while (head->next != NULL)
		head = head->next;
	to_add = malloc(sizeof(t_stack));
	if (!to_add)
	{
		ps_free_stack(stack);
		return ;
	}
	to_add->num = num;
	to_add->next = NULL;
	to_add->prev = head;
	head->next = to_add;
}

void	ps_free_stack(t_stack *stack)
{
	t_stack	*head;
	t_stack	*tmp;

	head = stack;
	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}
