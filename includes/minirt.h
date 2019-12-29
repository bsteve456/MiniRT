/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 10:37:11 by blacking          #+#    #+#             */
/*   Updated: 2019/12/29 13:55:21 by blacking         ###   ########.fr       */
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
	float		  width;
	float		  heigth;
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

typedef struct
{
	float ratio;
	int rgb;
}			t_aligth;

typedef struct
{
	vect	orig;
	vect	orit;
	float	fov;
}			t_cam;

typedef struct s_ray
{
	vect	orig;
	vect	dir;

}			t_ray;

typedef struct
{
	vect center;
	float radius;
	float rgb;
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
float	create_color(char **line);
vect	create_vect(char **line);
void	camera(t_list **scene, char *line);
void	A_light(t_list **scene, char *line);
void	resolution(t_list **scene, char *line);
void	sphere(t_list **scene, char *line);
void	camera_loop(t_list *scene);
data_t init_data(t_list *copy);

#endif
