/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_parsing_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalshafy <aalshafy@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 16:54:43 by aalshafy          #+#    #+#             */
/*   Updated: 2024/02/19 11:14:31 by aalshafy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	ps_strlen(char *str)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ' ' && (str[i + 1] == ' '))
			i++;
		else
		{
			len++;
			i++;
		}
	}
	return (len);
}

char	*ps_strdup(char *src)
{
	char	*dest;
	int		i;
	int		j;

	dest = (char *)malloc(sizeof(char) * (ps_strlen(src) + 2));
	if (!dest)
		return (NULL);
	i = -1;
	j = -1;
	while (src[++i])
	{
		if (src[i] == ' ' && (src[i + 1] == ' ' || src[i + 1] == '\0'))
			continue ;
		else
		{
			dest[++j] = src[i];
		}
	}
	dest[++j] = '\0';
	return (dest);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	ps_cpy_char(char s1, char s2, char *dest, int *j)
{
	if (s1 == ' ' && (s2 == ' ' || s2 == '\0'))
		return ;
	else
		dest[++(*j)] = s1;
}
