#include "../inc/fractol.h"

void	data_init(t_fractal *f)
{
	f->i_max = 100;
	f->offset_x = 0;
	f->offset_y = 0;
	f->zoom = 1.0;
	f->colour = 0x200;
}

void	mandelbrot(int x, int y, t_fractal *f)
{
	t_complex	z;
	t_complex	c;
	int			iter;
	int			colour;

	z.r = 0.0;
	z.i = 0.0;
	c.r = ft_interp(x, f->offset_x, f->zoom);
	c.i = ft_interp(y, f->offset_y, f->zoom);
	iter = 0;
	while (iter++ < f->i_max)
	{
		z = ft_sum(ft_sq(z), c);
		if ((z.r * z.r) + (z.i * z.i) > 4.0)
		{
			colour = iter * f->colour;
			ft_pxl_put(&f->img, x, y, colour);
			return ;
		}
	}
	ft_pxl_put(&f->img, x, y, 0);
}

void	julia(int x, int y, t_fractal *f)
{
	t_complex	z;
	t_complex	c;
	int			iter;
	int			colour;

	z.r = ft_interp(x, f->offset_x, f->zoom);
	z.i = ft_interp(y, f->offset_y, f->zoom);
	c.r = f->julia_r;
	c.i = f->julia_i;
	iter = 0;
	while (iter++ < f->i_max)
	{
		z = ft_sum(ft_sq(z), c);
		if ((z.r * z.r) + (z.i * z.i) > 4.0)
		{
			colour = iter * f->colour;
			ft_pxl_put(&f->img, x, y, colour);
			return ;
		}
	}
	ft_pxl_put(&f->img, x, y, 0);
}

void	burningship(int x, int y, t_fractal *f)
{
	t_complex	z;
	t_complex	c;
	int			iter;
	int			colour;

	z.r = 0.0;
	z.i = 0.0;
	c.r = ft_interp(x, f->offset_x, f->zoom);
	c.i = ft_interp(y, f->offset_y, f->zoom);
	iter = 0;
	while (iter++ < f->i_max)
	{
		z.r = fabs(z.r);
		z.i = fabs(z.i);
		z = ft_sum(ft_sq(z), c);
		if ((z.r * z.r) + (z.i * z.i) > 4.0)
		{
			colour = iter * f->colour;
			ft_pxl_put(&f->img, x, y, colour);
			return ;
		}
	}
	ft_pxl_put(&f->img, x, y, 0);
}

void	render(t_fractal *f, void (*func)(int, int, struct s_fractal*))
{
	int	x;
	int	y;

	y = -1;
	while (++y < SIZE)
	{
		x = -1;
		while (++x < SIZE)
			func(x, y, f);
	}
	mlx_put_image_to_window(f->mlx_ptr, f->mlx_win, f->img.img_ptr, 0, 0);
}
