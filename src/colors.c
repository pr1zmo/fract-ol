/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelbassa <zelbassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 17:17:36 by zelbassa          #+#    #+#             */
/*   Updated: 2024/04/23 17:19:53 by zelbassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

RGB get_color(int t, int max_iterations)
{
	RGB	color;
	int	factor;
	
	factor = 255 / max_iterations;
	color.r = 255 - factor * t;
	color.g = 255 - factor * t;
	color.b = 255;

	return (color);
}