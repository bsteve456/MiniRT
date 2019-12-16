/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_loop_rt.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 10:40:22 by blacking          #+#    #+#             */
/*   Updated: 2019/12/16 11:37:23 by blacking         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_ray	init_ray(int i, float j, t_widw widw)
{
	t_ray new_ray;
	new_ray.orig = 0;
	new_ray.orig = 0;
	new_ray.orig = 0;
	new_ray.dir.x = j - (widw.width / 2);
	new_ray.dir.y = i - (widw.heigth / 2);
	new_ray.dir.z = -widw.width / (2 * tan(30.0/2));

	return new_ray;
}


void	display_loop(data_t data, t_widw widw)
{
	int i;
	int j;
	t_ray ray;

	i = 0;
	j = 0;
	while(i < widw.heigth)
	{
		while(j < widw.width)
		{
			ray = init_ray(i, j, widw);
			printf("%f %f %f\n", ray.dir.x, ray.dir.y, ray.dir.z);
			mlx_pixel_put(data.mlx_ptr, data.mlx_win, i, j, 120);
			j++;
		}
		j = 0;
		i++;
	}
}
