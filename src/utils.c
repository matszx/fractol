#include "../inc/fractol.h"

void	ft_pxl_put(t_img *img, int x, int y, int colour)
{
	int	offset;

	offset = (x * img->bpp / 8) + (y * img->line_len);
	*((unsigned int *)(offset + img->pxl_ptr)) = colour; 
}

void	ft_putstr_fd(char *s, int fd)
{
	size_t	len;

	if (!s)
		return ;
	len = 0;
	while (s[len])
		len++;
	write(fd, s, len);
}

double	ft_atof(const char *s)
{
	int		sign;
	double	res;
	double	exp;

	sign = 1;
	res = 0.0;
	exp = 1.0;
	while (*s == 32 || (*s >= 9 && *s <= 13))
		s++;
	while (*s == '+' || *s == '-')
	{
		if (*s++ == '-')
			sign *= -1;
	}
	while (*s && *s >= '0' && *s <= '9')
		res = (res * 10) + (*s++ - '0');
	if (*s == '.')
		s++;
	while (*s && *s >= '0' && *s <= '9')
	{
		exp /= 10;
		res = res + (*s++ - '0') * exp;
	}
	return (res * sign);
}
