/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prizmo <prizmo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 14:39:21 by prizmo            #+#    #+#             */
/*   Updated: 2024/04/25 18:22:52 by prizmo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void    exit_handler()
{
    ft_putendl_fd("Usage: ./fractol [mandelbrot | julia] [julia arguments]", 2);
    exit(1);
}