/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_triangle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 23:49:09 by blacking          #+#    #+#             */
/*   Updated: 2020/01/22 00:28:29 by blacking         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void	inter_triangle(t_triangle *trgl, data_t *data, t_list *scene)
{
	vect A = vectSub(trgl->p1, trgl->p0);
	vect B = vectSub(trgl->p2, trgl->p0);
	vect N = crossP(A, B);
	N = normalize(N);
	float D = vectDot(N, trgl->p0);
	float t = (vectDot(N, data->ray.orig) + D) / vectDot(N, data->ray.dir);

	if(t > 0.0f)
	{
		vect Pt = vectAdd(data->ray.orig, vectMult(data->ray.dir, (double)t));
		vect edge0 = vectSub(trgl->p1, trgl->p0);
		vect edge1 = vectSub(trgl->p2, trgl->p1);
		vect edge2 = vectSub(trgl->p0, trgl->p2);
		vect C0 = vectSub(Pt, trgl->p0);
		vect C1 = vectSub(Pt, trgl->p1);
		vect C2 = vectSub(Pt, trgl->p2);
		if(vectDot(N, crossP(edge0, C0)) > 0 &&
			vectDot(N, crossP(edge1, C1)) > 0 &&
			vectDot(N, crossP(edge2, C2)) > 0)
		{
			data->rgb = trgl->rgb;
//				mlx_pixel_put(data->mlx_ptr, data->mlx_win, data->x, data->y, 255);
			if(shadow_ray(scene, Pt, data) == 0)
				light_loop(Pt, N, data, scene);
		}
	}
}

