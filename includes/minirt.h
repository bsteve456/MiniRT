/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_bis.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stbaleba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 15:38:33 by stbaleba          #+#    #+#             */
/*   Updated: 2020/02/01 08:56:12 by stbaleba         ###   ########.fr       */
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
	int				type;
	void			*obj;
}					t_object;

typedef struct
{
	float			x;
	float			y;
	float			z;
}					t_vect;

typedef struct		s_window
{
	float			x;
	float			y;
}					t_widw;

typedef struct
{
	int				r;
	int				g;
	int				b;
}					t_color;

typedef struct
{
	float			ratio;
	t_color			rgb;
}					t_aligth;

typedef struct
{
	t_vect			p0;
	t_vect			n;
	t_color			rgb;
}	t_plane;

typedef struct
{
	t_vect			orig;
	t_vect			orit;
	float			fov;
}	t_cam;

typedef struct		s_ray
{
	t_vect			orig;
	t_vect			dir;

}					t_ray;

typedef struct
{
	t_vect			orig;
	float			ratio;
	t_color			rgb;
}	t_light;

typedef struct		s_data
{
	void			*mlx_ptr;
	void			*mlx_win;
	void			*img;
	char			*img_data;
	t_widw			*widw;
	float			x;
	float			y;
	t_ray			ray;
	float			t;
	float			temp;
	t_vect			pt;
	t_vect			ptemp;
	t_vect			n;
	t_vect			ntemp;
	t_color			rgb;
	t_color			rgbt;
	int				na;
	int				type;
}					t_data;

typedef struct
{
	t_vect			orig;
	t_vect			dir;
	t_vect			light_orig;
}	t_sdaw;

typedef struct
{
	t_vect			center;
	float			radius;
	t_color			rgb;
}	t_sphere;

typedef struct
{
	t_vect			p0;
	t_vect			n;
	float			height;
	t_color			rgb;
}	t_square;

typedef struct
{
	t_vect			p0;
	t_vect			n;
	float			radius;
	float			height;
	t_color			rgb;
}	t_cylinder;

typedef struct
{
	t_vect			p0;
	t_vect			p1;
	t_vect			p2;
	t_color			rgb;
}	t_triangle;

typedef struct		s_lst
{
	void			*mlx_ptr;
	void			*mlx_win;
	void			*img;
	char			*img_data;
	float			x;
	float			y;
	struct s_lst	*next;
}					t_lst;

typedef struct		s_img_lst
{
	t_lst			*img;
	t_lst			*copy;
}					t_img_lst;

typedef struct		s_bitmap_file_header
{
	unsigned char	bitmap_type[2];
	int				file_size;
	short			reserved1;
	short			reserved2;
	unsigned int	offset_bits;
}					t_bfh;

typedef struct		s_bitmap_image_header
{
	unsigned int	size_header;
	unsigned int	width;
	unsigned int	height;
	short int		planes;
	short int		bit_count;
	unsigned int	compression;
	unsigned int	image_size;
	unsigned int	ppm_x;
	unsigned int	ppm_y;
	unsigned int	clr_used;
	unsigned int	clr_important;
}					t_bih;

t_vect				vectsub(t_vect v1, t_vect v2);
float				vectdot(t_vect v1, t_vect v2);
t_vect				vectadd(t_vect v1, t_vect v2);
t_vect				vectmult(t_vect v1, float num);
t_vect				crossp(t_vect v1, t_vect v2);
t_vect				normalize(t_vect ray);
t_vect				x_axis_rot(t_vect dir, float theta);
t_vect				y_axis_rot(t_vect dir, float theta);
t_vect				z_axis_rot(t_vect dir, float theta);
int					parse_info_scene(t_list **scene, char *line);
float				create_float(char **line);
int					create_color(t_color *rgb, char **line);
t_vect				create_vect(char **line);
int					camera(t_list **scene, char *line);
int					a_light(t_list **scene, char *line);
int					resolution(t_list **scene, char *line);
int					sphere(t_list **scene, char *line);
int					light_init(t_list **scene, char *line);
int					plane(t_list **scene, char *line);
int					square(t_list **scene, char *line);
int					cylinder(t_list **scene, char *line);
int					triangle(t_list **scene, char *line);
void				camera_loop(t_list *scene, int n);
t_data				*init_data(t_list *copy);
t_data				*cplt_ray_pixel(float i, float j, t_cam *cam, t_data *data);
void				ambient_light(t_list *scene, t_data *data);
void				inter_sphere(t_sphere *sphere, t_data *data);
void				object_parse(t_list *scene, t_data *data);
void				lght_lp(t_vect pt, t_vect n, t_data *data, t_list *scene);
void				inter_plane(t_plane *plane, t_data *data);
int					shadow_ray(t_list *scene, t_data *data, t_color rgb);
int					inter_shadow_sphere(t_sdaw d_ray, t_sphere *sphere);
int					inter_shadow_plane(t_sdaw d_ray, t_plane *plane);
int					shadow_square(t_sdaw d_ray, t_square *square);
int					shadow_cylinder(t_sdaw d_ray, t_cylinder *cy);
int					shadow_triangle(t_sdaw d_ray, t_triangle *trgl);
float				find_t0(float a, float b, float c);
void				surface_color(t_data *data, t_color rgb);
int					inter_plane_square(t_square *square, t_data *data);
void				inter_cylinder(t_cylinder *cy, t_data *data);
int					inter_disk(t_cylinder *cy, t_vect p, t_data *data);
int					inter_triangle(t_triangle *trgl, t_data *data);
t_vect				vect_init(float x, float y, float z);
float				inter_triangle2(t_vect pt, t_triangle *trgl, t_vect n);
void				check_order_object(t_data *data, int n, int obj_type);
void				temporary_value(t_data *data, float t, t_vect pt, t_vect n);
void				put_color_to_window(t_data *data, t_color rgb);
t_lst				*lstnew(t_data *content);
void				lstadd_back(t_lst **alst, t_lst *new);
int					deal_key(int key, t_img_lst *img_test);
int					x_close(t_img_lst *img_test);
void				screenshot_loop(t_lst *imga);
void				free_data(t_data *data);
void				free_imga(t_lst **imga);
int					check_params1(char *line);
int					check_rgb(t_color rgb);
t_vect				find_normal(t_vect pt, t_cylinder *cy);
t_vect				find_n(t_triangle *trgl);
t_triangle			trgl_init(void);
t_triangle			create_triangle(t_triangle trgl, float d, t_square *square);
t_triangle			create_trngle2(t_triangle trgl, float d, t_square *square);
#endif
