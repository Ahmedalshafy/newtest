/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_parsing_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalshafy <aalshafy@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 17:27:19 by aalshafy          #+#    #+#             */
/*   Updated: 2024/02/18 17:28:02 by aalshafy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	exit_error(void)
{
	write(2, "Error\n", ft_strlen("Error\n"));
	exit(1);
}

void	free_array(char **arr)
{
	int	i;

	i = -1;
	while (arr[++i])
		free(arr[i]);
	free(arr);
}

char	**ps_parsing(int ac, char *av[])
{
	char	*str;
	char	**args;

	str = ps_join(ac, av);
	if (!str || !*str)
		return (NULL);
	if (ps_validate(str) == 0)
		return (free(str), NULL);
	args = ft_split(str, ' ');
	if (!args)
		return (free(str), NULL);
	free(str);
	return (args);
}

int	ps_check_0(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] != '\0' && str[i] == '0')
	{
		if (str[i + 1] == '\0')
			return (0);
		i++;
	}
	return (1);
}

int	ps_check_empty(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != ' ')
			return (1);
		i++;
	}
	return (0);
}
