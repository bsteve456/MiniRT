/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow_cylinder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 11:52:20 by blacking          #+#    #+#             */
/*   Updated: 2020/01/27 11:56:22 by stbaleba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

float find_delta_s(t_sdaw d_ray, t_cylinder *cy)
{
	vect V1;
	vect V2;
	vect MoO;
	float abc[3];

	MoO = vectSub(d_ray.orig, cy->p0);
	V1 = (vectSub(MoO, vectMult(cy->N,  vectDot(MoO, cy->N))));
	V2 = (vectSub(d_ray.dir,
	vectMult(cy->N, vectDot(d_ray.dir, cy->N))));
	abc[0] = vectDot(V2, V2);
	abc[1] = 2  * vectDot(V1, V2);
	abc[2] = vectDot(V1, V1) - (cy->radius * cy->radius);
	return ((abc[1] * abc[1]) - (4 * abc[0] * abc[2]));
}

int		shadow_cylinder(t_sdaw d_ray, t_cylinder *cy)
{
	float delta;

	cy->N = normalize(cy->N);
	delta = find_delta_s(d_ray, cy);
	if(delta >= 0.0f)
		return (1);
	return (0);
}
