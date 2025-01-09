#include "../inc/fractol.h"

void	events_init(t_fractal *f)
{
	mlx_key_hook(f->mlx_win, key_handler, f);
	mlx_mouse_hook(f->mlx_win, mouse_handler, f);
	mlx_hook(f->mlx_win, 17, 1L << 0, close_handler, f);
}

int	key_handler(int keycode, t_fractal *f)
{
	if (keycode == 0x61)
		f->offset_x -= 0.25 * f->zoom;
	else if (keycode == 0x64)
		f->offset_x += 0.25 * f->zoom;
	else if (keycode == 0x77)
		f->offset_y -= 0.25 * f->zoom;
	else if (keycode == 0x73)
		f->offset_y += 0.25 * f->zoom;
	else if (keycode == 0x7a)
		f->i_max -= 25;
	else if (keycode == 0x78)
		f->i_max += 25;
	else if (keycode == 0x31)
		f->col = 0x204;
	else if (keycode == 0x32)
		f->col = 0xFCBE11;
	else if (keycode == 0x33)
		f->col = 0xE418C1;
	else if (keycode == 0x72)
		data_init(f);
	else if (keycode == 0xff1b)
		close_handler(f);
	render(f, f->func);
	return (0);
}

int	mouse_handler(int button, int x, int y, t_fractal *f)
{
	x += 0;
	y += 0;
	if (button == 0x4)
		f->zoom *= 0.9;
	else if (button == 0x5)
		f->zoom *= 1.1;
	render(f, f->func);
	return (0);
}

int	close_handler(t_fractal *f)
{
	mlx_destroy_image(f->mlx_ptr, f->img.img_ptr);
	mlx_destroy_window(f->mlx_ptr, f->mlx_win);
	mlx_destroy_display(f->mlx_ptr);
	free(f->mlx_ptr);
	exit(EXIT_SUCCESS);
}

int	error_handler(t_fractal *f)
{
	if (f->mlx_ptr)
	{
		if (f->mlx_win)
			mlx_destroy_window(f->mlx_ptr, f->mlx_win);
		if (f->img.img_ptr)
			mlx_destroy_image(f->mlx_ptr, f->img.img_ptr);
		mlx_destroy_display(f->mlx_ptr);
		free(f->mlx_ptr);
	}
	ft_putstr_fd(MEM_ERR, STDERR_FILENO);
	exit(EXIT_FAILURE);
}
