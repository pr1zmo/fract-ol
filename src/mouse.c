/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelbassa <zelbassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:37:12 by zelbassa          #+#    #+#             */
/*   Updated: 2024/04/26 16:37:13 by zelbassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	handle_mouse(int button, int x, int y, t_config *config)
{
	t_vars	*vars;

	vars = &config->vars;
	if (button == 4)
		config->zoom /= 1.1;
	else if (button == 5)
		config->zoom *= 1.1;
	else if (button == 1)
	{
		config->offset_x = 0;
		config->offset_y = 0;
	}
	redraw(config, vars);
	return (0);
}
