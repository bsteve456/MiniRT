/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 13:20:20 by blacking          #+#    #+#             */
/*   Updated: 2020/01/31 14:27:21 by stbaleba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void	put_color_to_window(data_t *data, color rgb)
{
	int x;

	x = data->x * 4 + 4 * data->widw->x * data->y;
	data->img_data[x] = rgb.b;
	data->img_data[x + 1] = rgb.g;
	data->img_data[x + 2] = rgb.r;
}

float	vectdot(t_vect v1, t_vect v2)
{
	float res;

	res = v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
	return (res);
}

int		x_close(img_lst *img_test)
{
	t_lst *imga;

	imga = img_test->img;
	mlx_destroy_window(img_test->copy->mlx_ptr, img_test->copy->mlx_win);
	free_imga(&imga);
	_Exit(0);
	return (0);
}

int		deal_key(int key, img_lst *img_test)
{
	t_lst *imga;

	imga = img_test->img;
	if (key == 0 && img_test->copy)
	{
		mlx_put_image_to_window(img_test->copy->mlx_ptr,
		img_test->copy->mlx_win, img_test->copy->img, 0, 0);
		if (img_test->copy->next != NULL)
			img_test->copy = img_test->copy->next;
	}
	if (key == 53)
	{
		mlx_destroy_window(img_test->copy->mlx_ptr, img_test->copy->mlx_win);
		free_imga(&imga);
		_Exit(0);
	}
	return (0);
}

void	temporary_value(data_t *data, float t, t_vect pt, t_vect n)
{
	data->temp = t;
	data->Ptemp = pt;
	data->Ntemp = n;
}
