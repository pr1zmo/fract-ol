/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelbassa <zelbassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 21:22:24 by prizmo            #+#    #+#             */
/*   Updated: 2024/04/22 20:25:36 by zelbassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	close_window(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
}

void	config_init(t_config *settings, char *av, t_vars vars, t_data img)
{
	settings->zoom = 1;
	settings->iterations = 60;
	settings->name = av;
	settings->offset_x = 0;
	settings->offset_y = 0;
	settings->palette = 1;
	settings->vars = vars;
	settings->img = img;
}

int	main(int ac, char **av)
{
	void		*mlx_ptr;
	void		*mlx_window;
	t_vars		vars;
	t_data		img;
	t_config	settings;

	if (ac != 2)
		exit(0);
	mlx_ptr = mlx_init();
	mlx_window = mlx_new_window(mlx_ptr, WIDTH, HEIGHT, av[1]);
	img.img = mlx_new_image(mlx_ptr, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	vars.mlx = mlx_ptr;
	vars.win = mlx_window;
	config_init(&settings, av[1], vars, img);
	draw(&settings, &img);
	mlx_key_hook(mlx_window, handle_events, &settings);
	mlx_mouse_hook(mlx_window, handle_mouse, &settings);
	mlx_put_image_to_window(mlx_ptr, mlx_window, img.img, 0, 0);
	mlx_loop(mlx_ptr);
	return (0);
}
