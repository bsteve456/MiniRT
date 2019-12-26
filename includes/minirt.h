/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 10:37:11 by blacking          #+#    #+#             */
/*   Updated: 2019/12/26 18:35:03 by blacking         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H
# include <stdlib.h>
# include <string.h>
# include <mlx.h>
# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include "../libft/libft.h"

typedef struct
{
	int type;
	void *obj;
}			object;

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
	float			x;
	float			y;
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
vect	x_axis_rot(vect dir, float theta);
vect	y_axis_rot(vect dir, float theta);
vect	z_axis_rot(vect dir, float theta);
void	parse_info_scene(t_list **scene, char *line);
float	create_float(char **line);
void	resolution(t_list **scene, char *line);
#endif
