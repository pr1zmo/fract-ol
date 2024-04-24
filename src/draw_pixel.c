/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelbassa <zelbassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 09:54:40 by prizmo            #+#    #+#             */
/*   Updated: 2024/04/24 13:24:31 by zelbassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	draw_pixel(t_config configs, t_complex c, t_complex z, t_params *ints)
{
	int		iterations;
	int		int_color;
	t_RGB	color;
	t_data	img;

	img.img = mlx_new_image(configs.vars.mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	iterations = 0;
	if (ft_strncmp(configs.name, "mandelbrot", 10) == 0)
		iterations = mandelbrot(configs, c, z, ints);
	else if (ft_strncmp(configs.name, "julia", 10) == 0)
		iterations = julia(configs, c, z, *ints);
	color = get_color(PALETTE, iterations, configs.iterations);
	int_color = (color.r << 16) | (color.g << 8) | color.b;
	my_mlx_pixel_put(&img, ints->i, ints->k, int_color);
}
