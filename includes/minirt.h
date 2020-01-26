/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 10:37:11 by blacking          #+#    #+#             */
/*   Updated: 2020/01/26 11:09:53 by blacking         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
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
}			t_widw;

typedef struct
{
	int r;
	int g;
	int b;
}			color;

typedef struct
{
	float ratio;
	color rgb;
}			t_aligth;

typedef struct
{
	vect p0;
	vect N;
	color rgb;
}			t_plane;

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
	vect orig;
	float ratio;
	color rgb;
}			t_light;

typedef struct	data_s
{
    void          *mlx_ptr;
    void          *mlx_win;
	void		  *img;
	char		  *img_data;
	t_widw		  *widw;
	float		  x;
	float		  y;
	t_ray		  ray;
	float		  t;
	float		  temp;
	vect		  Pt;
	vect		  Ptemp;
	vect		  N;
	vect		  Ntemp;
	color		  rgb;
	color		  rgbt;
}				data_t;

typedef struct
{
	vect orig;
	vect dir;
	vect light_orig;
}			t_sdaw;

typedef struct
{
	vect center;
	float radius;
	color rgb;
}			t_sphere;

typedef struct
{
	vect p0;
	vect N;
	float height;
	color rgb;
}			t_square;

typedef struct
{
	vect p0;
	vect N;
	float radius;
	float height;
	color rgb;
}			t_cylinder;

typedef struct
{
	vect p0;
	vect p1;
	vect p2;
	color rgb;
}			t_triangle;

typedef struct s_lst
{
	void *mlx_ptr;
	void *mlx_win;
	void *img;
	char *img_data;
	t_widw *widw;
	struct s_lst *next;
}				t_lst;

typedef struct
{
	t_lst *img;
}				img_lst;

typedef struct bitmap_file_header {
    unsigned char   bitmap_type[2];     // 2 bytes
    int             file_size;          // 4 bytes
    short           reserved1;          // 2 bytes
    short           reserved2;          // 2 bytes
    unsigned int    offset_bits;        // 4 bytes
} bfh;

typedef struct bitmap_image_header {
    unsigned int    size_header;        // 4 bytes
    unsigned int    width;              // 4 bytes
    unsigned int    height;             // 4 bytes
    short int       planes;             // 2 bytes
    short int       bit_count;          // 2 bytes
    unsigned int    compression;        // 4 bytes
    unsigned int    image_size;         // 4 bytes
    unsigned int    ppm_x;              // 4 bytes
    unsigned int    ppm_y;              // 4 bytes
    unsigned int    clr_used;           // 4 bytes
    unsigned int    clr_important;      // 4 bytes
} bih;

vect	vectSub(vect v1, vect v2);
float	vectDot(vect v1, vect v2);
vect	vectAdd(vect v1, vect v2);
vect	vectMult(vect v1, float num);
vect	crossP(vect v1, vect v2);
vect	normalize(vect ray);
vect	x_axis_rot(vect dir, float theta);
vect	y_axis_rot(vect dir, float theta);
vect	z_axis_rot(vect dir, float theta);
void	parse_info_scene(t_list **scene, char *line);
float	create_float(char **line);
color	create_color(char **line);
vect	create_vect(char **line);
void	camera(t_list **scene, char *line);
void	A_light(t_list **scene, char *line);
void	resolution(t_list **scene, char *line);
void	sphere(t_list **scene, char *line);
void	light_init(t_list **scene, char *line);
void	plane(t_list **scene, char *line);
void	square(t_list **scene, char *line);
void	cylinder(t_list **scene, char *line);
void	triangle(t_list **scene, char *line);
void	camera_loop(t_list *scene, int n);
data_t	*init_data(t_list *copy);
data_t	*complet_ray_pixel(float i, float j, t_cam *cam, data_t *data);
void	ambient_light(t_list *scene, data_t *data);
void	inter_sphere(t_sphere *sphere, data_t *data, t_list *scene);
void	object_parse(t_list *scene, data_t *data);
void	light_loop(vect Pt, vect N, data_t *data, t_list *scene);
void	inter_plane(t_plane *plane, data_t *data, t_list *scene);
int		shadow_ray(t_list *scene, data_t *data);
int		inter_shadow_sphere(t_sdaw d_ray, t_sphere *sphere);
int		inter_shadow_plane(t_sdaw d_ray, t_plane *plane);
int		shadow_square(t_sdaw d_ray, t_square *square);
int		shadow_cylinder(t_sdaw d_ray, t_cylinder *cy);
int		shadow_triangle(t_sdaw d_ray, t_triangle *trgl);
float	find_t0(float a, float b, float c);
void	surface_color(data_t *data, color rgb);
void	inter_plane_square(t_square *square, data_t *data, t_list *scene);
void	inter_cylinder(t_cylinder *cy, data_t *data, t_list *scene);
int		inter_disk(t_cylinder *cy, vect p, data_t *data, t_list *scene);
void	inter_triangle(t_triangle *trgl, data_t *data, t_list *scene);
vect	square_corner_init(float x, float y, float z);
float	orient(vect a, vect b, vect c, vect n);
float	inter_triangle2(vect Pt, t_triangle *trgl, vect N);
void	check_order_object(data_t *data);
void	temporary_value(data_t *data, float t, vect Pt, vect N);
void	put_color_to_window(data_t *data, color rgb);
t_lst	*lstnew(data_t *content);
void	lstadd_back(t_lst **alst, t_lst *new);
int		deal_key(int key, img_lst *img_test);
int 	X_close(img_lst *img_test);
void	screenshot_loop(t_lst *imga);
#endif
