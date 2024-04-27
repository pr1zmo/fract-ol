/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelbassa <zelbassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:37:03 by zelbassa          #+#    #+#             */
/*   Updated: 2024/04/26 16:37:04 by zelbassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

t_complex	sum_complex(t_complex z1, t_complex z2)
{
	t_complex	c;

	c.x = z1.x + z2.x;
	c.y = z1.y + z2.y;
	return (c);
}

t_complex	square_complex(t_complex z)
{
	t_complex	result;

	result.x = (z.x * z.x) - (z.y * z.y);
	result.y = z.x * z.y * 2;
	return (result);
}

double	recursive_num(int k)
{
	double	i;

	i = 1;
	while (k-- > 0)
		i *= 0.1;
	return (i);
}

double	scale_number(double num, double old_max, double new_min, double new_max)
{
	double	proportion;
	double	scaled_value;

	proportion = (num) / (old_max);
	scaled_value = new_min + (proportion * (new_max - new_min));
	return (scaled_value);
}
