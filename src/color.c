/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelbassa <zelbassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 09:54:26 by prizmo            #+#    #+#             */
/*   Updated: 2024/04/24 13:23:59 by zelbassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

t_RGB	int_to_rgb(int iteration, int max_iterations)
{
	t_RGB	color;

	color.r = (255 * iteration) / max_iterations;
	color.g = (255 * (max_iterations - iteration)) / max_iterations;
	color.b = (255 * iteration) / (2 * max_iterations);
	return (color);
}

t_RGB	basic_variation(int iterations, int max_iterations)
{
	t_RGB	color;
	double	scaled_value;

	scaled_value = scale_number(iterations, max_iterations, 0, 255);
	color.r = scaled_value;
	color.g = scaled_value * 0.7;
	color.b = scaled_value * 0.9;
	return (color);
}

t_RGB	colorful_variation(int iterations, int max_iterations)
{
	t_RGB	color;
	double	scaled_value;

	scaled_value = scale_number(iterations, max_iterations, 0, 255);
	color.b = scaled_value * 8;
	color.g = scaled_value * 4;
	color.r = scaled_value * 2;
	return (color);
}

t_RGB	black_n_white(int iteration, int max_iterations)
{
	t_RGB	color;

	color.g = (int)scale_number(iteration, max_iterations, 0, 255);
	color.b = color.g;
	color.r = color.g;
	return (color);
}

t_RGB	get_color(int variation, int iteration, int max_iterations)
{
	if (variation == 1)
		return (basic_variation(iteration, max_iterations));
	else if (variation == 2)
		return (colorful_variation(iteration, max_iterations));
	else if (variation == 3)
		return (black_n_white(iteration, max_iterations));
}
