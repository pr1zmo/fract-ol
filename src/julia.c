/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prizmo <prizmo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 09:54:34 by prizmo            #+#    #+#             */
/*   Updated: 2024/04/26 15:37:05 by prizmo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	julia(t_config configs, t_complex c, t_complex z, t_params *ints)
{
	if (configs.julia.x > 2.0 || configs.julia.y > 2.0
		|| configs.julia.x < -2.0 || configs.julia.y < -2.0)
		exit_handler();
	c.x = scale_number(ints->i, HEIGHT, -2.0 * configs.zoom
			+ configs.offset_x, 2.0 * configs.zoom + configs.offset_x);
	c.y = scale_number(ints->k, WIDTH, 2.0 * configs.zoom
			+ configs.offset_y, -2.0 * configs.zoom + configs.offset_y);
	z = c;
	ints->t = 0;
	while (ints->t++ < configs.iterations && (z.x * z.x + z.y * z.y) < 4)
		z = sum_complex(square_complex(z), configs.julia);
	return (ints->t);
}
