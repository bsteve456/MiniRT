/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow_square.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 11:38:11 by blacking          #+#    #+#             */
/*   Updated: 2020/01/31 13:52:14 by stbaleba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_triangle		create_triangle2(t_triangle trgl, float d, t_square *square)
{
	vect oy;
	vect op1;
	vect op2;
	vect op3;
	vect op4;

	oy = vect_init(0, 1, 0);
	op1 = crossp(square->N, oy);
	op1 = vectmult(op1, d);
	op2 = crossp(square->N, op1);
	op3 = crossp(square->N, op2);
	op4 = crossp(square->N, op3);
	trgl.p0 = vectadd(square->p0, op3);
	trgl.p1 = vectadd(square->p0, op2);
	trgl.p2 = vectadd(square->p0, op4);
	return (trgl);
}

t_triangle		create_triangle(t_triangle trgl, float d, t_square *square)
{
	vect oy;
	vect op1;
	vect op2;
	vect op3;
	vect op4;

	oy = vect_init(0, 1, 0);
	op1 = crossp(square->N, oy);
	op1 = vectmult(op1, d);
	op2 = crossp(square->N, op1);
	op3 = crossp(square->N, op2);
	op4 = crossp(square->N, op3);
	trgl.p0 = vectadd(square->p0, op1);
	trgl.p1 = vectadd(square->p0, op2);
	trgl.p2 = vectadd(square->p0, op4);
	return (trgl);
}

int				shadow_square(t_sdaw d_ray, t_square *square)
{
	t_triangle		trgl1;
	t_triangle		trgl2;
	float			d;

	d = sqrt(2 * square->height * square->height) / 2;
	trgl1 = trgl_init();
	trgl2 = trgl_init();
	trgl1 = create_triangle(trgl1, d, square);
	trgl2 = create_triangle2(trgl2, d, square);
	if (shadow_triangle(d_ray, &trgl1) == 1 ||
		shadow_triangle(d_ray, &trgl2) == 1)
		return (1);
	return (0);
}
