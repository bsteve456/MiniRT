/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_calcul.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 12:26:01 by blacking          #+#    #+#             */
/*   Updated: 2020/01/13 10:47:18 by blacking         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

vect	vectSub(vect v1, vect v2)
{
	v1.x -= v2.x;
	v1.y -= v2.y;
	v1.z -= v2.z;
	return (v1);
}

vect	vectAdd(vect v1, vect v2)
{
	v1.x += v2.x;
	v1.y += v2.y;
	v1.z += v2.z;
	return (v1);
}

vect	vectMult(vect v1,float num)
{
	v1.x *= num;
	v1.y *= num;
	v1.z *= num;
	return (v1);
}

float	vectDot(vect v1, vect v2)
{
	float res;

	res = v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
	return (res);
}

vect	normalize(vect ray)
{
	float length;

	length = sqrt((ray.x * ray.x) + (ray.y * ray.y) + (ray.z * ray.z));
	ray.x /= length;
	ray.y /= length;
	ray.z /= length;
	return (ray);
}
