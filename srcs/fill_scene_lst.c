/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_scene_lst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 17:09:47 by blacking          #+#    #+#             */
/*   Updated: 2020/02/01 09:32:05 by stbaleba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int	resolution(t_list **scene, char *line)
{
	t_object	*widw;
	t_widw		*window;

	if (!(window = ft_calloc(1, sizeof(t_widw))))
		window = 0;
	if (!(widw = ft_calloc(1, sizeof(t_object))))
		widw = 0;
	widw->type = 1;
	if (check_params1(line) == -1)
		return (-1);
	window->x = create_float(&line);
	if (check_params1(line) == -1)
		return (-1);
	window->y = create_float(&line);
	if (window->x <= 0 || window->y <= 0)
	{
		write(2, "Error\nnegative value in resolution(x, y)\n", 41);
		return (-1);
	}
	window->x = (window->x > 2560) ? 2560 : window->x;
	window->y = (window->y > 1440) ? 1440 : window->y;
	widw->obj = window;
	ft_lstadd_back(scene, ft_lstnew(widw));
	return (1);
}

int	a_light(t_list **scene, char *line)
{
	t_object		*t_lighta;
	t_aligth		*aligth;

	if (!(t_lighta = ft_calloc(1, sizeof(t_object))))
		return (0);
	if (!(aligth = ft_calloc(1, sizeof(t_aligth))))
		return (0);
	t_lighta->type = 2;
	if (check_params1(line) == -1)
		return (-1);
	aligth->ratio = create_float(&line);
	if (create_color(&(aligth->rgb), &line) == -1)
		return (-1);
	aligth->rgb.r *= aligth->ratio;
	aligth->rgb.g *= aligth->ratio;
	aligth->rgb.b *= aligth->ratio;
	if (check_rgb(aligth->rgb) == -1)
		return (-1);
	t_lighta->obj = aligth;
	ft_lstadd_back(scene, ft_lstnew(t_lighta));
	return (1);
}

int	camera(t_list **scene, char *line)
{
	t_object	*a_cam;
	t_cam		*cam;

	if (!(a_cam = ft_calloc(1, sizeof(t_object))))
		return (0);
	if (!(cam = ft_calloc(1, sizeof(t_cam))))
		return (0);
	a_cam->type = 0;
	if (check_params1(line) == -1)
		return (-1);
	cam->orig = create_vect(&line);
	if (check_params1(line) == -1)
		return (-1);
	cam->orit = create_vect(&line);
	if (check_params1(line) == -1)
		return (-1);
	cam->fov = create_float(&line);
	a_cam->obj = cam;
	ft_lstadd_back(scene, ft_lstnew(a_cam));
	return (1);
}

int	light_init(t_list **scene, char *line)
{
	t_object	*a_light;
	t_light		*light;

	if (!(a_light = ft_calloc(1, sizeof(t_object))))
		return (0);
	if (!(light = ft_calloc(1, sizeof(t_light))))
		return (0);
	a_light->type = 4;
	if (check_params1(line) == -1)
		return (-1);
	light->orig = create_vect(&line);
	if (check_params1(line) == -1)
		return (-1);
	light->ratio = create_float(&line);
	if (create_color(&(light->rgb), &line) == -1)
		return (-1);
	a_light->obj = light;
	ft_lstadd_back(scene, ft_lstnew(a_light));
	return (1);
}

int	plane(t_list **scene, char *line)
{
	t_object	*a_plane;
	t_plane		*plane;

	if (!(a_plane = ft_calloc(1, sizeof(t_object))))
		return (0);
	if (!(plane = ft_calloc(1, sizeof(t_plane))))
		return (0);
	a_plane->type = 5;
	if (check_params1(line) == -1)
		return (-1);
	plane->p0 = create_vect(&line);
	if (check_params1(line) == -1)
		return (-1);
	plane->n = create_vect(&line);
	if (create_color(&(plane->rgb), &line) == -1)
		return (-1);
	a_plane->obj = plane;
	ft_lstadd_back(scene, ft_lstnew(a_plane));
	return (1);
}
