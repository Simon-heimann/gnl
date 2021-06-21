#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s && *s != (char)c)
		s++;
	if (*s == (char)c)
		return ((char *)s);
	return (0);
}

size_t	ft_strlen(const char *s)
{
	int		i;

	i = 0;
	while (*s++)
		i++;
	return ((size_t)i);
}

char	*ft_strdup(const char *s1)
{
	char	*sdup;
	size_t	i;

	sdup = malloc(ft_strlen(s1) + 1);
	if (!sdup)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		sdup[i] = s1[i];
		i++;
	}
	sdup[i] = '\0';
	return (sdup);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*str;
	size_t		a;
	size_t		b;
	int			i;

	if (!s1 || !s2)
		return (NULL);
	a = ft_strlen(s1);
	b = ft_strlen(s2);
	i = -1;
	str = malloc(sizeof(char) * (a + b + 1));
	if (!str)
		return (NULL);
	while (s1[++i])
		str[i] = s1[i];
	i = -1;
	while (s2[++i])
	{
		str[a] = s2[i];
		a++;
	}
	str[a] = '\0';
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (i < len)
	{
		str[i] = s[start];
		i++;
		start++;
	}
	str[len] = '\0';
	return (str);
}
