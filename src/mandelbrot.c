/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prizmo <prizmo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 09:54:34 by prizmo            #+#    #+#             */
/*   Updated: 2024/04/26 13:28:57 by prizmo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	mandelbrot(t_config configs, t_complex c, t_complex z, t_params *ints)
{
	c.x = scale_number(ints->i, WIDTH, -2.0 * configs.zoom
			+ configs.offset_x, 2.0 * configs.zoom + configs.offset_x);
	c.y = scale_number(ints->k, HEIGHT, 2.0 * configs.zoom
			+ configs.offset_y, -2.0 * configs.zoom + configs.offset_y);
	z.x = 0;
	z.y = 0;
	ints->t = 0;
	while (ints->t++ < configs.iterations && (z.x * z.x + z.y * z.y) < 4)
		z = sum_complex(square_complex(z), c);
	return (ints->t);
}
