/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 13:32:46 by mkarim            #+#    #+#             */
/*   Updated: 2022/05/12 18:57:27 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	handle_julia(int keycode, int x, int y, t_all *a)
{
	x = y;

	if (keycode == 5)
	{
		a->mm->z_x *= 0.9;
		a->mm->z_y *= 0.9;
	}
	else if (keycode == 4)
	{
		a->mm->z_x *= 1.1;
		a->mm->z_y *= 1.1;
	}
	else if (keycode == 1)
		a->mm->pos *= -1;
	ft_julia(a);
	return (0);
}

int	ft_handle_mouse(int x, int y, t_all *a)
{
	if (a->mm->pos > 0)
	{
		a->mm->c_re = (x * a->mm->scale_x) - 2.0 + (4.0 - a->mm->z_x) / 2.0;
		a->mm->c_im = (y * a->mm->scale_y) - 2.0 + (4.0 - a->mm->z_y) / 2.0;
	}
	ft_julia(a);
	return (0);
}

void	ft_julia(t_all *a)
{
	a->mm->max = 500;
	a->mm->row = 0;
	a->mm->scale_x = (a->mm->z_x/WIN_WIDTH);
	a->mm->scale_y = (a->mm->z_y/WIN_WIDTH);
	while (a->mm->row < WIN_HEIGHT)
	{
		a->mm->col = 0;
		while (a->mm->col < WIN_WIDTH)
		{
			a->mm->x = (a->mm->col * a->mm->scale_x) - 2.0 + (4.0 - a->mm->z_x) / 2.0;
			a->mm->y = (a->mm->row * a->mm->scale_y) - 2.0 + (4.0 - a->mm->z_y) / 2.0;
			// a->mm->c_re = 0.284;
			// a->mm->c_im = 0.01;
			a->mm->iteration = 0;
			while (a->mm->iteration < a->mm->max) {
				a->mm->x_new = a->mm->x*a->mm->x - a->mm->y*a->mm->y + a->mm->c_re;
				a->mm->y = 2*a->mm->x*a->mm->y + a->mm->c_im;
				a->mm->x = a->mm->x_new;
				a->mm->iteration++;
				if (a->mm->x*a->mm->x+a->mm->y*a->mm->y > 4)
					break;
			}
			if (a->mm->iteration < a->mm->max) mlx_pixel_put(a->fractt->mlx, a->fractt->mlx_win, a->mm->col, a->mm->row, a->mm->iteration * 0x00ffddcc);
			// else mlx_pixel_put(a->fractt->mlx, a->fractt->mlx_win, a->mm->col, a->mm->row, 0x00000000);
			a->mm->col++;
		}
		a->mm->row++;
	}
}
