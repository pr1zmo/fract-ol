/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelbassa <zelbassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:36:32 by zelbassa          #+#    #+#             */
/*   Updated: 2024/04/26 16:36:33 by zelbassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

t_RGB	basic_variation(int iterations, int max_iterations)
{
	t_RGB	color;
	double	scaled_value;

	if (iterations >= 255)
		scaled_value = 0;
	else
		scaled_value = scale_number(iterations, max_iterations, 0, 255);
	color.r = scaled_value;
	color.g = scaled_value * 2;
	color.b = scaled_value * 3;
	return (color);
}

t_RGB	colorful_variation(int iterations, int max_iterations)
{
	t_RGB	color;
	double	scaled_value;

	if (iterations >= 255)
		scaled_value = 0;
	else
		scaled_value = scale_number(iterations, max_iterations, 0, 255);
	color.b = (int)scaled_value * 8;
	color.g = (int)scaled_value * 4;
	color.r = (int)scaled_value * 2;
	return (color);
}

t_RGB	black_n_white(int iteration, int max_iterations)
{
	t_RGB	color;
	double	scaled_value;

	if (iteration >= 255)
		scaled_value = 0;
	else
		scaled_value = scale_number(iteration, max_iterations, 0, 255);
	color.b = (int)scaled_value;
	color.g = (int)scaled_value;
	color.r = (int)scaled_value;
	return (color);
}

t_RGB	get_color(int variation, int iteration, int max_iterations)
{
	t_RGB	color;

	color.r = 0;
	color.g = 0;
	color.b = 0;
	if (variation == 1)
		color = basic_variation(iteration, max_iterations);
	else if (variation == 2)
		color = colorful_variation(iteration, max_iterations);
	else if (variation == 3)
		color = black_n_white(iteration, max_iterations);
	return (color);
}
