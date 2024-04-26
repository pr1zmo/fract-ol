/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prizmo <prizmo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 14:21:19 by prizmo            #+#    #+#             */
/*   Updated: 2024/04/25 14:21:20 by prizmo           ###   ########.fr       */
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
}
