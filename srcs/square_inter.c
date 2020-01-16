/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square_inter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 11:38:06 by blacking          #+#    #+#             */
/*   Updated: 2020/01/16 13:25:58 by blacking         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

vect	square_corner_init(float x, float y, float z)
{
	vect p;

	p.x = x;
	p.y = y;
	p.z = z;
	return (p);
}

int		dot_product(vect *corner, vect q)
{
	vect v1;
	vect v3;
	vect v4;
	vect v5;

	v1 = vectSub(corner[1], corner[0]);
	vect v2 = vectSub(corner[0], corner[3]);
	vect v6 = vectSub(corner[2], corner[1]);
	v3 = vectSub(corner[3], corner[2]);

	vect v7 = vectSub(q, corner[3]);
	vect v8 = vectSub(q, corner[1]);
	v4 = vectSub(q, corner[0]);
	v5 = vectSub(q, corner[2]);
	if(vectDot(v1, v4) > 0 && vectDot(v5, v3) > 0 && vectDot(v2, v7) > 0 && vectDot(v6, v8) > 0)
	{
		if(q.y < 2.5 && q.y > -2.5)
		{
		//	printf("%f, %f, %f\n", q.x, q.y, q.z);
			printf("%f %f\n", vectDot(v1,v4),vectDot(v3,v5));
		}
		return (1);
	}
	return (0);
}
void	corner_orientation(vect **corner, vect N)
{
	vect *new_corner = *corner;

	new_corner[0] = x_axis_rot(new_corner[0], N.x);
	new_corner[0] = y_axis_rot(new_corner[0], N.y);
	new_corner[0] = z_axis_rot(new_corner[0], N.z);

	new_corner[1] = x_axis_rot(new_corner[1], N.x);
	new_corner[1] = y_axis_rot(new_corner[1], N.y);
	new_corner[1] = z_axis_rot(new_corner[1], N.z);

	new_corner[2] = x_axis_rot(new_corner[2], N.x);
	new_corner[2] = y_axis_rot(new_corner[2], N.y);
	new_corner[2] = z_axis_rot(new_corner[2], N.z);

	new_corner[3] = x_axis_rot(new_corner[3], N.x);
	new_corner[3] = y_axis_rot(new_corner[3], N.y);
	new_corner[3] = z_axis_rot(new_corner[3], N.z);

	*corner = new_corner;
}
void	inter_square(vect Pt, t_square *square, data_t *data)
{
	vect *square_corner = ft_calloc(4, sizeof(vect));
	int color = square->rgb.r * pow(256, 2) + square->rgb.g * 256 + square->rgb.b;
	square_corner[0] = square_corner_init(square->p0.x - square->height/2, 
		square->p0.y + square->height/2, square->p0.z);
	square_corner[1] = square_corner_init(square->p0.x + square->height/2, 
		square->p0.y + square->height/2, square->p0.z);
	square_corner[2] = square_corner_init(square->p0.x + square->height/2, 
		square->p0.y - square->height/2, square->p0.z);
	square_corner[3] = square_corner_init(square->p0.x - square->height/2, 
		square->p0.y - square->height/2, square->p0.z);
	corner_orientation(&square_corner, square->N);
	if(dot_product(square_corner, Pt) == 1)
		mlx_pixel_put(data->mlx_ptr, data->mlx_win, data->x, data->y, color);
	free(square_corner);
}


void	inter_plane_square(t_square *square, data_t *data)
{
	vect p0l0;
	float t;
	float demom;
	vect Pt;

	demom = vectDot(data->ray.dir, square->N);
	if(fabs(demom) > 0.00001f) {
		p0l0 = vectSub(square->p0, data->ray.orig);
		t = vectDot(p0l0, square->N) / demom;
		if(t >= 0.00001f)
		{
			Pt = vectAdd(data->ray.orig, vectMult(data->ray.dir, t));
			inter_square(Pt, square, data);
		}
	}
}
