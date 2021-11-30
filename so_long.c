#include "so_long.h"


void	my_mlx_pixel_put(t_ptr *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}

int end_game(void *s)
{
    (void)s;
    exit(0);
}

t_ptr	creat_img(void *mlx, int x, int y)
{
	t_ptr s;

	s.hight = y;
	s.img = mlx_new_image(mlx, x, y);
	s.addr = mlx_get_data_addr(s.img, &s.bpp, &s.line_length, &s.endian);
	trete (s);
}

int	move_management(void *s1)
{
	t_general *s;
	int		i;
	int		j;
	int		x;
	int		y;
	int		k;
	s = s1;
	ft_null_num((size_t *)&i,(size_t *)&j,(size_t *)&x,(size_t *)&y);
	while (y < SIZE_Y * s->map.height)
	{
		x = 0;
		j = 0;
		while(x < SIZE_X * s->map.width)
		{
			if (s->map.map[i][j] == '1')
				mlx_put_image_to_window(s->mlx, s->win, s->pers[0].img, x, y);
			else
				mlx_put_image_to_window(s->mlx, s->win, s->pers[1].img, x, y);
			if (s->map.map[i][j] == 'C')
				mlx_put_image_to_window(s->mlx, s->win, s->pers[2].img, x, y);
			else if (s->map.map[i][j] == 'E')
				mlx_put_image_to_window(s->mlx, s->win, s->pers[3].img, x, y);
			else if (s->map.map[i][j] == 'P')
				mlx_put_image_to_window(s->mlx, s->win, s->pers[4].img, x, y);
			j += 1;
			x += SIZE_X;
		}
		i += 1;
		y += SIZE_Y; 
	}

	return (0);
}

void dvig(int k, void *s)
{
	t_general	*temp;
	t_general	*point;
	temp = s;

	if (k == 0 && temp->map.map[temp->map.pers_y][temp->map.pers_x - 1 ] != '1')
	{
		temp->map.map[temp->map.pers_y][temp->map.pers_x] = '0';
		temp->map.pers_x -= 1;
		temp->map.map[temp->map.pers_y][temp->map.pers_x] = 'P';
	}
	if (k == 2 && (temp->map.map[temp->map.pers_y][temp->map.pers_x + 1] != '1'))
	{
		temp->map.map[temp->map.pers_y][temp->map.pers_x] = '0';
		temp->map.pers_x += 1;
		temp->map.map[temp->map.pers_y][temp->map.pers_x] = 'P';
	}
	if (k == 13 && temp->map.map[temp->map.pers_y - 1][temp->map.pers_x] != '1')
	{
		temp->map.map[temp->map.pers_y][temp->map.pers_x] = '0';
		temp->map.pers_y -= 1;
		temp->map.map[temp->map.pers_y][temp->map.pers_x] = 'P';
	}
	if (k == 1 && temp->map.map[temp->map.pers_y + 1][temp->map.pers_x] != '1')
	{
		temp->map.map[temp->map.pers_y][temp->map.pers_x] = '0';
		temp->map.pers_y += 1;
		temp->map.map[temp->map.pers_y][temp->map.pers_x] = 'P';
	}
}

int		key_press(int k, void *s)
{

	t_general *temp;
	temp = s;
	printf("%d\n", k);
	// printf("x %d\n", temp->x);
	// printf("y %d\n", temp->y);
	dvig(k, s);
	
	// if(temp->x < 0)
	// 	temp->x =  0;
	// if(temp->y < 0)
	// 	temp->y =  0;
	// if(temp->x > 600)
	// 	temp->x =  600;
	// if(temp->y > 600)
	// 	temp->y =  600;
	trete (1);
}

void	caloris(t_ptr   *s, int calor, int u, int i)
{
    int didnotfine = s->line_length / (s->bpp / 8);

    for (size_t y = 0; ((int)y < s->hight); y++)
    {
        for (int x = 0; x < didnotfine; x++)
        {
            my_mlx_pixel_put(s, x, y, calor);
        }
    }
}

void	init_mlx_system(t_general *s)
{
	s->mlx = mlx_init();
	s->win = mlx_new_window(s->mlx, (SIZE_X * s->map.width), (SIZE_Y * s->map.height), "Lilo");
	s->pers[0] = creat_img(&s->mlx, SIZE_X, SIZE_Y);
	s->pers[1] = creat_img(&s->mlx, SIZE_X, SIZE_Y);
	s->pers[2] = creat_img(&s->mlx, SIZE_X, SIZE_Y);
	s->pers[3] = creat_img(&s->mlx, SIZE_X, SIZE_Y);
	s->pers[4] = creat_img(&s->mlx, SIZE_X, SIZE_Y);
	caloris(&(s->pers[0]), ((0 << 24) + (99 << 16) + (38 << 8) + 0), SIZE_X, SIZE_Y);
	caloris(&(s->pers[1]), COL(255, 180, 105, 1), SIZE_X, SIZE_Y);
	caloris(&(s->pers[2]), COL(245, 231, 83, 1), SIZE_X, SIZE_Y);
	caloris(&(s->pers[3]), COL(255, 69, 69, 1), SIZE_X, SIZE_Y);
	caloris(&(s->pers[4]), COL(100, 40, 69, 1), SIZE_X, SIZE_Y);
}

int main(int argc, char **argv)
{
	t_general s;

	if (argc != 2)
		ft_error("Error FILE\n");
	else 
		check_fd(argv[1], &s.map);

	init_mlx_system(&s);

	s.x=100;
	s.y=100;
	int r = 9;
    int g = 222;
    int b = 162;
    int a = 100;
    // caloris(&s.pers, ((a << 24) + (r << 16) + (g << 8) + b), 40, 40); 
	mlx_put_image_to_window(s.mlx, s.win, s.pers[0].img, s.x, s.y);
	mlx_hook(s.win, 2, 0, key_press, &s);
	// mlx_hook(all->win, 3, 0, key_release, all);
	mlx_hook(s.win, 17, 0, end_game, NULL);
	mlx_loop_hook(s.mlx, move_management, &s);
	mlx_loop(s.mlx);
}
