/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 14:30:20 by blacking          #+#    #+#             */
/*   Updated: 2020/01/17 20:50:22 by blacking         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include 	"../includes/minirt.h"

float find_final_t(float t0, float t1, float y0, float y1)
{
	float th;
	
//	printf("%f, %f\n");
	if(y0 < -1)
	{
		if(y1 < -1)
			return (-3000);
		else
		{
			th = t0 + (t1 - t0) * (y0 + 1) / (y0 - y1);
			if(th <= 0)
				return (-3000);
			return (th);
		}
	}
	else if(y0 >= -1 && y0 <= 1)
	{
		if(t0 <= 0)
			return (-3000);
		return (t0);
	}
	else if(y0 > 1)
	{
		if(y1 > 1)
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


void	inter_cylinder_delta(float delta, float abc[3], data_t *data)
{
	float t0;
	float t1;
	float y0;
	float y1;
	float temp;

//	printf("%f\n %f\n", -abc[1], abc[1] * (-1));
	t0 = (-1 * abc[1] + sqrt(delta)) / (2 * abc[0]);
	t1 = (-1 * abc[1] - sqrt(delta)) / (2 * abc[0]);
	if(t0 > t1)
	{
		temp = t0;
		t0 = t1;
		t1 = temp;
	}
	y0 = data->ray.orig.y + data->ray.dir.y * t0;
	y1 = data->ray.orig.y + data->ray.dir.y * t1;
	if((temp = find_final_t(t0, t1, y0, y1)) > 0)
	{
//		printf("%f\n", temp);
		mlx_pixel_put(data->mlx_ptr, data->mlx_win, data->x, data->y, 255*255);
	}
}


void	inter_cylinder(t_cylinder *cylinder, data_t *data)
{
//	float a;
//	float b;
//	float c;
	float abc[3];
	float delta;

	abc[0] = data->ray.dir.x * data->ray.dir.x 
		+ data->ray.dir.z * data->ray.dir.z;
	abc[1] = 2 * data->ray.orig.x * data->ray.dir.x 
		+ 2 * data->ray.orig.z * data->ray.dir.z;
	abc[2] = data->ray.orig.x * data->ray.orig.x 
		+ data->ray.orig.z * data->ray.orig.z - (cylinder->radius* cylinder->radius);

	delta = abc[1] * abc[1] - 4 * abc[0] * abc[2];
	if(delta >= 0.0f)
		inter_cylinder_delta(delta, abc, data);
}
