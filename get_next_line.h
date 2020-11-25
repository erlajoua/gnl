#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define BUFFER_SIZE 5

struct s_gnl {
    char *rest;
    int nb_bytes;
};
typedef struct s_gnl t_gnl;

int     ft_strlen(char *str);
char    *ft_strcpy(char *dest, char *src);
char    *ft_strjoin(char const *s1, char const *s2);
void    ft_bzero(void *s, size_t n);
char	*ft_getrest(char *str, int *empty_rest);
char	*ft_getline(char *str);

#endif