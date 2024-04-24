#include "../fractol.h"

void	render(t_config *settings, t_data *img)
{
	t_complex	c;
	t_complex	z;
	t_params	ints;

	ints.i = 0;
	ints.k = 0;
	ints.t = 0;
	while (ints.i < WIDTH)
	{
		while (ints.k < HEIGHT)
		{
			draw_pixel(*settings, c, z, &ints);
			ints.k++;
		}
		ints.k = 0;
		ints.i++;
	}
}

void	draw(t_config *config, t_vars *vars)
{
	t_data	img;

	img.img = mlx_new_image(vars->mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	render(config, &img);
	mlx_put_image_to_window(vars->mlx, vars->win, img.img, 0, 0);
}
