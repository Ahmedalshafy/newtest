/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_math.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalshafy <aalshafy@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 13:50:11 by aalshafy          #+#    #+#             */
/*   Updated: 2024/02/07 10:18:52 by aalshafy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	*ps_put_in_arr(t_stack *stack)
{
	int		i;
	int		*array;
	t_stack	*tmp;

	array = (int *)malloc(sizeof(int) * stack_len(stack));
	tmp = stack;
	i = -1;
	while (tmp)
	{
		array[++i] = tmp->num;
		tmp = tmp->next;
	}
	return (array);
}

int	ps_partition(int *array, int start, int n)
{
	int	i;
	int	j;
	int	pivot;
	int	tmp;

	j = start;
	i = start - 1;
	pivot = array[n];
	while (j < n)
	{
		if (array[j] < pivot)
		{
			tmp = array[i + 1];
			array[i + 1] = array[j];
			array[j] = tmp;
			i++;
		}
		j++;
	}
	tmp = array[i + 1];
	array[i + 1] = array[n];
	array[n] = tmp;
	return (i);
}

void	ps_quick_sort(int *array, int start, int n)
{
	int	i;

	if (start < n)
	{
		i = ps_partition(array, start, n);
		ps_quick_sort(array, start, i);
		ps_quick_sort(array, i + 1, n);
	}
}
