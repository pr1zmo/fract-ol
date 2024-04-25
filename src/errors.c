/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prizmo <prizmo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 14:39:21 by prizmo            #+#    #+#             */
/*   Updated: 2024/04/25 18:28:12 by prizmo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	exit_handler(void)
{
	ft_putendl_fd("Usage: ./fractol [mandelbrot | julia] [julia arguments]",
		2);
	exit(1);
}
