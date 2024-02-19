/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_main_checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalshafy <aalshafy@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 16:54:43 by aalshafy          #+#    #+#             */
/*   Updated: 2024/02/07 16:20:41 by aalshafy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	main(int ac, char *av[])
{
	char	**args;
	t_stack	*stack_a;

	args = ps_parsing(ac, av);
	if (!args)
		exit_error();
	stack_a = ps_stack(args);
	free_array(args);
	if (!stack_a)
		exit_error();
	ps_read(&stack_a);
	ps_free_stack(stack_a);
}

void	ps_read(t_stack **stack_a)
{
	t_stack	*stack_b;
	char	*line;

	stack_b = NULL;
	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		ps_excute_ins(stack_a, &stack_b, line);
	}
	if (ps_is_sorted(*stack_a) && !stack_b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

void	ps_excute_ins(t_stack **stack_a, t_stack **stack_b, char *line)
{
	if (ft_strcmp(line, "sa\n") == 0)
		sa(stack_a, 0);
	else if (ft_strcmp(line, "sb\n") == 0)
		sb(stack_b, 0);
	else if (ft_strcmp(line, "ss\n") == 0)
		ss(stack_a, stack_b, 0);
	else if (ft_strcmp(line, "pa\n") == 0)
		pa(stack_a, stack_b, 0);
	else if (ft_strcmp(line, "pb\n") == 0)
		pb(stack_a, stack_b, 0);
	else
		ps_excute_ins_2(stack_a, stack_b, line);
	free(line);
}

void	ps_excute_ins_2(t_stack **stack_a, t_stack **stack_b, char *line)
{
	if (ft_strcmp(line, "ra\n") == 0)
		ra(stack_a, 0);
	else if (ft_strcmp(line, "rb\n") == 0)
		rb(stack_b, 0);
	else if (ft_strcmp(line, "rr\n") == 0)
		rr(stack_a, stack_b, 0);
	else if (ft_strcmp(line, "rra\n") == 0)
		rra(stack_a, 0);
	else if (ft_strcmp(line, "rrb\n") == 0)
		rrb(stack_b, 0);
	else if (ft_strcmp(line, "rrr\n") == 0)
		rrr(stack_a, stack_b, 0);
	else
	{
		free(line);
		ps_free_stack(*stack_a);
		exit_error();
	}
}
