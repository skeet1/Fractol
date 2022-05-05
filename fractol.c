/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 14:22:44 by mkarim            #+#    #+#             */
/*   Updated: 2022/04/27 23:29:23 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_fractol	*fract;
	double		row;
	double		col;
	double		max;
	double		c_re;
	double		c_im;
	double		x_new;
	double		x;
	double		y;
	double		iteration;

	fract = (t_fractol *)malloc(sizeof(t_fractol));
	if (!fract)
		return (0);
	ft_init(fract);
	if (argc == 2)
	{
		if (argv[1][0] == 'm')
		{
			ft_mandelbrot_set();
		}
	}
	max = 10;
	row = 0;
	while (row < WIN_HEIGHT)
	{
		col = 0;
		while (col < WIN_WIDTH)
		{
			c_re = (col - WIN_WIDTH/2.0)*4.0/WIN_WIDTH;
			c_im = (row - WIN_HEIGHT/2.0)*4.0/WIN_WIDTH;
			x = 0;
			y = 0;
			iteration = 0;
			while (x*x+y*y <= 4 && iteration < max) {
				x_new = x*x - y*y + c_re;
				y = 2*x*y + c_im;
				x = x_new;
				iteration++;
			}
			if (iteration < max) mlx_pixel_put(fract->mlx, fract->mlx_win, col, row, 0x00FFFFFF);
			else mlx_pixel_put(fract->mlx, fract->mlx_win, col, row, 0x0000FF00);
			col++;
		}
		row++;
	}
	mlx_loop(fract->mlx);
	// mlx_destroy_window(fract->mlx, fract->mlx_win);
	// free(fract->mlx);
}
