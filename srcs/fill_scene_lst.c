/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_scene_lst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 17:09:47 by blacking          #+#    #+#             */
/*   Updated: 2019/12/28 15:23:22 by blacking         ###   ########.fr       */
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
