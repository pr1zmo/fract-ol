/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelbassa <zelbassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 21:22:24 by prizmo            #+#    #+#             */
/*   Updated: 2024/04/24 13:26:04 by zelbassa         ###   ########.fr       */
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

int	change_param(int keycode, void *param)
{
	t_config	*config;
	t_vars		*vars;

	config = (t_config *)param;
	vars = &config->vars;
	if (keycode == ENTER && config->iterations > 100)
		config->iterations -= 100;
	else if (keycode == UP_ARROW)
		config->offset_y += 0.1 * config->zoom;
	else if (keycode == C_KEY)
		config->iterations += 100;
	else if (keycode == DOWN_ARROW)
		config->offset_y -= 0.1 * config->zoom;
	else if (keycode == LEFT_ARROW)
		config->offset_x -= 0.1 * config->zoom;
	else if (keycode == RIGHT_ARROW)
		config->offset_x += 0.1 * config->zoom;
	else if (keycode == ZOOM_IN)
		config->zoom /= 1.1;
	else if (keycode == ZOOM_OUT)
		config->zoom *= 1.1;
	else if (keycode == ESCAPE)
		close_window(vars);
	draw(config, vars);
	printf("Key pressed: %d\n", keycode);
	return (0);
}

void	init_settings(t_config *settings, t_vars vars, char *av)
{
	settings->zoom = 1.0;
	settings->offset_x = 0.0;
	settings->offset_y = 0.0;
	settings->iterations = 60;
	settings->name = av;
	settings->vars = vars;
}

int	main(int ac, char **av)
{
	void		*mlx_ptr;
	void		*mlx_window;
	t_vars		vars;
	t_config	settings;

	if (ac != 2)
		exit(0);
	mlx_ptr = mlx_init();
	mlx_window = mlx_new_window(mlx_ptr, WIDTH, HEIGHT, av[1]);
	vars.mlx = mlx_ptr;
	vars.win = mlx_window;
	init_settings(&settings, vars, av[1]);
	draw(&settings, &vars);
	mlx_key_hook(mlx_window, change_param, &settings);
	mlx_loop(mlx_ptr);
	return (0);
}
