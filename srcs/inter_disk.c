/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_disk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 10:34:33 by blacking          #+#    #+#             */
/*   Updated: 2020/01/23 14:44:31 by blacking         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int		inter_disk(t_cylinder *cy, vect p, data_t *data, t_list *scene)
{
	vect Pt;
	vect p0l0;
	float t;
	float demom;

	demom = vectDot(data->ray.dir, cy->N);
	if(fabs(demom) > 0.00001f) {
		p0l0 = vectSub(p, data->ray.orig);
		t = vectDot(p0l0, cy->N) / demom;
		if(t >= 0.00001f)
		{
			Pt = vectAdd(data->ray.orig, vectMult(data->ray.dir, t));
			vect v = vectSub(Pt, p);
			float d1 = vectDot(v, v);
			if(sqrt(d1) <= cy->radius)
			{
				data->rgbt = cy->rgb;
				temporary_value(data, t, Pt, cy->N);
				return (1);
			}
		}
	}
	return (0);

}
