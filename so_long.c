#include "so_long.h"


void	my_mlx_pixel_put(t_ptr *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}

t_ptr   creat_img(void *mlx, int x, int y)
{
    t_ptr s;

    s.hight = y;
    s.img = mlx_new_image(mlx, x, y);
    s.addr = mlx_get_data_addr(s.img, &s.bpp, &s.line_length, &s.endian);
    trete (s);
}

void    caloris(t_ptr   *s, int calor, int sdvig)
{
    int didnotfine = s->line_length / (s->bpp / 8);
    for (size_t y = 0; ((int)y < s->hight); y++)
    {
        if(y % 10 == 0)
            calor <<=sdvig;
        for (int x = 0; x < didnotfine; x++)
        {
            if (y < 30)
                my_mlx_pixel_put(s, x, y, calor);
            else if (y > 29 && y < 70 && x > 40 && x < 61)
                my_mlx_pixel_put(s, x, y, calor);
            else if (y > 69 && y < 80)
                my_mlx_pixel_put(s, x, y, calor);
            else if (y > 79 && y <= 100 && x > 40 && x < 61)
                my_mlx_pixel_put(s, x, y, calor);
            else 
                my_mlx_pixel_put(s, x, y, 0xff000000);
        }
    }
}

int end_game(void *s)
{
    (void)s;
    exit(0);
}

void dvig(int k, void *s)
{
    t_general *temp;
    temp = s;

    if (k == 0)
        temp->x -= 15;
    if (k == 2)
        temp->x += 15;
    if (k == 13)
        temp->y -= 15;
    if (k == 1)
        temp->y += 15;
}

int key_press(int k, void *s)
{

    t_general *temp;
    temp = s;
    printf("%d\n", k);
    printf("x %d\n", temp->x);
    printf("y %d\n", temp->y);
    dvig(k, s);    
    mlx_clear_window(temp->mlx, temp->win);
    mlx_put_image_to_window(temp->mlx, temp->win, temp->pers.img, temp->x, temp->y);
    if(temp->x < 0)
        temp->x =  0;
    if(temp->y < 0)
        temp->y =  0;
    if(temp->x > 600)
        temp->x =  600;
    if(temp->y > 600)
        temp->y =  600;
    trete (1);
}

int main(int argc, char **argv)
{
    t_general s;

    if (argc != 2)
        ft_error("Error FILE\n");
    else 
        check_fd(argv[1], &s.map);
    
    return (write(1, "1\n", 2));
    s.mlx = mlx_init();
    s.win = mlx_new_window(s.mlx, 700, 700, "Lilo");
    s.pers = creat_img(s.mlx, 100, 100);
    t_general   lost;

    lost.x=100;
    lost.y=100;

    lost.mlx = s.mlx;
    lost.win = s.win;
    int r = 9;
    int g = 222;
    int b = 162;
    int a = 100;
    caloris(&s.pers, ((a << 24) + (r << 16) + (g << 8) + b), 0); 
    lost.pers = s.pers;
    mlx_hook(s.win, 2, 0, key_press, &lost);
	// mlx_hook(all->win, 3, 0, key_release, all);
	mlx_hook(s.win, 17, 0, end_game, NULL);
	// mlx_loop_hook(all->mlx, move_management, all);
	mlx_loop(s.mlx);
}

