/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 13:32:46 by mkarim            #+#    #+#             */
/*   Updated: 2022/05/13 15:13:49 by mkarim           ###   ########.fr       */
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
	mlx_clear_window(a->fractt->mlx, a->fractt->mlx_win);
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

double	ft_calc_it_julia(t_all *a)
{
	a->mm->x = (a->mm->col * a->mm->scale_x) - 2.0 + (4.0 - a->mm->z_x) / 2.0;
	a->mm->y = (a->mm->row * a->mm->scale_y) - 2.0 + (4.0 - a->mm->z_y) / 2.0;
	a->mm->iteration = 0;
	while (a->mm->iteration < a->mm->max)
	{
		a->mm->x_new = a->mm->x * a->mm->x - a->mm->y * a->mm->y + a->mm->c_re;
		a->mm->y = 2 * a->mm->x * a->mm->y + a->mm->c_im;
		a->mm->x = a->mm->x_new;
		a->mm->iteration++;
		if (a->mm->x * a->mm->x + a->mm->y * a->mm->y > 4)
			break ;
	}
	return (a->mm->iteration);
}

void	ft_julia(t_all *a)
{
	a->mm->max = 500;
	a->mm->row = 0;
	a->mm->scale_x = (a->mm->z_x / WIN_WIDTH);
	a->mm->scale_y = (a->mm->z_y / WIN_WIDTH);
	while (a->mm->row < WIN_HEIGHT)
	{
		a->mm->col = 0;
		while (a->mm->col < WIN_WIDTH)
		{
			a->mm->iteration = ft_calc_it_julia(a);
			if (a->mm->iteration < a->mm->max)
				img_pix_put(a->fractt, a->mm->col, a->mm->row,
					a->mm->iteration * 0x00ffddcc);
			a->mm->col++;
		}
		a->mm->row++;
	}
	mlx_put_image_to_window(a->fractt->mlx, a->fractt->mlx_win,
		a->fractt->img, 0, 0);
}
