/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prizmo <prizmo@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 09:54:34 by prizmo            #+#    #+#             */
/*   Updated: 2024/04/24 09:54:34 by prizmo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	change_color(t_config *config, t_vars *vars)
{
	if (config->palette == 1)
		config->palette = 2;
	else if (config->palette == 2)
		config->palette = 3;
	else if (config->palette == 3)
		config->palette = 1;
	redraw(config, &config->vars);
}

void	zoom(int keycode, t_config *config, t_vars *vars)
{
	if (keycode == ZOOM_OUT)
		config->zoom *= 1.1;
	else if (keycode == ZOOM_IN)
		config->zoom /= 1.1;
	else if (keycode == H_KEY)
	{
		config->zoom = 1;
		config->offset_x = 0;
		config->offset_y = 0;
	}
	redraw(config, vars);
}

void	move(int keycode, t_config *config, t_vars *vars)
{
	if (keycode == UP_ARROW)
		config->offset_y += 0.1 * config->zoom;
	else if (keycode == DOWN_ARROW)
		config->offset_y -= 0.1 * config->zoom;
	else if (keycode == LEFT_ARROW)
		config->offset_x -= 0.1 * config->zoom;
	else if (keycode == RIGHT_ARROW)
		config->offset_x += 0.1 * config->zoom;
	redraw(config, vars);
}

void	iterations(int keycode, t_config *config, t_vars *vars)
{
	if (keycode == ENTER)
		config->iterations += 10;
	else if (keycode == C_KEY)
		config->iterations -= 10;
	redraw(config, vars);
}

int	handle_events(int keycode, void *param)
{
	t_config	*config;
	t_vars		*vars;

	config = (t_config *)param;
	vars = &config->vars;
	if (keycode == UP_ARROW || keycode == DOWN_ARROW
		|| keycode == LEFT_ARROW || keycode == RIGHT_ARROW)
		move(keycode, config, vars);
	else if (keycode == ENTER || keycode == C_KEY)
		iterations(keycode, config, vars);
	else if (keycode == ZOOM_IN || keycode == ZOOM_OUT
		|| keycode == H_KEY)
		zoom(keycode, config, vars);
	else if (keycode == LEFT_SHIFT)
		change_color(config, vars);
	else if (keycode == ESCAPE)
		close_window(vars);
	printf("iterations: %d\n", keycode);
	return (0);
}
