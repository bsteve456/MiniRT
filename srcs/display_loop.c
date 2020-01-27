/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_loop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 13:28:17 by blacking          #+#    #+#             */
/*   Updated: 2020/01/27 15:11:32 by stbaleba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void	display_list(t_list *scene, data_t *data)
{
	ambient_light(scene, data);
	object_parse(scene, data);
}

void	window_loop(t_list *scene, data_t *data, t_cam *cam)
{
	float i;
	float j;
	i = 0;
	while(i < data->widw->x)
	{
		j = 0;
		while(j < data->widw->y)
		{
			data = complet_ray_pixel(i, j, cam, data);
			display_list(scene, data);
			j++;
		}
		i++;
	}
}

void	display_camera(t_lst *imga, int n)
{
	img_lst  test;

	test.img = imga;
	t_lst *copy;
	copy = imga;
	test.copy = copy;
	if(n == 1)
		screenshot_loop(copy);
	else
	{
		mlx_hook(copy->mlx_win, 17, 0, &X_close, &test);
		mlx_key_hook(copy->mlx_win, &deal_key, &test);
		mlx_loop(copy->mlx_ptr);
	}
	free_imga(&imga);
}

void	init_img(data_t *data)
{
	int bpp;
	int size_line;
	int endian;

	data->img = mlx_new_image(data->mlx_ptr, data->widw->x, data->widw->y);
	data->img_data = mlx_get_data_addr(data->img, &bpp, &size_line, &endian);
}

void	camera_loop(t_list *scene, int n)
{
	object	*cam_obj;
	data_t *data;
	t_list *copy;
	t_lst *img;

	img = NULL;
	copy = scene;
	data = init_data(scene); // NULL
	while(copy)
	{
		cam_obj = copy->content;
		if(cam_obj->type == 0)
		{
			init_img(data);
			window_loop(scene, data, cam_obj->obj);
			lstadd_back(&img, lstnew(data));
		}
		copy = copy->next;
	}
	free_data(data);
	display_camera(img, n);
}
