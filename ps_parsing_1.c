/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_parsing_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalshafy <aalshafy@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 16:54:43 by aalshafy          #+#    #+#             */
/*   Updated: 2024/02/19 11:14:13 by aalshafy         ###   ########.fr       */
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
	str = ps_strdup(av[i]);
	if (!str || !*str)
		return (NULL);
	while (++i < ac)
	{
		if (!ps_check_empty(av[i]))
			return (free(str), NULL);
		if (av[i] && (av[i][0] == ' ') && av[i][1] == '\0')
			return (free(str), NULL);
		str = ps_strjoin(str, av[i]);
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
		else if (ft_isdigit(str[i]) && (str[i + 1] && !ft_isdigit(str[i + 1])
				&& str[i + 1] != ' '))
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

int	ps_check_dup(t_stack *stack)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	tmp = stack;
	while (tmp)
	{
		tmp2 = tmp->next;
		while (tmp2)
		{
			if (tmp->num == tmp2->num)
				return (0);
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
	return (1);
}

char	*ps_strjoin(char *s1, char *s2)
{
	char	*new;
	int		s1len;
	int		s2len;
	int		i;
	int		j;

	if ((s1 == 0 && s2 == 0) || *s2 == 0)
		return (NULL);
	s1len = ps_strlen(s1);
	s2len = ps_strlen(s2);
	new = (char *) malloc(s1len + s2len + 2);
	if (new == 0)
		return (NULL);
	i = -1;
	j = -1;
	while (s1[++i] != 0)
		ps_cpy_char(s1[i], s1[i + 1], new, &j);
	new[++j] = ' ';
	i = -1;
	while (s2[++i] != 0)
		ps_cpy_char(s2[i], s2[i + 1], new, &j);
	new[++j] = '\0';
	return (free(s1), new);
}
