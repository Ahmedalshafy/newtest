/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_parsing_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalshafy <aalshafy@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 16:54:43 by aalshafy          #+#    #+#             */
/*   Updated: 2024/02/18 17:55:39 by aalshafy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

char	*ps_join(int ac, char **av)
{
	int		i;
	char	*str;

	i = 1;
	if (!ps_check_empty(av[i]))
		return (NULL);
	str = ft_strdup(av[i]);
	if (!str || !*str)
		return (NULL);
	while (++i < ac)
	{
		if (!ps_check_empty(av[i]))
			return (free(str), NULL);
		if (av[i] && (av[i][0] == ' ' || av[i][0] == '\t') && av[i][1] == '\0')
			return (free(str), NULL);
		str = ft_strjoin(str, av[i]);
		if (!str || !*str)
			return (NULL);
	}
	return (str);
}

int	ps_validate(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (!ft_isdigit(str[i]) && str[i] != '-' && str[i] != '+'
			&& str[i] != ' ')
			return (0);
		else if (ft_isdigit(str[i]) && (!ft_isdigit(str[i + 1])
				&& str[i + 1] != ' ' && str[i + 1]))
			return (0);
		else if ((str[i] == '-' || str[i] == '+') && (!str[i + 1]
				|| !ft_isdigit(str[i + 1])))
			return (0);
		else if (str[i] == ' ' && str[i + 1] && (str[i + 1] != ' '
				&& !ft_isdigit(str[i + 1]) && str[i + 1] != '-')
			&& str[i + 1] != '+')
			return (0);
	}
	return (1);
}

int	ps_check_dup(char **arr)
{
	int	i;
	int	j;

	i = -1;
	while (arr[++i])
	{
		j = i;
		while (arr[++j])
			if (ft_strcmp(arr[i], arr[j]) == 0)
				return (0);
	}
	return (1);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (!s1[i] && !s2[i])
		return (0);
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}
