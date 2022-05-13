/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 16:30:39 by mkarim            #+#    #+#             */
/*   Updated: 2022/05/12 14:37:00 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	handle(int keycode, int x, int y, t_all *a)
{
	x = y;
	if (keycode == 5)
	{
		a->mm->z_x *= 0.9;
		a->mm->z_y *= 0.9;
		a->mm->max += 4;
	}
	else if (keycode == 4)
	{
		a->mm->z_x *= 1.1;
		a->mm->z_y *= 1.1;
		a->mm->max -= 1;
	}
	ft_mandelbrot(a);
	return (0);
}

int	handle_key(int keycode, int x, int y, t_all *a)
{
	x = y;
	(void)a;
	if (keycode == 53)
	{
		exit(1);
	}
	return (0);
}

void	ft_mandelbrot(t_all *a)
{
	a->mm->max = 50;
	a->mm->row = 0;
	a->mm->scale_x = (a->mm->z_x/WIN_WIDTH);
	a->mm->scale_y = (a->mm->z_y/WIN_WIDTH);
	while (a->mm->row < WIN_HEIGHT)
	{
		a->mm->col = 0;
		while (a->mm->col < WIN_WIDTH)
		{
			a->mm->c_re = (a->mm->col * a->mm->scale_x) - 2.0 + (4.0 - a->mm->z_x) / 2.0;
			a->mm->c_im = (a->mm->row * a->mm->scale_y) - 2.0 + (4.0 - a->mm->z_y) / 2.0;
			a->mm->x = 0;
			a->mm->y = 0;
			a->mm->iteration = 0;
			while (a->mm->x*a->mm->x+a->mm->y*a->mm->y <= 4 && a->mm->iteration < a->mm->max) {
				a->mm->x_new = a->mm->x*a->mm->x - a->mm->y*a->mm->y + a->mm->c_re;
				a->mm->y = 2*a->mm->x*a->mm->y + a->mm->c_im;
				a->mm->x = a->mm->x_new;
				a->mm->iteration++;
			}
			if (a->mm->iteration < a->mm->max) mlx_pixel_put(a->fractt->mlx, a->fractt->mlx_win, a->mm->col, a->mm->row, a->mm->iteration * 3 * 0x00FFFFFF);
			else mlx_pixel_put(a->fractt->mlx, a->fractt->mlx_win, a->mm->col, a->mm->row, 0x00000000);
			a->mm->col++;
		}
		a->mm->row++;
	}
}
