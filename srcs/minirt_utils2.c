/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 13:20:20 by blacking          #+#    #+#             */
/*   Updated: 2020/01/25 14:52:29 by blacking         ###   ########.fr       */
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

float	vectDot(vect v1, vect v2)
{
	float res;

	res = v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
	return (res);
}

int		deal_key(int key, img_lst *img_test)
{
	if(key == 97 && img_test->img)

	{
		mlx_put_image_to_window(img_test->img->mlx_ptr, img_test->img->mlx_win, img_test->img->img, 0, 0);
		img_test->img = img_test->img->next;

	}
	if(key == 65307)
		mlx_destroy_window(img_test->img->mlx_ptr, img_test->img->mlx_win);
	return (0);
}
