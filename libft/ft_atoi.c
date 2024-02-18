/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalshafy <aalshafy@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:24:09 by aalshafy          #+#    #+#             */
/*   Updated: 2024/02/07 12:23:52 by aalshafy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_atoi(const char *str)
{
	int					sign;
	unsigned long long	n;

	sign = 1;
	n = 0;
	while (*str == '\n' || *str == '\t' || *str == ' ')
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str != 0 && *str >= 48 && *str <= 57)
	{
		n = (n * 10) + (*str - 48);
		str++;
	}
	if (n > INT_MAX && sign == 1)
		return (0);
	if (n - 1 > INT_MAX && sign == -1)
		return (0);
	return (n * sign);
}
