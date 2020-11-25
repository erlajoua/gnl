#include "get_next_line.h"

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

char *ft_strjoin(char const *s1, char const *s2)
{
    char *str1;
    char *str2;
    char *dest;
    int i;
    int j;

    if (!s1 || !s2)
        return (NULL);
    str1 = (char *)s1;
    str2 = (char *)s2;
    i = -1;
    j = -1;
    if (!(dest = malloc(sizeof(char *) * (ft_strlen(str1) + ft_strlen(str2)))))
        return (NULL);
    while (str1[++i])
        dest[i] = str1[i];
    while (str2[++j])
        dest[i + j] = str2[j];
    dest[i + j] = '\0';
    return (dest);
}

char *ft_strcpy(char *dest, char *src)
{
    int i;

    i = 0;
    while (src[i])
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = src[i];
    return (dest);
}

void ft_bzero(void *s, size_t n)
{
    unsigned char *ptr;

    ptr = (unsigned char *)s;
    while (n > 0)
    {
        *(ptr++) = 0;
        n--;
    }
}

char *ft_get_subline(char *buffer)
{
    int i;
    char *dest;

    i = 0;
    while (buffer[i] != '\n' && buffer[i])
        i++;
    dest = (char *)malloc(sizeof(char) * i + 1);
    i = 0;
    while (buffer[i] != '\n' && buffer[i])
    {
        dest[i] = buffer[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}

char *ft_get_rest(char *buffer)
{
    int i;

    i = 0;
    while (buffer[i] != '\0')
    {
        if (buffer[i] == '\n')
            return (&buffer[i + 1]);
        i++;
    }
    return (0);
}

static int ft_read(int fd, t_gnl *p, char **line)
{
    char *buffer;
    char *rest;
    char *subline;
    buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
    ft_bzero(buffer, BUFFER_SIZE + 1);
    *line = malloc(sizeof(char *) * 1);
    *line[0] = '\0';
    while (1)
    {
        if (p->reste)
        {
            buffer = ft_strcpy(buffer, p->reste);
            p->reste = NULL;
        }
        else
        {
            p->nb_bytes = read(fd, buffer, BUFFER_SIZE);
            if (p->nb_bytes == 0)
                return (0);
            else if (p->nb_bytes < 0)
                return (-1);
        }
        rest = ft_get_rest(buffer);
        if (rest == 0)
            *line = ft_strjoin(*line, buffer);
        else
        {
            subline = ft_get_subline(buffer);
            *line = ft_strjoin(*line, subline);
            p->reste = rest;
            break;
        }
        if (p->nb_bytes > 0 || p->reste)
            return (1);
        return (0);
    }
}

int get_next_line(int fd, char **line)
{
    static t_gnl p;
    int ret;

    if (fd < 0 || BUFFER_SIZE < 1)
        return (-1);
    ret = ft_read(fd, &p, line);
    return (ret);
}

/*int main(void)
{
    int fd;
    int ret;
    char *line;

    fd = open("test.txt", O_RDONLY);
    if (!fd)
        return (-1);
    while ((ret = get_next_line(fd, &line)) > 0)
    {
        printf("%d -> %s\n", ret, line);
    }
    close(fd);
    return (0);
}*/
