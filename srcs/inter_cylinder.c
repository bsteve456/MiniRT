/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 14:30:20 by blacking          #+#    #+#             */
/*   Updated: 2020/01/21 14:39:41 by blacking         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include 	"../includes/minirt.h"

float find_final_t(float t0, float t1, float y0, float y1, t_cylinder *cylinder)
{
	float th;
	float min;
	float max;

	min = cylinder->p0.y - cylinder->height / 2;
	max = cylinder->p0.y + cylinder->height / 2;

	
//	printf("%f, %f\n");
	if(y0 < min)
	{
		if(y1 < min)
			return (-3000);
		else
		{
			th = t0 + (t1 - t0) * (y0 + 1) / (y0 - y1);
			if(th <= 0)
				return (-3000);
			return (th);
		}
	}
	else if(y0 >= min && y0 <= max)
	{
		if(t0 <= 0)
			return (-3000);
		return (t0);
	}
	else if(y0 > max)
	{
		if(y1 > max)
			return (-3000);
		else
		{
			th = t0 + (t1 - t0) * (y0 - 1) / (y0 - y1);
			if(th <= 0)
				return (-3000);
			return(th);
		}
	}
	return (-3000);
}


void	inter_cylinder_delta(float delta, float abc[3], data_t *data, t_cylinder *cylinder)
{
	float t0;
	float t1;
	float y0;
	float y1;
	float temp;

	t0 = (-1 * abc[1] + sqrt(delta)) / (2 * abc[0]);
	t1 = (-1 * abc[1] - sqrt(delta)) / (2 * abc[0]);
	if(t0 > t1)
	{
		temp = t0;
		t0 = t1;
		t1 = temp;
	}
	y0 = (data->ray.orig.y - cylinder->p0.y) + data->ray.dir.y * t0;
	y1 = (data->ray.orig.y - cylinder->p0.y) + data->ray.dir.y * t1;
	if((temp = find_final_t(t0, t1, y0, y1, cylinder)) > 0)
	{
		mlx_pixel_put(data->mlx_ptr, data->mlx_win, data->x, data->y, 255*255);
	}
}




void	top_bottom_cap(t_cylinder *cy, vect p1, vect Pt, data_t *data, t_list *scene)
{
		inter_disk(cy, cy->p0, data, scene);
//			mlx_pixel_put(data->mlx_ptr, data->mlx_win, data->x, data->y, 255*255);
		inter_disk(cy, p1, data, scene);
//			mlx_pixel_put(data->mlx_ptr, data->mlx_win, data->x, data->y, 255*255);
}

void	inter_cylinder(t_cylinder *cy, data_t *data, t_list *scene)
{
	float abc[3];
	float delta;
	vect orig;
	vect dir;

	orig = data->ray.orig;
	dir = data->ray.dir;
	cy->N = normalize(cy->N);
	vect p1 = vectAdd(cy->p0, vectMult(cy->N, cy->height));
//	printf("p1 :%f, %f, %f\n", p1.x, p1.y, p1.z);
//	printf("p0 :%f, %f, %f\n", cy->p0.x, cy->p0.y, cy->p0.z);
	vect MoO = vectSub(orig, cy->p0);
	float a = vectDot(MoO, cy->N);
	float b = vectDot(dir, cy->N);
	vect V1 = (vectSub(MoO, vectMult(cy->N, a)));
	vect V2 = (vectSub(dir, vectMult(cy->N, b)));
	abc[0] = vectDot(V2, V2);
	abc[1] = 2  * vectDot(V1, V2);
	abc[2] = vectDot(V1, V1) - (cy->radius * cy->radius);
	delta = (abc[1] * abc[1]) - (4 * abc[0] * abc[2]);
	if(delta >= 0.0f)
	{
		a = find_t0(abc[0], abc[1], abc[2]);
		data->rgb = cy->rgb;
		vect Pt = vectAdd(data->ray.orig, vectMult(data->ray.dir, (double)a));
		vect MoP = vectSub(Pt, cy->p0);
		b = vectDot(MoP, cy->N);
		vect Mp = vectMult(cy->N, b);
//		if(Mp.y  == 3.0)
//			printf("%f, %f, %f\n", Pt.x, Pt.y, Pt.z);
		vect N = vectSub(MoP, Mp);
		if(Pt.y == 0.0 && Pt.x == 0.0 && Pt.z == 3.0)
		{
			printf("%f, %f, %f\n", MoP.x, MoP.y, MoP.z);
			printf("%f, %f, %f\n", Mp.x, Mp.y, Mp.z);
			printf("%f, %f, %f\n", N.x, N.y, N.z);
		}
		if(b > 0 && b < cy->height){
//		printf("%f, %f, %f\n", Pt.x, Pt.y, Pt.z);

//		printf("%f, %f, %f\n", N.x, N.y, N.z);

			if(shadow_ray(scene, Pt, data) == 0)
				light_loop(Pt, N, data, scene);
	//	mlx_pixel_put(data->mlx_ptr, data->mlx_win, data->x, data->y, 255*255);
		}
		else 
			top_bottom_cap(cy, p1, Pt, data, scene);
	}
}
