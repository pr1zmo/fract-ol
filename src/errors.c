/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelbassa <zelbassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:36:43 by zelbassa          #+#    #+#             */
/*   Updated: 2024/04/26 20:23:33 by zelbassa         ###   ########.fr       */
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
	free(vars->mlx);
	exit(EXIT_SUCCESS);
	return (0);
}
