/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_verif.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 09:47:34 by blacking          #+#    #+#             */
/*   Updated: 2020/01/10 15:38:00 by blacking         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"


void	inter_sphere(t_sphere *sphere, data_t *data, t_list *scene)
{
	float a;
	float b;
	float c;
	float t0;
	float t1;
	float discr;
	vect vectOS;

	vectOS = vectSub(data->ray.orig, sphere->center);
	a = vectDot(data->ray.dir, data->ray.dir);
	b = 2 * vectDot(data->ray.dir, vectOS);
	c = vectDot(vectOS, vectOS) - (sphere->radius * sphere->radius);
	discr = (b * b) - (4 * a * c);
	if(discr >= 0.0000)
	{
		if(discr == 0.0)
			t0 = -b / (2 * a);
		else
		{
			t0 = (-b + sqrt(discr)) / (2 * a);
			t1 = (-b - sqrt(discr)) / (2 * a);
			if(t0 > t1)
				t0 = t1;
		}
		light_loop(t0, sphere, data, scene);
	
//		mlx_pixel_put(data->mlx_ptr, data->mlx_win, data->x, data->y, sphere->rgb);
	}
}
