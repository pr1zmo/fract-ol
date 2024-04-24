/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prizmo <prizmo@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 09:54:26 by prizmo            #+#    #+#             */
/*   Updated: 2024/04/24 09:54:26 by prizmo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

t_RGB	basic_variation(int iterations, int max_iterations)
{
	t_RGB	color;
	double	scaled_value;

	scaled_value = scale_number(iterations, max_iterations, 0, 255);
	color.r = (int)scaled_value;
	color.g = (int)scaled_value * 3;
	color.b = (int)scaled_value * 2;
	return (color);
}

t_RGB	colorful_variation(int iterations, int max_iterations)
{
	t_RGB	color;
	double	scaled_value;

	scaled_value = scale_number(iterations, max_iterations,
			0, 255);
	color.b = (int)scaled_value * 8;
	color.g = (int)scaled_value * 4;
	color.r = (int)scaled_value * 2;
	return (color);
}

t_RGB	black_n_white(int iteration, int max_iterations)
{
	t_RGB	color;
	double	scaled_value;

	scaled_value = scale_number(iteration, max_iterations,
			0, 255);
	color.b = (int)scaled_value;
	color.g = (int)scaled_value;
	color.r = (int)scaled_value;
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
