/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data_ray.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 13:42:47 by blacking          #+#    #+#             */
/*   Updated: 2020/02/03 09:00:46 by stbaleba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_widw		*t_object_widw(t_list *copy)
{
	t_object *widw;

	while (copy)
	{
		widw = copy->content;
		if (widw->type == 1)
			return (widw->obj);
		copy = copy->next;
	}
	return (NULL);
}

t_data		*init_data(t_list *copy)
{
	t_data *res;
	t_widw *widw;

	if (!(res = ft_calloc(1, sizeof(t_data))))
		return (NULL);
	if ((res->mlx_ptr = mlx_init()) == NULL)
		return (NULL);
	if ((widw = t_object_widw(copy)) == NULL)
		return (NULL);
	res->widw = widw;
	if ((res->mlx_win =
	mlx_new_window(res->mlx_ptr, widw->x, widw->y, "minirt")) == NULL)
		return (NULL);
	return (res);
}

t_ray		init_ray(float i, float j, t_widw *widw, t_cam *cam)
{
	t_ray new_ray;

	new_ray.dir.x = i - (widw->x / 2);
	new_ray.dir.y = (widw->y / 2) - j;
	new_ray.dir.z = ((widw->y / 2) / (tan((M_PI * 0.5 * cam->fov) / 180.0)));
	new_ray.dir = normalize(vectsub(new_ray.dir, cam->orig));
	new_ray.dir = x_axis_rot(new_ray.dir, cam->orit.x);
	new_ray.dir = y_axis_rot(new_ray.dir, cam->orit.y);
	new_ray.dir = z_axis_rot(new_ray.dir, cam->orit.z);
	new_ray.orig = cam->orig;
	return (new_ray);
}

t_data		*cplt_ray_pixel(float i, float j, t_cam *cam, t_data *data)
{
	data->x = i;
	data->y = j;
	data->ray = init_ray(i, j, data->widw, cam);
	return (data);
}
