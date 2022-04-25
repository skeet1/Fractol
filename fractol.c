/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 14:22:44 by mkarim            #+#    #+#             */
/*   Updated: 2022/04/25 17:04:29 by mkarim           ###   ########.fr       */
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
	// fract->mlx = mlx_init();
	// fract->mlx_win = mlx_new_window(fract->mlx, WIN_WIDTH, WIN_HEIGHT, "SKKET's Fractol");
	if (argc == 2)
	{
		if (argv[1][0] == 'm' || argv[1][0] == 'j')
		{
			printf("hello\n");
			return (0);
		}
	}
}
