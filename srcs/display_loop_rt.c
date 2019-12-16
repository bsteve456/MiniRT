/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_loop_rt.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 10:40:22 by blacking          #+#    #+#             */
/*   Updated: 2019/12/16 14:38:25 by blacking         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_ray	init_ray(float i, float j, t_widw widw)
{
	t_ray new_ray;
	new_ray.orig.x = 0.0;
	new_ray.orig.y = 0.0;
	new_ray.orig.z = 0.0;
	new_ray.dir.x = (widw.width / 2) - j;
	new_ray.dir.y = (widw.heigth / 2) - i;
	new_ray.dir.z = -widw.width /(2 * tan(10 * 0.5));

	return new_ray;
}

int		inter_sphere(t_sphere sphere, t_ray ray)
{
	float a;
	float b;
	float c;
	float discr;
	vect vectOS;
	vectOS = vectSub(ray.orig, sphere.center);
	a = vectDot(ray.dir, ray.dir);
	b = 2 * vectDot(ray.dir, vectOS);
	c = vectDot(vectOS, vectOS) - (sphere.radius * sphere.radius);
	discr = b * b - 4 * a * c;
	if(discr >= 0.0)
			return(1);
	return (0);
}

void	display_loop(data_t data, t_widw widw)
{
	float i;
	float j;
	t_ray ray;

	t_sphere sphere;

	sphere.center.x = 0.0;
	sphere.center.y = 0.0;
	sphere.center.z = 20.6;
	sphere.radius = 12.6;
	i = 0.0;
	j = 0.0;
	while(i <= widw.heigth)
	{
		j = 0;
		while(j <= widw.width)
		{
			ray = init_ray(i, j, widw);
			printf("%f %f %f\n", ray.dir.x, ray.dir.y, ray.dir.z);
			if(inter_sphere(sphere, ray) == 1)
			{
				mlx_pixel_put(data.mlx_ptr, data.mlx_win, i, j, 170 + 5 + 12);
			}
			j++;
		}
		i++;
	}
}
