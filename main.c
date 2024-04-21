/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prizmo <prizmo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 21:22:24 by prizmo            #+#    #+#             */
/*   Updated: 2024/04/02 21:38:38 by prizmo           ###   ########.fr       */
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
	t_complex c;

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

uint32_t get_color(int iteration, int max_iterations)
{
	int color = (255 * iteration) / max_iterations;
	return color | (color << 8) | (color << 16);
}

void	draw_pixels(t_data *img)
{
	t_complex	c;
	t_complex	z;
	t_complex	tmp;
	int			max_iterations = 300;
	int			t;

	for (int i = 0; i < WIDTH; i++)
	{
		for (int k = 0; k < HEIGHT; k++)
		{
			c.x = scale_number(i, HEIGHT, -2.0, 2.0);
			c.y = scale_number(k, WIDTH, 2.0, -2.0);
			z.x = 0;
			z.y = 0;
			t = 0;
			while (t++ < max_iterations && (z.x * z.x + z.y * z.y) < 4)
			{
				z = sum_complex(square_complex(z), c);
			}
			uint32_t color = get_color(t, max_iterations);
			my_mlx_pixel_put(img, i, k, color);

		}
	}
}

int	*close_window(int keycode, t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}

int main()
{
	void	*mlx_ptr;
	void	*mlx_window;
	t_data 	img;

	mlx_ptr = mlx_init();
	mlx_window = mlx_new_window(mlx_ptr, WIDTH, HEIGHT, "Fractol");
	img.img = mlx_new_image(mlx_ptr, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								 &img.endian);
	draw_pixels(&img);
	mlx_put_image_to_window(mlx_ptr, mlx_window, img.img, 0, 0);
	mlx_loop(mlx_ptr);
}
