/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_loop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 13:28:17 by blacking          #+#    #+#             */
/*   Updated: 2020/01/24 18:27:37 by blacking         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void	display_list(t_list *scene, data_t *data)
{
	ambient_light(scene, data);
//	init_planes(scene, data);
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
//	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img, 0, 0);
//	mlx_loop(data->mlx_ptr);
}

void	display_camera(t_lst *imga)
{
	img_lst  test;

	test.img = imga;
//	mlx_put_image_to_window(ptr, imga->mlx_win, imga->img, 0, 0);
	mlx_key_hook(imga->mlx_win, &deal_key, &test);
	mlx_loop(imga->mlx_ptr);
}

void	init_img(data_t *data)
{
	int bpp;
	int size_line;
	int endian;

	data->img = mlx_new_image(data->mlx_ptr, data->widw->x, data->widw->y);
	data->img_data = mlx_get_data_addr(data->img, &bpp, &size_line, &endian);
}

void	camera_loop(t_list *scene)
{
	object	*cam_obj;
	data_t *data;
	t_list *copy;
	t_lst *img;
	int n = 0;

	img = NULL;
	copy = scene;
	data = init_data(scene); // NULL
	while(copy)
	{
		cam_obj = copy->content;
		if(cam_obj->type == 0)
		{
//			data = init_data(scene); // NULL
			init_img(data);
			window_loop(scene, data, cam_obj->obj);
			lstadd_back(&img, lstnew(data), n);
			n++;
		}
		copy = copy->next;
	}
	display_camera(img);
}
