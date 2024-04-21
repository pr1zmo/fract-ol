/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prizmo <prizmo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 21:24:24 by prizmo            #+#    #+#             */
/*   Updated: 2024/04/03 02:52:19 by prizmo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "libft/libft.h"
# include "mlx_linux/mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <math.h>

#define LEFT_ARR 37
#define RIGHT_ARR 38
#define ESCAPE 27
#define RED 0x00FF0000
#define GREEN 0x0000FF00
#define BLUE 0x000000FF
#define WHITE 0x00FFFFFF
#define YELLOW 0x00FFFF00
#define INDIGO 0x0000FF99
#define PURPLE 0x009933FF
#define BLACK 0x00000000
#define WIDTH 800
#define HEIGHT 800

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

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