/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_verif.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 09:47:34 by blacking          #+#    #+#             */
/*   Updated: 2019/12/30 10:24:52 by blacking         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void	inter_sphere(t_sphere *sphere, t_ray ray, data_t *data, t_cam *cam)
{
	float a;
	float b;
	float c;
	float discr;
	vect vectOS;

	vectOS = vectSub(cam->orig, sphere->center);
	a = vectDot(ray.dir, ray.dir);
	b = 2 * vectDot(ray.dir, vectOS);
	c = vectDot(vectOS, vectOS) - (sphere->radius * sphere->radius);
	discr = (b * b) - (4 * a * c);
	if(discr >= 0.0000)
		mlx_pixel_put(data->mlx_ptr, data->mlx_win, data->x, data->y, sphere->rgb);
}
