/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 14:22:44 by mkarim            #+#    #+#             */
/*   Updated: 2022/05/07 16:39:29 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_fractol	*fract;

	fract = (t_fractol *)malloc(sizeof(t_fractol));
	if (!fract)
		return (0);
	ft_init(fract);
	if (argc == 2)
	{
		if (argv[1][0] == 'm')
			ft_mandelbrot(fract);
	}
	mlx_loop(fract->mlx);
	// mlx_destroy_window(fract->mlx, fract->mlx_win);
	// free(fract->mlx);
}
