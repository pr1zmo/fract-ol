/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prizmo <prizmo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 09:54:34 by prizmo            #+#    #+#             */
/*   Updated: 2024/04/25 16:15:45 by prizmo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

double	scale_number(double num, double old_max, double new_min, double new_max)
{
	double	proportion;
	double	scaled_value;

	proportion = (num) / (old_max);
	scaled_value = new_min + (proportion * (new_max - new_min));
	return (scaled_value);
}

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
	double i = 1;
	while (k-- > 0)
	{
		i *= 0.1;
	}
	return (i);
}

double	atoi_double(char *str)
{
	int	i = 0;
	int	sign;
	double	result = 0;

	if (str[i] == '-')
	{
		sign = -1;
		i+=3;
	}
	else
	{
		sign = 1;
		i += 2;
	}
	int	k = 1;
	while (str[i])
	{
		result += (str[i] - '0') * recursive_num(k);
		i++;
		k++;
	}
	return (result * sign);
}