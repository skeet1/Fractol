/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 14:34:35 by mkarim            #+#    #+#             */
/*   Updated: 2022/04/25 21:48:35 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_init(t_fractol *fract)
{
	fract->mlx = mlx_init();
	fract->mlx_win = mlx_new_window(fract->mlx, WIN_WIDTH, WIN_HEIGHT, "SKKET's Fractol");
	fract->img = mlx_new_image(fract->mlx, WIN_WIDTH, WIN_HEIGHT);
}
