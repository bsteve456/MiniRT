/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_verif.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 09:47:34 by blacking          #+#    #+#             */
/*   Updated: 2020/01/09 14:24:23 by blacking         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void	inter_sphere(t_sphere *sphere, data_t *data)
{
	float a;
	float b;
	float c;
	vect vectOS;

	vectOS = vectSub(data->ray.orig, sphere->center);
	a = vectDot(data->ray.dir, data->ray.dir);
	b = 2 * vectDot(data->ray.dir, vectOS);
	c = vectDot(vectOS, vectOS) - (sphere->radius * sphere->radius);
	if( (b * b) - (4 * a * c)  >= 0.0000)
		mlx_pixel_put(data->mlx_ptr, data->mlx_win, data->x, data->y, sphere->rgb);
}
