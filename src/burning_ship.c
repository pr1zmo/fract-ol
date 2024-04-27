/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelbassa <zelbassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:36:23 by zelbassa          #+#    #+#             */
/*   Updated: 2024/04/26 16:36:25 by zelbassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static t_complex	square_abs(t_complex z)
{
	t_complex	result;

	result.x = (fabs(z.x) * fabs(z.x)) - (fabs(z.y) * fabs(z.y));
	result.y = 2 * fabs(z.x) * fabs(z.y);
	return (result);
}

int	burning_ship(t_config configs, t_complex z, t_complex c, t_params *ints)
{
	c.x = scale_number(ints->i, WIDTH, -2.0 * configs.zoom
			+ configs.offset_x, 2.0 * configs.zoom + configs.offset_x);
	c.y = scale_number(ints->k, HEIGHT, -2.0 * configs.zoom
			- configs.offset_y, 2.0 * configs.zoom - configs.offset_y);
	z.x = 0;
	z.y = 0;
	ints->t = 0;
	while (ints->t++ < configs.iterations && (z.x * z.x + z.y * z.y) < 4)
		z = sum_complex(square_abs(z), c);
	return (ints->t);
}
