/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelbassa <zelbassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 21:24:24 by zelbassa          #+#    #+#             */
/*   Updated: 2024/04/26 16:33:46 by zelbassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "libft/libft.h"
# include "mlx.h"
# include "settings.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_RGB
{
	int	r;
	int	g;
	int	b;
}		t_RGB;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}			t_vars;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

typedef struct s_complex
{
	double	x;
	double	y;
}			t_complex;

typedef struct s_config
{
	double		zoom;
	double		offset_x;
	double		offset_y;
	int			iterations;
	char		*name;
	int			palette;
	t_complex	julia;
	t_vars		vars;
	t_data		img;
}				t_config;

typedef struct s_params
{
	int		i;
	int		k;
	int		t;
}			t_params;

t_RGB		get_color(int variation, int iteration, int max_iterations);
double		scale_number(double num, double old_min, double new_min,
				double new_max);
t_RGB		black_n_white(int iteration, int max_iterations);
t_RGB		colorful_variation(int iterations, int max_iterations);
int			mandelbrot(t_config configs, t_complex c, t_complex z,
				t_params *ints);
int			julia(t_config configs, t_complex c, t_complex z, t_params *ints);
int			burning_ship(t_config configs, t_complex z,
				t_complex c, t_params *ints);
t_complex	sum_complex(t_complex z1, t_complex z2);
t_complex	square_complex(t_complex z);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
int			render(t_config configs, t_complex c, t_complex z, t_params *ints);
void		draw(t_config *settings, t_data *img);
int			handle_events(int keycode, void *param);
int			handle_mouse(int button, int x, int y, t_config *config);
void		redraw(t_config *settings, t_vars *vars);
int			close_window(int keycode, t_config *settings);
void		exit_handler(void);
double		atoi_double(char *av);
double		recursive_num(int k);
int			destroy(t_vars *vars);

#endif