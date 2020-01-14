/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow_inter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 19:39:30 by blacking          #+#    #+#             */
/*   Updated: 2020/01/14 20:09:56 by blacking         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int	inter_shadow_sphere(t_sdaw d_ray, t_sphere *sphere)
{
	float a;
	float b;
	float c;
	vect vectOS;
	
//	d_ray.orig = vectAdd(d_ray.orig, vectSub(d_ray.orig, sphere->center));
//	d_ray.orig = vectMult(d_ray.orig, 0.5);
	vectOS = vectSub(d_ray.orig, sphere->center);
	a = vectDot(d_ray.dir, d_ray.dir);
	b = 2 * vectDot(d_ray.dir, vectOS);
	c = vectDot(vectOS, vectOS) - (sphere->radius * sphere->radius);
	if((b * b) - (4 * a * c) >= 0.0000)
		return (1);
	return (0);
}

