#include "get_next_line.h"

int	get_next_line_helper(char **str, int i, char **line, int fd)
{
	char	*temp;
	int		nwline;

	nwline = 0;
	while (str[fd][nwline] && str[fd][nwline] != '\n')
		nwline++;
	*line = ft_substr(str[fd], 0, nwline);
	if (str[fd][nwline] == '\n')
	{
		temp = str[fd];
		str[fd] = ft_strdup((str[fd]) + (nwline + 1));
		free(temp);
	}
	else
	{
		temp = str[fd];
		str[fd] = NULL;
		free(temp);
		return (0);
	}
	if (!str[fd] || !*line)
		return (-1);
	if ((i == 0 && str[fd]) || i)
		return (1);
	return (-1);
}

char	*empty_str(char *str[OPEN_MAX], int fd)
{
	return (str[fd] = ft_strdup(""));
}

int	update_read(int fd, char *buffer, int	*ptr)
{
	*ptr = read(fd, buffer, BUFFER_SIZE);
	if (!*ptr)
		return (0);
	return (1);
}

int	get_next_line(int fd, char **line)
{
	int				i;
	int				*ptr;
	static char		*buffer;
	char			*str[OPEN_MAX];
	char			*mem;

	ptr = &i;
	if (!line || fd < 0 || fd >= OPEN_MAX
		|| read(fd, buffer, 0) == -1 || BUFFER_SIZE <= 0)
		return (-1);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!str[fd] || !buffer)
		if (!empty_str(str, fd) || !buffer)
			return (-1);
	while (update_read(fd, buffer, ptr))
	{
		mem = str[fd];
		buffer[i] = '\0';
		str[fd] = ft_strjoin(str[fd], buffer);
		free (mem);
		if (ft_strchr(str[fd], '\n'))
			break ;
	}
	free (buffer);
	return (get_next_line_helper(str, i, line, fd));
}
