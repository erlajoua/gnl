#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str1;
	char	*str2;
	char	*dest;
	int		i;
	int		j;

	i = -1;
	j = 0;
	if (!s2)
		return (NULL);
	if (!s1)
	{
		s1 = malloc(1);
		s1[0] = '\0';
	}
	str1 = (char *)s1;
	str2 = (char *)s2;
	if (!(dest = (char *)malloc(ft_strlen(str1) + ft_strlen(str2) + 1)))
		return (NULL);
	while (str1[++i])
		dest[i] = str1[i];
	while (str2[j])
	{
		dest[i + j] = str2[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

char	*ft_firstline(char **str, int *keepgoing)
{
	char	*line;
	char	*newdata;
	size_t	i;

	i = 0;
	while ((*str)[i] && (*str)[i] != '\n')
		i++;
	if (!(line = (char*)malloc(sizeof(char) * (i + 1))))
		return (0);
	i = 0;
	while ((*str)[i] && (*str)[i] != '\n')
	{
		line[i] = (*str)[i];
		i++;
	}
	line[i] = '\0';
	if ((*str)[i] == '\n')
	{
		i++;
		*keepgoing = 1;
	}
	newdata = ft_strdup(*str + i);
	free(*str);
	*str = newdata;
	return (line);
}

char	*get_line(char **buffer, int *flag)
{
	int		i;
	char	*dest;
	char	*tmp;
	char	*tmp2;

	i = 0;
	tmp = *buffer;
	tmp2 = *buffer;
	*flag = 0;
	while (tmp[i] != '\n' && tmp[i])
		i++;
	dest = malloc(i + 1);
	i = -1;
	while (tmp[++i] != '\n' && tmp[i])
		dest[i] = tmp[i];
	dest[i] = '\0';
	if (tmp[i] == '\n')
	{
		*flag = 1;
		i++;
	}
	tmp2 = ft_strdup(&tmp[i]);
	free(*buffer);
	*buffer = tmp2;
	return (dest);
}

int		get_next_line(int fd, char **line)
{
	static char		*buffer = 0;
	char			*reading;
	int				ret;
	int				flag;

	ret = 0;
	reading = malloc(BUFFER_SIZE + 1);
	bzero(reading, BUFFER_SIZE + 1);
	if (error(fd, *line))
		return (-1);
	if (!is_newline(buffer))
	{
		while ((ret = read(fd, reading, BUFFER_SIZE)) > 0)
		{
			reading[BUFFER_SIZE] = 0;
			buffer = ft_strjoin(buffer, reading);
			if (is_newline(buffer))
				break ;
		}
	}
	*line = get_line(&buffer, &flag);
	return (!ret && !flag) ? 0 : 1;
}

/*int		main(void)
{
	int fd = 0;
	int ret = 0;
	char *line;

	line = malloc(1);
	line[0] = '\0';
	fd = open("texte", O_RDONLY);
	if (!fd)
		return (-1);
	while (ret = ft_get_next_line(fd, &line) > 0)
		printf("%d -> %s\n", ret, line);
	return (0);
}*/
