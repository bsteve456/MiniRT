/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_t_object_lst.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 15:53:04 by blacking          #+#    #+#             */
/*   Updated: 2020/01/31 14:15:13 by stbaleba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int		sphere(t_list **scene, char *line)
{
	t_object		*sphere;
	t_sphere	*sphr;

	if (!(sphere = ft_calloc(1, sizeof(t_object))))
		return (0);
	if (!(sphr = ft_calloc(1, sizeof(t_sphere))))
		return (0);
	sphere->type = 3;
	if (check_params1(line) == -1)
		return (-1);
	sphr->center = create_vect(&line);
	if (check_params1(line) == -1)
		return (-1);
	sphr->radius = create_float(&line) / 2;
	if (create_color(&(sphr->rgb), &line) == -1)
		return (-1);
	sphere->obj = sphr;
	ft_lstadd_back(scene, ft_lstnew(sphere));
	return (1);
}

int		square(t_list **scene, char *line)
{
	t_object		*square;
	t_square	*sqr;

	if (!(square = ft_calloc(1, sizeof(t_object))))
		return (0);
	if (!(sqr = ft_calloc(1, sizeof(t_square))))
		return (0);
	square->type = 6;
	if (check_params1(line) == -1)
		return (-1);
	sqr->p0 = create_vect(&line);
	if (check_params1(line) == -1)
		return (-1);
	sqr->N = create_vect(&line);
	if (check_params1(line) == -1)
		return (-1);
	sqr->height = create_float(&line);
	if (create_color(&(sqr->rgb), &line) == -1)
		return (-1);
	square->obj = sqr;
	ft_lstadd_back(scene, ft_lstnew(square));
	return (1);
}

int		cylinder(t_list **scene, char *line)
{
	t_object		*cylinder;
	t_cylinder	*cyldr;

	if (!(cylinder = ft_calloc(1, sizeof(t_object))))
		return (0);
	if (!(cyldr = ft_calloc(1, sizeof(t_cylinder))))
		return (0);
	cylinder->type = 7;
	if (check_params1(line) == -1)
		return (-1);
	cyldr->p0 = create_vect(&line);
	if (check_params1(line) == -1)
		return (-1);
	cyldr->N = create_vect(&line);
	if (check_params1(line) == -1)
		return (-1);
	cyldr->radius = create_float(&line) / 2;
	if (check_params1(line) == -1)
		return (-1);
	cyldr->height = create_float(&line);
	if (create_color(&(cyldr->rgb), &line) == -1)
		return (-1);
	cylinder->obj = cyldr;
	ft_lstadd_back(scene, ft_lstnew(cylinder));
	return (1);
}

int		triangle(t_list **scene, char *line)
{
	t_object		*triangle;
	t_triangle	*trgl;

	if (!(triangle = ft_calloc(1, sizeof(t_object))))
		return (0);
	if (!(trgl = ft_calloc(1, sizeof(t_triangle))))
		return (0);
	triangle->type = 8;
	if (check_params1(line) == -1)
		return (-1);
	trgl->p0 = create_vect(&line);
	if (check_params1(line) == -1)
		return (-1);
	trgl->p1 = create_vect(&line);
	if (check_params1(line) == -1)
		return (-1);
	trgl->p2 = create_vect(&line);
	if (create_color(&(trgl->rgb), &line) == -1)
		return (-1);
	triangle->obj = trgl;
	ft_lstadd_back(scene, ft_lstnew(triangle));
	return (1);
}
