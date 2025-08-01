/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelbassa <zelbassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:36:49 by zelbassa          #+#    #+#             */
/*   Updated: 2024/04/26 20:24:13 by zelbassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*pxl;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		pxl = data->addr + (y * data->line_length
				+ x * (data->bits_per_pixel / 8));
		*(unsigned int *)pxl = color;
	}
}

int	close_window(int keycode, t_config *settings)
{
	mlx_destroy_window(settings->vars.mlx, settings->vars.win);
	free(settings->vars.mlx);
	exit(EXIT_SUCCESS);
	return (0);
}

void	config_init(t_config *settings, char **av, t_vars vars, t_data img)
{
	settings->zoom = 1;
	settings->iterations = 60;
	settings->name = av[1];
	settings->offset_x = 0;
	settings->offset_y = 0;
	settings->palette = 1;
	if (av[2] && av[3]
		&& (ft_isdigit(av[2][0]) || ft_isdigit(av[2][1]))
		&& (ft_isdigit(av[3][0]) || ft_isdigit(av[3][1])))
	{
		settings->julia.x = atoi_double(av[2]);
		settings->julia.y = atoi_double(av[3]);
	}
	else
	{
		settings->julia.x = 0.0;
		settings->julia.y = 0.0;
	}
	settings->vars = vars;
	settings->img = img;
}

void	check_args(int ac, char **av)
{
	if (ac < 2)
		exit_handler();
	if (ac == 2)
	{
		if (ft_strcmp("mandelbrot", av[1]) == 0)
			return ;
		if (ft_strcmp("burning_ship", av[1]) == 0)
			return ;
	}
	if (ac == 4 && ft_strcmp("julia", av[1]) == 0)
		return ;
	else
		exit_handler();
}

int	main(int ac, char **av)
{
	void		*mlx_ptr;
	void		*mlx_window;
	t_vars		vars;
	t_data		img;
	t_config	settings;

	check_args(ac, av);
	mlx_ptr = mlx_init();
	mlx_window = mlx_new_window(mlx_ptr, WIDTH, HEIGHT, av[1]);
	img.img = mlx_new_image(mlx_ptr, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	vars.mlx = mlx_ptr;
	vars.win = mlx_window;
	config_init(&settings, av, vars, img);
	draw(&settings, &img);
	mlx_put_image_to_window(mlx_ptr, mlx_window, img.img, 0, 0);
	mlx_key_hook(mlx_window, handle_events, &settings);
	mlx_mouse_hook(mlx_window, handle_mouse, &settings);
	mlx_hook(mlx_window, 17, 0, destroy, &vars);
	mlx_loop(mlx_ptr);
	return (0);
}
