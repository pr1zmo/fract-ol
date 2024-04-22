/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelbassa <zelbassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 21:24:24 by prizmo            #+#    #+#             */
/*   Updated: 2024/04/22 19:49:16 by zelbassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "libft/libft.h"
# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <math.h>

#define C_KEY 8
#define ESCAPE 53
#define	LEFT_ARROW 123
#define	RIGHT_ARROW 124
#define	DOWN_ARROW 125
#define	UP_ARROW 126
#define ZOOM_IN 69
#define ZOOM_OUT 78
#define EVENT_KEY_DOWN 2
#define ENTER 36
#define	MASK 1L<<0
#define RED 0x00FF0000
#define GREEN 0x0000FF00
#define BLUE 0x000000FF
#define WHITE 0x00FFFFFF
#define YELLOW 0x00FFFF00
#define INDIGO 0x0000FF99
#define PURPLE 0x009933FF
#define BLACK 0x00000000
#define WIDTH 1080
#define HEIGHT 1080


typedef struct	s_vars {
	void	*mlx;
	void	*win;
}	t_vars;

typedef struct s_config
{
	double	zoom;
	double	offsetX;
	double	offsetY;
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