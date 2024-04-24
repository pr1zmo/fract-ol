/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelbassa <zelbassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 09:54:40 by prizmo            #+#    #+#             */
/*   Updated: 2024/04/24 13:24:31 by zelbassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	render(t_config configs, t_complex c, t_complex z, t_params *ints)
{
	if (ft_strncmp(configs.name, "mandelbrot", 10) == 0)
		return (mandelbrot(configs, c, z, ints));
	else if (ft_strncmp(configs.name, "julia", 10) == 0)
		julia(configs, c, z, *ints);
}
