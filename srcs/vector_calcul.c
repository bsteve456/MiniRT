/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_calcul.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 12:26:01 by blacking          #+#    #+#             */
/*   Updated: 2020/01/20 13:15:37 by blacking         ###   ########.fr       */
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

vect	crossP(vect v1, vect v2)
{
	vect res;

	res.x = (v1.y * v2.z) - (v1.z * v2.y);
	res.y = (v1.z * v2.x) - (v1.x * v2.z);
	res.z = (v1.x * v2.y) - (v1.y * v2.x);
	return res;
}
