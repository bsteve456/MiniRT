/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_loop_rt.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 10:40:22 by blacking          #+#    #+#             */
/*   Updated: 2019/12/16 10:44:43 by blacking         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void	display_loop(data_t data, int haut, int large)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while(i < haut)
	{
		while(j < large)
		{
			mlx_pixel_put(data.mlx_ptr, data.mlx_win, i, j, 120);
			j++;
		}
		j = 0;
		i++;
	}
}
