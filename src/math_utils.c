#include "../fractol.h"

double	scale_number(double num, double old_max, double new_min, double new_max)
{
	double	proportion;
	double	scaled_value;

	proportion = (num) / (old_max);
	scaled_value = new_min + (proportion * (new_max - new_min));
	return (scaled_value);
}

t_complex	sum_complex(t_complex z1, t_complex z2)
{
	t_complex	c;

	c.x = z1.x + z2.x;
	c.y = z1.y + z2.y;
	return (c);
}

t_complex	square_complex(t_complex z)
{
	t_complex	result;

	result.x = (z.x * z.x) - (z.y * z.y);
	result.y = z.x * z.y * 2;
	return (result);
}
