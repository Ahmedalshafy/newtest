/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalshafy <aalshafy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 09:20:07 by aalshafy          #+#    #+#             */
/*   Updated: 2023/12/22 11:00:29 by aalshafy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_puthex(unsigned int nb, char c)
{
	char	*base;
	int		count;

	if (c == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (nb < 16)
		return (ft_putchar(base[nb]));
	else
	{
		count = ft_puthex((nb / 16), c);
		return (count + ft_puthex((nb % 16), c));
	}
}

// int	main(void)
// {
// 	int	x = -2147483648;
// 	char *s = "Ahmed";
//     int y;

// 	// printf("%p\n", &x);
// 	// printf("%p\n", s);
//     // printf("%llu\n", s);
// 	y = ft_puthex(x);
//     printf("\n");
// 	printf("%i\n", y);
// }
