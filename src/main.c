#include "../inc/fractol.h"

void	fractal_init(t_fractal *f)
{
	f->mlx_ptr = mlx_init();
	if (!f->mlx_ptr)
		error_handler(f);
	f->mlx_win = mlx_new_window(f->mlx_ptr, SIZE, SIZE, "fractol");
	f->img.img_ptr = mlx_new_image(f->mlx_ptr, SIZE, SIZE);
	if (!f->mlx_win || !f->img.img_ptr) 
		error_handler(f);
	f->img.pxl_ptr = mlx_get_data_addr(f->img.img_ptr, &f->img.bpp, &f->img.line_len, &f->img.endian);
	data_init(f);
	events_init(f);
}

int	main(int argc, char **argv)
{
	t_fractal	f;

	if (argc == 2 && argv[1][0] == 'm')
		f.func = mandelbrot;
	else if (argc == 4 && argv[1][0] == 'j')
	{
		f.func = julia;
		f.julia_r = ft_atof(argv[2]);
		f.julia_i = ft_atof(argv[3]);
	}
	else if (argc == 2 && argv[1][0] == 'b')
		f.func = burningship;
	else
		return (ft_putstr_fd(ARG_ERR, STDERR_FILENO), EXIT_FAILURE);
	fractal_init(&f);
	render(&f, f.func);
	mlx_loop(f.mlx_ptr);
	return (EXIT_SUCCESS);
}
