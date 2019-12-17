/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 10:37:11 by blacking          #+#    #+#             */
/*   Updated: 2019/12/17 16:11:32 by blacking         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H
# include <stdlib.h>
# include <string.h>
# include <mlx.h>
# include <math.h>
# include <stdio.h>
typedef struct		data_s
{
    void          *mlx_ptr;
    void          *mlx_win;
}					data_t;

typedef struct
{
	float x;
	float y;
	float z;
}			vect;
typedef struct s_window
{
	int			width;
	int			heigth;
}				t_widw;
typedef struct s_ray
{
	vect	orig;
	vect	dir;

}			t_ray;

typedef struct
{
	vect center;
	float radius;
}	t_sphere;
void	display_loop(data_t data, t_widw widw);
vect	vectSub(vect v1, vect v2);
float	vectDot(vect v1, vect v2);
vect	normalize(vect ray);

#endif
