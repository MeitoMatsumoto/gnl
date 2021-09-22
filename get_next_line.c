#include "get_next_line.h"

int	put_line(char **line, char **save, char *buf)
{
	int		flag;
	size_t	n;
	char	*tmp;

	n = ft_find_newline(buf, '\n');
	tmp = ft_strjoin(*line, buf, -1, n);
	if (tmp == NULL)
		return (-1);
	free(*line);
	*line = tmp;
	tmp = NULL;
	flag = 0;
	if (buf[n] == '\n')
	{
		tmp = ft_strdup(buf + n + 1);
		if (tmp == NULL)
			return (-1);
		flag = 1;
	}
	free(*save);
	*save = tmp;
	return (flag);
}

char	*free_all(char **line, char *save)
{
	free(line);
	free(*line);
	free(save);
	return (NULL);
}

char	*get_next_line(int fd)
{
	char		**line;
	char		*buf;
	static char	*save;
	ssize_t		rc;
	int			flag;

	line = (char **)malloc(2);
	*line = (char *)malloc(1);
	if (fd < 0)
		return (free_all(line, save));
	*line[0] = 0;
	flag = 0;
	if (save)
		flag = put_line(line, &save, save);
	buf = (char *)malloc(BUFFER_SIZE + 1);
	while (flag == 0 && (rc = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[rc] = '\0';
		flag = put_line(line, &save, buf);
	}
	free(buf);
	buf = NULL;
	if (rc < 0 || flag == -1)
		return (free_all(line, save));
	buf = *line;
	flag = ft_strlen(buf);
	free(line);
	if (save)
	{
		buf[flag] = '\n';
		buf[flag + 1] = '\0';
		return (buf);
	}
	if (buf[0] == '\0')
	{
		free(*line);
		return (NULL);
	}
	return (buf);
}
