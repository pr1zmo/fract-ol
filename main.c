/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prizmo <prizmo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 21:22:24 by prizmo            #+#    #+#             */
/*   Updated: 2024/04/02 21:38:38 by prizmo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <complex.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


void    ft_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int *)dst = color;
}

int mandelbrot(double complex c)
{
    int max_iter = 100;
    int z = 0;
    int n = 0;
    int iter = 0;
    while (abs(z) <= 2 && n < max_iter)
    {
        z = pow(z, 2) + c;
        printf("Complex number: %.2f + %.2fi\n", creal(z), cimag(z));
        printf("THE Z: %d\n", z);
        printf("Small iters: %d\n", iter);
        iter++;
        n++;
    }
    return n;
}

int scale(int unscaled_num, int min_allowed, int max_allowed, int min, int max)
{
    return (max_allowed - min_allowed) * (unscaled_num - min) / (max - min) + min_allowed;
}

int main()
{
    void    *mlx_ptr;
    void    *mlx_window;
    t_data  *img;
    int     fd;

	mlx_ptr = mlx_init();
    fd = open("hello.txt", O_CREAT | O_WRONLY | O_TRUNC);
	img = malloc(sizeof(t_data));
	img->img = mlx_new_image(mlx_ptr, HEIGHT, LENGTH);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);
	mlx_window = mlx_new_window(mlx_ptr, HEIGHT, LENGTH, "fractol");
    int iters = 0;
	for (int i = 0; i <= HEIGHT; i++)
    {
		for (int k = 0; k <= LENGTH; k++)
		{
            int scaled_i = scale(i, -2, 2, 0, LENGTH - 1);
            int scaled_k = scale(k, -2, 2, 0, HEIGHT - 1);
            double complex c = scaled_i + scaled_k * I;
            printf("All iters: %d\n", iters);
            if (mandelbrot(c) <= 2)
                ft_mlx_pixel_put(img, i, k, GREEN);
            iters++;
        }
    }
    mlx_put_image_to_window(mlx_ptr, mlx_window, img->img, 0, 0);
    free(img);
    mlx_loop(mlx_ptr);
	return (0);
}