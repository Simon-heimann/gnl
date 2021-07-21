/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sheimann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 16:40:54 by sheimann          #+#    #+#             */
/*   Updated: 2021/07/16 16:40:56 by sheimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int		i;

	i = 0;
	while (*s++)
		i++;
	return ((size_t)i);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s && *s != (char)c)
		s++;
	if (*s == (char)c)
		return ((char *)s);
	return (0);
}

char	*ft_strdup(const char *s)
{
	char	*str;
	size_t	index;

	str = (char *)malloc(sizeof(*str) * (ft_strlen(s) + 1));
	if (!str)
		return (NULL);
	index = 0;
	while (s[index])
	{
		str[index] = s[index];
		index++;
	}
	str[index] = s[index];
	return (str);
}

char	*ft_strcat(char *s1, const char *s2)
{
	int	a;

	a = ft_strlen(s1);
	while (*s2)
	{
		s1[a] = *s2;
		a++;
		s2++;
	}
	s1[a] = 0;
	return (s1);
}
