#include "../inc/fdf.h"

int		calcul(t_m m)
{

}

void drawline(int x0, int y0, int x1, int y1)
{
    int dx;
	int dy;
	int p;
	int x;
	int	y;
 
	dx=x1-x0;
	dy=y1-y0;
 
	x=x0;
	y=y0;
 
	p=2*dy-dx;
 
	while (x<x1)
	{
		if (p>=0)
		{
			mlx_put_pixel(m->win, m->ptr, x, y, );
			y=y+1;
			p=p+2*dy-2*dx;
		}
		else
		{
			mlx_put_pixel(x,y,7);
			p=p+2*dy;
		}
		x=x+1;
	}
}
