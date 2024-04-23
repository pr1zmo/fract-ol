/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelbassa <zelbassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 21:24:24 by prizmo            #+#    #+#             */
/*   Updated: 2024/04/23 17:17:52 by zelbassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "libft/libft.h"
# include "settings.h"
# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <math.h>

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}	t_vars;

typedef struct s_config
{
	double	zoom;
	double	offset_x;
	double	offset_y;
	int		iterations;
	t_vars	vars;
}	t_config;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_complex
{
	double	x;
	double	y;
}	t_complex;



#endif