#pragma once

#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <mlx.h>

#define SIZE   800

#define ARG_ERR    "Invalid argument:\n\
 >  [m]andelbrot\n\
 >  [j]ulia <real> <imaginary>\n\
 >  [b]urningship\n"
#define MEM_ERR    "Memory error\n"

typedef struct s_complex
{
	double	r;
	double	i;
}	t_complex;

typedef struct s_img
{
	void	*img_ptr;
	char	*pxl_ptr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_fractal
{
	void	*mlx_ptr;
	void	*mlx_win;
	t_img	img;

	void	(*func)(int, int, struct s_fractal*);
	double	julia_r;
	double	julia_i;

	int		i_max;
	double	offset_x;
	double	offset_y;
	double	zoom;
	int		col;
}	t_fractal;

// main.c
void		fractal_init(t_fractal *f);

// render.c
void		data_init(t_fractal *f);
void		mandelbrot(int x, int y, t_fractal *f);
void		julia(int x, int y, t_fractal *f);
void		burningship(int x, int y, t_fractal *f);
void		render(t_fractal *f, void (*func)(int, int, struct s_fractal*));

// math_utils.c
double		ft_interp(double xy, double offset, double zoom);
t_complex	ft_sum(t_complex z1, t_complex z2);
t_complex	ft_sq(t_complex z);

// handlers.c
void		events_init(t_fractal *f);
int			key_handler(int keycode, t_fractal *f);
int			mouse_handler(int button, int x, int y, t_fractal *f);
int			close_handler(t_fractal *f);
int			error_handler(t_fractal *f);

// utils.c
void		ft_pxl_put(t_img *img, int x, int y, int col);
void		ft_putstr_fd(char *s, int fd);
double		ft_atof(const char *s);
