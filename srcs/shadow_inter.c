/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow_inter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 19:39:30 by blacking          #+#    #+#             */
/*   Updated: 2020/01/16 20:00:35 by blacking         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int	inter_shadow_sphere(t_sdaw d_ray, t_sphere *sphere)
{
	float a;
	float b;
	float c;
	vect vectOS;
	
	vectOS = vectSub(d_ray.orig, sphere->center);
	a = vectDot(d_ray.dir, d_ray.dir);
	b = 2 * vectDot(d_ray.dir, vectOS);
	c = vectDot(vectOS, vectOS) - (sphere->radius * sphere->radius);
	if((b * b) - (4 * a * c) >= 0.0000)
	{
		float t = find_t0(a, b, c);
		if(t > 0.00015f)
		{
			printf("%f\n", t);
			return (1);
		}
	}
	return (0);
}

