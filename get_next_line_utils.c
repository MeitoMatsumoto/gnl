#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int	len;

	len = 0;
	while (*(str++) != '\0')
	{
		len++;
	}
	return (len);
}

char	*ft_strdup(const char *src)
{
	char	*dest;
	int		index;

	index = 0;
	dest = malloc(ft_strlen((char *)src) + 1);
	if (!dest)
		return (dest);
	while (src[index])
	{
		dest[index] = src[index];
		index++;
	}
	dest[index] = 0;
	return (dest);
}

size_t	ft_find_newline(char *str, char c)
{
	size_t	i;

	i = 0;
	while (*str)
	{
		if (*str == c)
			return (i);
		i++;
		str++;
	}
	return (i);
}

char	*ft_strjoin(char *s1, char *s2, ssize_t size1, ssize_t size2)
{
	char	*str;
	size_t	size;
	int		i;
	int		j;

	if (size1 == -1)
		size1 = ft_strlen(s1);
	size = size1 + size2;
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (*s1 != '\0')
		str[i++] = *s1++;
	while (*s2 != '\0' && j < size2)
	{
		str[i++] = *s2++;
		j++;
	}
	str[i] = '\0';
	return (str);
}
