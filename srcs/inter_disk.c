/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_disk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 10:34:33 by blacking          #+#    #+#             */
/*   Updated: 2020/01/31 17:41:51 by stbaleba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int		inter_disk(t_cylinder *cy, t_vect p, t_data *data)
{
	t_vect	pt;
	t_vect	p0l0;
	float	t;
	float	demom;
	float	d1;

	demom = vectdot(data->ray.dir, cy->n);
	if (fabs(demom) > 0.00001f)
	{
		p0l0 = vectsub(p, data->ray.orig);
		t = vectdot(p0l0, cy->n) / demom;
		if (t >= 0.00001f)
		{
			pt = vectadd(data->ray.orig, vectmult(data->ray.dir, t));
			d1 = vectdot(vectsub(pt, p), vectsub(pt, p));
			if (sqrt(d1) <= cy->radius)
			{
				data->rgbt = cy->rgb;
				temporary_value(data, t, pt, cy->n);
				return (1);
			}
		}
	}
	return (0);
}
