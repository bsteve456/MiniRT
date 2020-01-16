/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square_inter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 11:38:06 by blacking          #+#    #+#             */
/*   Updated: 2020/01/16 23:16:20 by blacking         ###   ########.fr       */
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

float orient(vect a, vect b, vect c, vect n)
{
	float res;
	vect v1;
	vect v2;

	v1 = vectSub(b, a);
	v2 = vectSub(c, a);
	res = vectDot(crossP(v1, v2), n);
	return (res);
}

int		dot_product(vect *corner, vect q, vect n)
{
	float o1;
	float o2;
	float o3;
	float o4;
	
	o1 = orient(q, corner[0], corner[1], n);
	o2 = orient(q, corner[1], corner[2], n);
	o3 = orient(q, corner[2], corner[3], n);
	o4 = orient(q, corner[3], corner[0], n);

	if((o1 >= 0 && o2 >= 0 && o3 >= 0 && o4 >= 0) ||
		(o1 < 0 && o2 < 0 && o3 < 0 && o4 < 0))
		return (1);
	return (0);
}
void	corner_orientation(vect **corner, vect N)
{
	vect *new_corner = *corner;
	int i;

	i = 0;
	while(i < 4)
	{
		new_corner[i] = x_axis_rot(normalize(new_corner[i]), N.x);
		new_corner[i] = y_axis_rot(normalize(new_corner[i]), N.y);
		new_corner[i] = z_axis_rot(normalize(new_corner[i]), N.z);
	//	printf("%f, %f, %f\n", new_corner[i].x, new_corner[i].y, new_corner[i].z);
		i++;
	}
	*corner = new_corner;
}
void	inter_square(vect Pt, t_square *square, data_t *data, t_list *scene)
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
	data->rgb = square->rgb;
	if(dot_product(square_corner, Pt, square->N) == 1)
	{
		if(shadow_ray(scene, Pt, data) == 0){
			mlx_pixel_put(data->mlx_ptr, data->mlx_win, data->x, data->y, color);
		}
	free(square_corner);
	}
}


void	inter_plane_square(t_square *square, data_t *data, t_list *scene)
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
//			mlx_pixel_put(data->mlx_ptr, data->mlx_win, data->x, data->y, 255);

			Pt = vectAdd(data->ray.orig, vectMult(data->ray.dir, t));
			inter_square(Pt, square, data, scene);
		}
	}
}
