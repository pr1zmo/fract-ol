/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prizmo <prizmo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 14:39:21 by prizmo            #+#    #+#             */
/*   Updated: 2024/04/26 15:14:07 by prizmo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	exit_handler(void)
{
	ft_putstr_fd("Usage: ./fractol [mandelbrot | julia |", 2);
	ft_putendl_fd(" burning_ship] [julia values]", 2);
	exit(1);
}

int	destroy(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(EXIT_SUCCESS);
	return (0);
}
