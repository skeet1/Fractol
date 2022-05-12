/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 13:32:46 by mkarim            #+#    #+#             */
/*   Updated: 2022/05/11 09:34:05 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_julia(t_fractol *fract)
{
	t_mandelbrot *m;

	m = (t_mandelbrot *)malloc(sizeof(t_mandelbrot));
	if (!m)
		return ;
	m->max = 500;
	m->row = 0;
	while (m->row < WIN_HEIGHT)
	{
		m->col = 0;
		while (m->col < WIN_WIDTH)
		{
			m->x = (m->col - WIN_WIDTH/2.0)*4.0/WIN_WIDTH;
			m->y = (m->row - WIN_HEIGHT/2.0)*4.0/WIN_WIDTH;
			m->c_re = 0.284;
			m->c_im = 0.01;
			m->iteration = 0;
			while (m->iteration < m->max) {
				m->x_new = m->x*m->x - m->y*m->y + m->c_re;
				m->y = 2*m->x*m->y + m->c_im;
				m->x = m->x_new;
				m->iteration++;
				if (m->x*m->x+m->y*m->y > 4)
					break ;
			}
			if (m->iteration < m->max) mlx_pixel_put(fract->mlx, fract->mlx_win, m->col, m->row, m->iteration * 0x00FFFFFF);
			m->col++;
		}
		m->row++;
	}
}
