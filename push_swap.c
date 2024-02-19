/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalshafy <aalshafy@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 16:54:43 by aalshafy          #+#    #+#             */
/*   Updated: 2024/02/19 10:29:05 by aalshafy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	main(int ac, char *av[])
{
	char	**args;
	t_stack	*stack_a;

	if (ac < 2)
		return (0);
	args = ps_parsing(ac, av);
	if (!args)
		exit_error();
	stack_a = ps_stack(args);
	free_array(args);
	if (!stack_a)
		exit_error();
	if (ps_check_dup(stack_a) == 0)
	{
		ps_free_stack(stack_a);
		exit_error();
	}
	if (ps_is_sorted(stack_a))
		return (ps_free_stack(stack_a), 0);
	if (stack_len(stack_a) == 2)
	{
		sa(&stack_a, 1);
		return (ps_free_stack(stack_a), 0);
	}
	ps_init_ps(&stack_a);
}

void	ps_init_ps(t_stack **stack_a)
{
	t_stack	*stack_b;
	t_info	info;
	int		*array;

	array = ps_put_in_arr(*stack_a);
	if (!array)
	{
		ps_free_stack(*stack_a);
		exit_error();
	}
	ps_quick_sort(array, 0, stack_len(*stack_a) - 1);
	stack_b = NULL;
	ps_init_info(&info, array);
	if (stack_len(*stack_a) < 9)
	{
		ps_max_3(stack_a, &stack_b, info, stack_len(*stack_a));
		free(array);
		ps_free_stack(*stack_a);
		return ;
	}
	ps_max_chunck(stack_a, &stack_b, info, stack_len(*stack_a));
	free(array);
	ps_free_stack(*stack_a);
}

void	ps_init_info(t_info *info, int *array)
{
	info->min_ind = 0;
	info->l = 0;
	info->array = array;
}
