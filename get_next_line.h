#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

int		get_next_line(int fd, char **line);
int		get_next_line_helper(char **str, int n, char **line, int fd);
char	*empty_str(char *str[5000], int fd);
int		update_read(int fd, char *buffer, int	*ptr);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif