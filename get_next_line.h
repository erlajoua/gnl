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

int     ft_strlen(char *str);
void	ft_bzero(void *s, size_t n);

struct s_gnl
{
    char *reste;
    int nb_bytes;
};
typedef	struct s_gnl t_gnl;

#endif
