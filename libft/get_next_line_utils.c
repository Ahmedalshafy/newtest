/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalshafy <aalshafy@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 12:02:15 by aalshafy          #+#    #+#             */
/*   Updated: 2024/02/05 17:24:04 by aalshafy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*new;
	int		s1len;
	int		s2len;
	int		i;
	int		j;

	if (s2 == NULL)
		return (s1);
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	if (checkln(s2) != -1 && checkln(s2) != 0)
		s2len = checkln(s2) + 1;
	new = (char *) malloc(s1len + s2len + 1);
	if (new == NULL)
		return (free(s1), NULL);
	i = -1;
	while (s1[++i] != 0)
		new[i] = s1[i];
	j = -1;
	while (s2[++j] != 0 && s2[j] != '\n')
		new[i++] = s2[j];
	if (s2[j] == '\n')
		new[i++] = '\n';
	new[i] = '\0';
	return (free(s1), new);
}

int	checkln(char *buffer)
{
	int	i;

	i = -1;
	if (!buffer[0])
		return (-1);
	while (buffer[++i])
	{
		if (buffer[i] == '\n')
			return (i);
	}
	return (-1);
}

void	buffer_edit(char *buffer)
{
	int		j;
	int		u;
	int		i;

	j = checkln(buffer);
	i = ft_strlen(buffer);
	u = -1;
	if (j != -1 && j != i - 1)
	{
		while (++j < i)
			buffer[++u] = buffer[j];
	}
	buffer[++u] = 0;
}
