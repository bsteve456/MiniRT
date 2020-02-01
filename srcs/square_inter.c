/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square_inter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 11:38:06 by blacking          #+#    #+#             */
/*   Updated: 2020/02/01 09:18:44 by stbaleba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_vect		vect_init(float a, float b, float c)
{
	t_vect res;

	res.x = a;
	res.y = b;
	res.z = c;
	return (res);
}

t_triangle	trgl_init(void)
{
	t_triangle	res;

	res.p0 = vect_init(0, 0, 0);
	res.p1 = vect_init(0, 0, 0);
	res.p2 = vect_init(0, 0, 0);
	return (res);
}

int			inter_plane_square(t_square *square, t_data *data)
{
	t_triangle	trgl2;
	t_triangle	trgl1;
	float		d;

	square->n = normalize(square->n);
	d = sqrt(2 * square->height * square->height) / 2;
	trgl1 = trgl_init();
	trgl2 = trgl_init();
	trgl1 = create_triangle(trgl1, d, square);
	trgl2 = create_trngle2(trgl2, d, square);
	if (inter_triangle(&trgl1, data) == 1 || inter_triangle(&trgl2, data) == 1)
	{
		data->rgbt = square->rgb;
		return (1);
	}
	return (0);
}
