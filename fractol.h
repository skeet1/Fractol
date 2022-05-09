/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 14:23:39 by mkarim            #+#    #+#             */
/*   Updated: 2022/05/08 13:35:58 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>

# define WIN_WIDTH 1000
# define WIN_HEIGHT 800

typedef	struct s_data
{
	void	*img;
	void	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}			t_data;

typedef	struct s_fractol
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
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
}			t_mandelbrot;


void	ft_init(t_fractol *fract);
void	ft_mandelbrot(t_fractol *fract);
void	ft_julia(t_fractol *fract);

#endif
