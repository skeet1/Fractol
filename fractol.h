/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 14:23:39 by mkarim            #+#    #+#             */
/*   Updated: 2022/05/12 18:56:06 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>

# define WIN_WIDTH 800
# define WIN_HEIGHT 800

typedef	struct s_fractol
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	void	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}			t_fractol;

typedef	struct s_mandelbrot
{
	double	row;
	double	col;
	double	max;
	double	c_re;
	double	c_im;
	double	x_new;
	double	x;
	double	y;
	double	iteration;
	double	scale_x;
	double	scale_y;
	double	z_x;
	double	z_y;
	double	ret;
	int		pos;
}			t_mandelbrot;

typedef	struct s_all
{
	t_fractol	*fractt;
	t_mandelbrot *mm;
}			t_all;


void	ft_init(t_all *a);
void	ft_mandelbrot(t_all *a);
void	ft_julia(t_all *a);
int		handle(int keycode, int x, int y, t_all *a);
int		handle_key(int keycode, int x, int y, t_all *a);
int		ft_handle_mouse(int x, int y, t_all *a);
int		handle_julia(int keycode, int x, int y, t_all *a);
#endif
