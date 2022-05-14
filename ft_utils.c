/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 14:34:35 by mkarim            #+#    #+#             */
/*   Updated: 2022/05/13 15:11:41 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_init(t_all **a)
{
	(*a)->fractt->mlx = mlx_init();
	(*a)->fractt->mlx_win = mlx_new_window((*a)->fractt->mlx, WIN_WIDTH,
			WIN_HEIGHT, "SKKET's Fractol");
	(*a)->fractt->img = mlx_new_image((*a)->fractt->mlx, WIN_WIDTH, WIN_HEIGHT);
	(*a)->fractt->addr = mlx_get_data_addr((*a)->fractt->img,
			&(*a)->fractt->bpp, &(*a)->fractt->line_length,
			&(*a)->fractt->endian);
}
