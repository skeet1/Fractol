/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 14:22:44 by mkarim            #+#    #+#             */
/*   Updated: 2022/05/13 12:57:40 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_initial(t_mandelbrot *mandel)
{
	mandel->z_x = 4.0;
	mandel->z_y = 4.0;
	mandel->pos = 1;
}

void	ft_mandel(t_all *all)
{
	ft_initial((*all).mm);
	ft_mandelbrot(all);
	mlx_mouse_hook((*all).fractt->mlx_win, &handle, all);
	mlx_key_hook((*all).fractt->mlx_win, &handle_key, all);
}

int	main(int argc, char **argv)
{
	t_all			*all;

	all = (t_all *)malloc(sizeof(t_all));
	all->fractt = (t_fractol *)malloc(sizeof(t_fractol));
	all->mm = (t_mandelbrot *)malloc(sizeof(t_mandelbrot));
	if (argc == 2)
	{
		ft_init(&all);
		if (argv[1][0] == 'm')
			ft_mandel(all);
		else if (argv[1][0] == 'j')
		{
			ft_initial(all->mm);
			all->mm->c_re = 0.284;
			all->mm->c_im = 0.01;
			ft_julia(all);
			mlx_mouse_hook(all->fractt->mlx_win, &handle_julia, all);
			mlx_hook(all->fractt->mlx_win, 6, 0, &ft_handle_mouse, all);
		}
		mlx_key_hook(all->fractt->mlx_win, &handle_key, all);
		mlx_loop(all->fractt->mlx);
	}
}
