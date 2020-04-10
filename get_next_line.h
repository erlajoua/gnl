#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

int     ft_strlen(char *str);
void	ft_bzero(void *s, size_t n);

struct s_gnl
{
    char *reste;
    int nb_bytes;
};
typedef	struct s_gnl t_gnl;

#endif