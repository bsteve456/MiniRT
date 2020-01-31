/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow_inter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 19:39:30 by blacking          #+#    #+#             */
/*   Updated: 2020/01/31 14:20:56 by stbaleba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int	inter_shadow_sphere(t_sdaw d_ray, t_sphere *sphere)
{
	float	a;
	float	b;
	float	c;
	float	t;
	t_vect	t_vectos;

	t_vectos = vectsub(d_ray.orig, sphere->center);
	a = vectdot(d_ray.dir, d_ray.dir);
	b = 2 * vectdot(d_ray.dir, t_vectos);
	c = vectdot(t_vectos, t_vectos) - (sphere->radius * sphere->radius);
	if ((b * b) - (4 * a * c) >= 0.0000)
	{
		t = find_t0(a, b, c);
		if (t > 0.00015f)
			return (1);
	}
	return (0);
}

int	inter_shadow_plane(t_sdaw d_ray, t_plane *plane)
{
	t_vect	p0l0;
	float	t;
	float	demom;

	plane->N = normalize(plane->N);
	demom = vectdot(d_ray.dir, plane->N);
	if (fabs(demom) > 0.00001f)
	{
		p0l0 = vectsub(plane->p0, d_ray.orig);
		t = vectdot(p0l0, plane->N) / demom;
		if (t >= 0.00001f && demom <= 0)
			return (1);
	}
	return (0);
}
