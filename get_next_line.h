#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <string.h>

int		get_next_line(int fd, char **line);
char	*get_line(char **buffer, int *flag);
char	*ft_firstline(char **str, int *keepgoing);
char	*ft_strjoin(char *s1, char *s2);
int		error(int fd, char *line);
int		is_newline(char *str);
char	*ft_strdup(char *str);
int		ft_strlen(char *str);

#endif
