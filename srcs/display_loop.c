/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_loop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 13:28:17 by blacking          #+#    #+#             */
/*   Updated: 2020/02/01 11:41:40 by stbaleba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void	display_list(t_list *scene, t_data *data)
{
	ambient_light(scene, data);
	object_parse(scene, data);
}

void	window_loop(t_list *scene, t_data *data, t_cam *cam)
{
	float i;
	float j;

	i = 0;
	while (i < data->widw->x)
	{
		j = 0;
		while (j < data->widw->y)
		{
			data = cplt_ray_pixel(i, j, cam, data);
			display_list(scene, data);
			j++;
		}
		i++;
	}
}

void	display_camera(t_lst *imga, int n)
{
	t_img_lst	test;
	t_lst		*copy;

	test.img = imga;
	copy = imga;
	test.copy = copy;
	if (n == 1)
		screenshot_loop(copy);
	else
	{
		mlx_hook(copy->mlx_win, 17, 0, &x_close, &test);
		mlx_key_hook(copy->mlx_win, &deal_key, &test);
		mlx_loop(copy->mlx_ptr);
	}
	free_imga(&imga);
}

void	init_img(t_data *data)
{
	int bpp;
	int size_line;
	int endian;

	data->img = mlx_new_image(data->mlx_ptr, data->widw->x, data->widw->y);
	data->img_data = mlx_get_data_addr(data->img, &bpp, &size_line, &endian);
}

void	camera_loop(t_list *scene, int n)
{
	t_object	*cam_obj;
	t_data		*data;
	t_list		*copy;
	t_lst		*img;
	int			na;

	img = NULL;
	copy = scene;
	data = init_data(scene);
	na = 0;
	while (copy)
	{
		cam_obj = copy->content;
		if (cam_obj->type == 0)
		{
			init_img(data);
			window_loop(scene, data, cam_obj->obj);
			lstadd_back(&img, lstnew(data));
			na++;
		}
		copy = copy->next;
	}
	free_data(data);
	if (na > 0)
		display_camera(img, n);
	else
		write(1, "Error\nNo camera.\n", 17);
}
