/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 16:30:39 by mkarim            #+#    #+#             */
/*   Updated: 2022/05/12 09:46:06 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_mandelbrot(t_fractol *fract)
{
	t_mandelbrot *m;

	m = (t_mandelbrot *)malloc(sizeof(t_mandelbrot));
	if (!m)
		return ;
	m->max = 50;
	m->row = 0;
	m->scale_x = (2.0/WIN_WIDTH);
	m->scale_y = (2.0/WIN_WIDTH);
	while (m->row < WIN_HEIGHT)
	{
		m->col = 0;
		while (m->col < WIN_WIDTH)
		{
			m->c_re = (m->col * m->scale_x) - 2.0 + 1.0;
			m->c_im = (m->row * m->scale_y) - 2.0 + 1.0;
			m->x = 0;
			m->y = 0;
			m->iteration = 0;
			while (m->x*m->x+m->y*m->y <= 4 && m->iteration < m->max) {
				m->x_new = m->x*m->x - m->y*m->y + m->c_re;
				m->y = 2*m->x*m->y + m->c_im;
				m->x = m->x_new;
				m->iteration++;
			}
			if (m->iteration < m->max) mlx_pixel_put(fract->mlx, fract->mlx_win, m->col, m->row, m->iteration * 3 * 0x00FFFFFF);
			else mlx_pixel_put(fract->mlx, fract->mlx_win, m->col, m->row, 0x00000000);
			m->col++;
		}
		m->row++;
	}
}
