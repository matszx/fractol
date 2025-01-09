#include "../inc/fractol.h"

double	ft_interp(double xy, double offset, double zoom)
{
	return ((4.0 * xy / SIZE - 2.0) * zoom + offset);
}

t_complex	ft_sum(t_complex z1, t_complex z2)
{
	t_complex	res;

	res.r = z1.r + z2.r;
	res.i = z1.i + z2.i;
	return (res);
}

t_complex	ft_sq(t_complex z)
{
	t_complex	res;

	res.r = (z.r * z.r) - (z.i * z.i);
	res.i = 2 * z.r * z.i;
	return (res);
}
