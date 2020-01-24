/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 13:20:20 by blacking          #+#    #+#             */
/*   Updated: 2020/01/24 14:44:30 by blacking         ###   ########.fr       */
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
