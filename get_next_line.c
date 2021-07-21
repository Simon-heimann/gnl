/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sheimann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 16:40:40 by sheimann          #+#    #+#             */
/*   Updated: 2021/07/16 16:40:47 by sheimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*gnl_strjoin(char *res, char const *buffer)
{
	char	*dest;

	if (!res || !buffer)
	{
		if (!res && !buffer)
			return (NULL);
		else if (res)
			return (ft_strdup(res));
		else if (buffer)
			return (ft_strdup(buffer));
	}
	dest = malloc(sizeof(*dest) * (ft_strlen(res) + ft_strlen(buffer) + 1));
	if (!dest)
		return (NULL);
	dest[0] = '\0';
	ft_strcat(dest, res);
	ft_strcat(dest, buffer);
	if (res)
		free(res);
	return (dest);
}

char	*gnl_strdup(char *str)
{
	int		i;
	int		totsize;
	char	*line;

	totsize = 0;
	while (str[totsize] != '\n' && str[totsize] != '\0')
		totsize++;
	line = (char *)malloc(sizeof(char) * (totsize + 1));
	if (!line)
		return (NULL);
	i = -1;
	while (++i < totsize + 1)
		line[i] = str[i];
	line[i] = '\0';
	return (line);
}

void	get_remaining_txt(char *buffer)
{
	size_t	i;
	int		j;

	i = 0;
	j = 0;
	while (buffer[i] != '\n')
		i++;
	i = i + 1;
	while (i < BUFFER_SIZE)
	{
		buffer[j] = buffer[i];
		j++;
		i++;
	}
	buffer[j] = '\0';
}

char	*get_next_line_2(size_t nbytes, char *res, char *buffer)
{
	char	*temp;

	temp = NULL;
	if (*res == '\0')
	{
		free(res);
		return (NULL);
	}
	temp = gnl_strdup(res);
	free(res);
	if (nbytes > 0)
		get_remaining_txt(buffer);
	return (temp);
}

char	*get_next_line(int fd)
{
	size_t		nbytes;
	char		*res;
	static char	buffer[BUFFER_SIZE];

	if (BUFFER_SIZE <= 0 || read(fd, buffer, 0) == -1 || BUFFER_SIZE > INT_MAX)
		return (NULL);
	res = NULL;
	res = gnl_strjoin(res, buffer);
	nbytes = 1;
	while (nbytes > 0 && ft_strchr(res, '\n') == 0)
	{
		nbytes = read(fd, buffer, BUFFER_SIZE);
		if (nbytes < 0)
		{
			free(res);
			return (NULL);
		}
		buffer[nbytes] = '\0';
		res = gnl_strjoin(res, buffer);
	}
	res = get_next_line_2(nbytes, res, buffer);
	return (res);
}
