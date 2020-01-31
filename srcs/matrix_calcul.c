/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_calcul.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 16:27:07 by blacking          #+#    #+#             */
/*   Updated: 2020/01/31 14:09:02 by stbaleba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_vect	x_axis_rot(t_vect dir, float theta)
{
	t_vect new_dir;

	theta *= M_PI;
	new_dir.x = 1 * dir.x;
	new_dir.y = cos(theta) * dir.y + (-1 * sin(theta)) * dir.z;
	new_dir.z = (sin(theta)) * dir.y + cos(theta) * dir.z;
	return (new_dir);
}

t_vect	y_axis_rot(t_vect dir, float theta)
{
	t_vect new_dir;

	theta *= M_PI;
	new_dir.x = cos(theta) * dir.x + (sin(theta)) * dir.z;
	new_dir.y = 1 * dir.y;
	new_dir.z = (-1 * sin(theta)) * dir.x + cos(theta) * dir.z;
	return (new_dir);
}

t_vect	z_axis_rot(t_vect dir, float theta)
{
	t_vect new_dir;

	theta *= M_PI;
	new_dir.x = cos(theta) * dir.x + (-1 * sin(theta)) * dir.y;
	new_dir.y = (sin(theta)) * dir.x + cos(theta) * dir.y;
	new_dir.z = 1 * dir.z;
	return (new_dir);
}
