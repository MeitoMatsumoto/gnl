#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <string.h>
# include <strings.h>
# include <stdio.h>
# include <unistd.h>
# include <ctype.h>

char	*get_next_line(int fd);
int		put_line(char **line, char **save, char *buf);
size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_find_newline(char *str, char c);
char	*ft_strjoin(char *s1, char *s2, ssize_t size1, ssize_t size2);
char	*ft_strdup(const char *src);

#endif
