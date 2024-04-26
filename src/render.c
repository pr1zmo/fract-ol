/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prizmo <prizmo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 09:54:40 by prizmo            #+#    #+#             */
/*   Updated: 2024/04/26 13:00:12 by prizmo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	redraw(t_config *settings, t_vars *vars)
{
	t_data	img;

	img.img = mlx_new_image(vars->mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	mlx_clear_window(vars->mlx, vars->win);
	draw(settings, &img);
	mlx_put_image_to_window(vars->mlx, vars->win, img.img, 0, 0);
}

int	render(t_config configs, t_complex c, t_complex z, t_params *ints)
{
	if (ft_strncmp(configs.name, "mandelbrot", 10) == 0)
		return (mandelbrot(configs, c, z, ints));
	else if (ft_strncmp(configs.name, "julia", 5) == 0)
		return (julia(configs, c, z, ints));
	else if (ft_strncmp(configs.name, "burning_ship", 12) == 0)
		return (burning_ship(configs, z, c, ints));
	return (0);
}

void	draw(t_config *settings, t_data *img)
{
	t_complex	c;
	t_complex	z;
	t_params	ints;
	t_RGB		color;
	int			int_color;

	ints.i = 0;
	ints.k = 0;
	ints.t = 0;
	while (ints.i < WIDTH)
	{
		while (ints.k < HEIGHT)
		{
			ints.t = render(*settings, c, z, &ints);
			color = get_color(settings->palette, ints.t, settings->iterations);
			int_color = (color.r << 16) | (color.g << 8) | color.b;
			my_mlx_pixel_put(img, ints.i, ints.k, int_color);
			ints.k++;
		}
		ints.k = 0;
		ints.i++;
	}
}
