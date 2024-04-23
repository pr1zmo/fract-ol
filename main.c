/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelbassa <zelbassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 21:22:24 by prizmo            #+#    #+#             */
/*   Updated: 2024/04/23 17:20:02 by zelbassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <complex.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdint.h>

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

double scale_number(double num, double old_max, double new_min, double new_max)
{
	double proportion = (num) / (old_max);
	double scaled_value = new_min + (proportion * (new_max - new_min));
	return scaled_value;
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
	t_complex result;

	result.x = (z.x * z.x) - (z.y * z.y);
	result.y = z.x * z.y * 2;
	return result;
}

void	draw_pixels(t_config *settings, t_data *img, void *mlx_window)
{
	t_complex	c;
	t_complex	z;
	t_complex	tmp;
	int			t;

	for (int i = 0; i < WIDTH; i++)
	{
		for (int k = 0; k < HEIGHT; k++)
		{
			c.x = scale_number(i, HEIGHT, -2.0 * settings->zoom + settings->offset_x, 2.0 * settings->zoom + settings->offset_x);
			c.y = scale_number(k, WIDTH, 2.0 * settings->zoom + settings->offset_y, -2.0 * settings->zoom + settings->offset_y);
			z.x = 0;
			z.y = 0;
			t = 0;
			while (t++ < settings->iterations && (z.x * z.x + z.y * z.y) < 4)
				z = sum_complex(square_complex(z), c);
			RGB color = get_color(t, settings->iterations);
			uint32_t int_color = (color.r << 16) | (color.g << 8) | color.b;
			my_mlx_pixel_put(img, i, k, int_color);
		}
	}
}

void	redraw(t_config *config, t_vars *vars)
{
	t_data	img;

	img.img = mlx_new_image(vars->mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, 
				&img.line_length, &img.endian);
	draw_pixels(config, &img, vars->win);
	mlx_put_image_to_window(vars->mlx, vars->win, img.img, 0, 0);
}

int	change_param(int keycode, void *param)
{
	t_config	*config;
	t_vars		*vars;

	config = (t_config *)param;
	vars = &config->vars;
	if (keycode == UP_ARROW)
		config->offset_y += 0.1;
	else if (keycode == ENTER && config->iterations > 100)
		config->iterations -= 50;
	else if (keycode == C_KEY)
		config->iterations += 50;
	else if (keycode == DOWN_ARROW)
		config->offset_y -= 0.1;
	else if (keycode == LEFT_ARROW)
		config->offset_x -= 0.1;
	else if (keycode == RIGHT_ARROW)
		config->offset_x += 0.1;
	else if (keycode == ZOOM_IN)
		config->zoom /= 1.1;
	else if (keycode == ZOOM_OUT)
		config->zoom *= 1.1;
	else if (keycode == ESCAPE)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	redraw(config, vars);
	printf("Key pressed: %d\n", keycode);
	return (0);
}

int main()
{
	void		*mlx_ptr;
	void		*mlx_window;
	t_vars		vars;
	t_data		img;

	mlx_ptr = mlx_init();
	mlx_window = mlx_new_window(mlx_ptr, WIDTH, HEIGHT, "Fractol");
	t_config	settings = {1.0, 0.0, 0.0, 60, mlx_ptr, mlx_window};
	img.img = mlx_new_image(mlx_ptr, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								 &img.endian);
	vars.mlx = mlx_ptr;
	vars.win = mlx_window;
	draw_pixels(&settings, &img, mlx_window);
	mlx_key_hook(mlx_window, change_param, &settings);
	mlx_put_image_to_window(mlx_ptr, mlx_window, img.img, 0, 0);
	mlx_loop(mlx_ptr);
	return (0);
}
