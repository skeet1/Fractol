/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 14:22:44 by mkarim            #+#    #+#             */
/*   Updated: 2022/05/12 18:56:57 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_hook(int keycode, t_fractol *fract)
{
	(void)keycode;
	(void)fract;
	printf("Hello, there is a hook");
	return (0);
}

// int		handl(int keycode, t_mandelbrot **fract)
// {
// 	if (keycode == 4)
// 	{

// 	}
// }

// int	handle(int keycode, t_fractol **fract)
// {
// 	(void)fract;
// 	// printf("Hello\n");
// 	if (keycode == 5)
// 		printf("Up scroll\n");
// 	else if (keycode == 4)
// 		printf("Down Scroll\n");
// 	else if (keycode == 1)
// 		printf("Left Click\n");
// 	else if (keycode == 2)
// 		printf("Right Click\n");
// 	else if (keycode == 3)
// 		printf("Middle Scroll\n");
// 	return (0);
// }

void	ft_initial(t_mandelbrot *mandel)
{
	mandel->z_x = 4.0;
	mandel->z_y = 4.0;
	mandel->pos = 1;
}

int	main(int argc, char **argv)
{
	t_fractol		fract;
	t_mandelbrot 	mandel;
	t_all 			all;

	if (argc == 2)
	{
		all.fractt = &fract;
		all.mm = &mandel;
		ft_init(&all);
		if (argv[1][0] == 'm')
		{
			ft_initial(all.mm);
			ft_mandelbrot(&all);
			mlx_mouse_hook(all.fractt->mlx_win, &handle, &all);
			mlx_key_hook(all.fractt->mlx_win, &handle_key, &all);
		}
		else if (argv[1][0] == 'j')
		{
			ft_initial(all.mm);
			all.mm->c_re = 0.284;
			all.mm->c_im = 0.01;
			ft_julia(&all);
			mlx_mouse_hook(all.fractt->mlx_win, &handle_julia, &all);
			mlx_hook(all.fractt->mlx_win, 6, 0, &ft_handle_mouse, &all);
		}
	}
	// mlx_mouse_hook(fract->mlx_win, &handle, &fract);
	mlx_key_hook(all.fractt->mlx_win, &handle_key, &all);
	mlx_loop(all.fractt->mlx);
	// mlx_destroy_window(fract->mlx, fract->mlx_win);
	// free(fract->mlx);
}
