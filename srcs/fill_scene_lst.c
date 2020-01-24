/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_scene_lst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 17:09:47 by blacking          #+#    #+#             */
/*   Updated: 2020/01/24 14:27:27 by blacking         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void	resolution(t_list **scene, char *line)
{
	object *widw;
	t_widw	*window;
	
	if(!(window = ft_calloc(1, sizeof(t_widw))))
		window = 0;
	if(!(widw = ft_calloc(1, sizeof(object))))
		widw = 0;
	widw->type = 1;
	window->x = create_float(&line);
	window->y = create_float(&line);
	widw->obj = window;
	ft_lstadd_back(scene, ft_lstnew(widw));
}

void	A_light(t_list **scene, char *line)
{
	object *A_light;
	t_aligth *aligth;

	if(!(A_light = ft_calloc(1, sizeof(object))))
		A_light = 0;
	if(!(aligth = ft_calloc(1, sizeof(t_aligth))))
		aligth = 0;
	A_light->type = 2;
	aligth->ratio = create_float(&line);
	aligth->rgb = create_color(&line);
	aligth->rgb.r *= aligth->ratio;
	aligth->rgb.g *= aligth->ratio;
	aligth->rgb.b *= aligth->ratio;
	A_light->obj = aligth;
	ft_lstadd_back(scene, ft_lstnew(A_light));
}

void	camera(t_list **scene, char *line)
{
	object *a_cam;
	t_cam *cam;

	if(!(a_cam = ft_calloc(1, sizeof(object))))
		a_cam = 0;
	if(!(cam = ft_calloc(1, sizeof(t_cam))))
		cam = 0;
	a_cam->type = 0;
	cam->orig = create_vect(&line);
	cam->orit = create_vect(&line);
	cam->fov = create_float(&line);
	a_cam->obj = cam;
	ft_lstadd_back(scene, ft_lstnew(a_cam));
}

void	light_init(t_list **scene, char *line)
{
	object *a_light;
	t_light *light;

	if(!(a_light = ft_calloc(1, sizeof(object))))
		a_light = 0;
	if(!(light = ft_calloc(1, sizeof(t_light))))
		light = 0;
	a_light->type = 4;
	light->orig = create_vect(&line);
	light->ratio = create_float(&line);
	light->rgb = create_color(&line);
	a_light->obj = light;
	ft_lstadd_back(scene, ft_lstnew(a_light));
}

void	plane(t_list **scene, char *line)
{
	object *a_plane;
	t_plane *plane;

	if(!(a_plane = ft_calloc(1, sizeof(object))))
		a_plane = 0;
	if(!(plane = ft_calloc(1, sizeof(t_plane))))
		plane = 0;
	a_plane->type = 5;
	plane->p0 = create_vect(&line);
	plane->N = create_vect(&line);
	plane->rgb = create_color(&line);
	a_plane->obj = plane;
	ft_lstadd_back(scene, ft_lstnew(a_plane));
}
