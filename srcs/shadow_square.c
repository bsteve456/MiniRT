/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow_square.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 11:38:11 by blacking          #+#    #+#             */
/*   Updated: 2020/01/30 12:03:35 by stbaleba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int		shadow_square(t_sdaw d_ray, t_square *square)
{
	t_triangle trgl1;
	t_triangle trgl2;
	vect Oy = square_corner_init(0, 1, 0);
	vect OP1 = crossP(square->N, Oy);
	float d = sqrt(2 * square->height * square->height) / 2;
	OP1 = vectMult(OP1, d);
	vect p1 = vectAdd(square->p0 , OP1);
	vect OP2 = crossP(square->N, OP1);
	vect p2 = vectAdd(square->p0, OP2);
	vect OP3 = crossP(square->N, OP2);
	vect p3 = vectAdd(square->p0, OP3);
	vect OP4 = crossP(square->N, OP3);
	vect p4 = vectAdd(square->p0, OP4);
	trgl1.p0 = p3;
	trgl1.p1 = p2;
	trgl1.p2 = p4;
	trgl2.p0 = p1;
	trgl2.p1 = p2;
	trgl2.p2 = p4;
	if(shadow_triangle(d_ray, &trgl1) == 1 || shadow_triangle(d_ray, &trgl2) == 1)
		return(1);
	return (0);
}
