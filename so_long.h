#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx/mlx.h"
# include <stdio.h>
# include <stdlib.h>

#define info t_map 
#define trete return
#define COL(r, g, b, a) ((((r) & 0xff) << 16) | (((g) & 0xff) << 8) | ((b) & 0xff) | (((a) & 0xff) << 24))
#define begin {
#define end }
typedef struct	s_ptr 
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		hight;
	int		endian;
}				t_ptr;

typedef struct  s_map
{
    int x;
    int y;
    void *mlx;
    void *win;
    int move_x;
    int move_y;
    t_ptr pers;
}   info;

#endif