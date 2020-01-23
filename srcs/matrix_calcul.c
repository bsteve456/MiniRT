/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_calcul.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 16:27:07 by blacking          #+#    #+#             */
/*   Updated: 2020/01/22 17:40:37 by blacking         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

vect	x_axis_rot(vect dir, float theta)
{
	vect new_dir;

	theta *=  M_PI;
	new_dir.x = 1 * dir.x;
	new_dir.y = cos(theta) * dir.y + (sin(theta)) * dir.z;
	new_dir.z =  (-1 * sin(theta)) * dir.y + cos(theta) * dir.z;
	return (new_dir);
}


vect	y_axis_rot(vect dir, float theta)
{
	vect new_dir;

	theta *= M_PI;
	new_dir.x = cos(theta) * dir.x + (-1 * sin(theta)) * dir.z;
	new_dir.y = 1 * dir.y;
	new_dir.z = (sin(theta)) * dir.x + cos(theta) * dir.z;
	return (new_dir);
}

vect	z_axis_rot(vect dir, float theta)
{
	vect new_dir;

	theta *=  M_PI;
	new_dir.x = cos(theta) * dir.x + (-1 * sin(theta)) * dir.y;
	new_dir.y = sin(theta) * dir.x + cos(theta) * dir.y;
	new_dir.z =  1 * dir.z;
	return (new_dir);
}
