#include "so_long.h"

void	valid_name(char *argv)
{
	char *point;

	point = ft_strnstr(argv, ".ber", ft_strlen(argv)+1);
	if(point)
		if(ft_strlen(point) == 4)
			return ;
	ft_error("Error FD\n");
}

int		valid_str(char *buf, int i, int *k)
{ 
	int o;

	if(i == -1)
		ft_error("GNL Error\n");
	o = ft_strlen_join(buf, NULL);
	if(o == 0)
	{
		free(buf);
		return (0);
	}
	*k = o; 
	return (1);
}

void	count_strings(int fd, int *height, int *width)
{
	int		i;
	char	*buf;
	int		k;
	int		temp;
	int		flag;

	temp = 0;
	k = 0;
	i = 1;
	flag = 0;
	while(i != 0)
	{
		temp = k;
		i = get_next_line(fd, &buf);
		if(!valid_str(buf, i, &k))
			continue ;
		if(k != temp && temp!=0 && k != 0)
			ft_error("Don't valid map\n");
		(*height)++;
		free(buf);
	}
	*width = k;
	close(fd);
}

void		pull_line(t_map *s, int fd, int width)
{
	int		i;
	short	res;
	char	*line;
	int		nul;

	line = NULL;
	i = 0;
	res = 1;
	nul = 0;
	while (res != 0 && width != i)
	{
		res = get_next_line(fd, &line);
		if (res == -1)
			ft_error("Error 2res GNL");
		if(!valid_str(line, res, &nul))
			continue ;
		s->map[i++] = line;
	}
	s->map[i] = NULL;
	close(fd);
}

void	check_fd(char *argv, void *s1)
{
	int		fd;
	t_map	*s;
	int		i = 0;

	s = s1;
	valid_name(argv);
	s->height = 0;
	s->width = 0;
	fd = open((const char *)argv, O_RDWR);
	if(fd < 0)
		ft_error("Error Don't open\n");
	count_strings(fd, &s->height, &s->width);
	s->map = malloc(sizeof(s->map) * (s->height));
	fd = open((const char *)argv, O_RDWR);
	if(fd < 0)
		ft_error("Error Don't open\n");
	printf("height - %d\nwidth - %d\n", s->height, s->width);
	pull_line(s, fd, s->width);
	while (s->map[i] != NULL)
	{
		write(1, s->map[i++], s->width);
		write(1, "\n", 1);
	}
	valid_element(s);
}
