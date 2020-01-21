/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_object_lst.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 15:53:04 by blacking          #+#    #+#             */
/*   Updated: 2020/01/21 23:47:31 by blacking         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void	sphere(t_list **scene, char *line)
{
	object *sphere;
	t_sphere *sphr;
	if(!(sphere = ft_calloc(1, sizeof(object))))
		sphere = 0;
	if(!(sphr = ft_calloc(1, sizeof(t_sphere))))
		sphr = 0;
	sphere->type = 3;
	sphr->center = create_vect(&line);
	sphr->radius = create_float(&line) / 2;
	sphr->rgb = create_color(&line);
	sphere->obj = sphr;
	ft_lstadd_back(scene, ft_lstnew(sphere));
}

void	square(t_list **scene, char *line)
{
	object *square;
	t_square *sqr;
	if(!(square = ft_calloc(1, sizeof(object))))
		square = 0;
	if(!(sqr = ft_calloc(1, sizeof(t_square))))
		sqr = 0;
	square->type = 6;
	sqr->p0 = create_vect(&line);
	sqr->N = create_vect(&line);
	sqr->height = create_float(&line);
	sqr->rgb = create_color(&line);
	square->obj = sqr;
	ft_lstadd_back(scene, ft_lstnew(square));
}

void	cylinder(t_list **scene, char *line)
{
	object *cylinder;
	t_cylinder *cyldr;
	if(!(cylinder = ft_calloc(1, sizeof(object))))
		cylinder = 0;
	if(!(cyldr = ft_calloc(1, sizeof(t_cylinder))))
		cyldr = 0;
	cylinder->type = 7;
	cyldr->p0 = create_vect(&line);
	cyldr->N = create_vect(&line);
	cyldr->radius = create_float(&line) / 2;
	cyldr->height = create_float(&line);
	cyldr->rgb = create_color(&line);
	cylinder->obj = cyldr;
	ft_lstadd_back(scene, ft_lstnew(cylinder));
}

void	triangle(t_list **scene, char *line)
{
	object *triangle;
	t_triangle *trgl;
	if(!(triangle = ft_calloc(1, sizeof(object))))
		triangle = 0;
	if(!(trgl = ft_calloc(1, sizeof(t_triangle))))
		trgl = 0;
	triangle->type = 8;
	trgl->p0 = create_vect(&line);
	trgl->p1 = create_vect(&line);
	trgl->p2 = create_vect(&line);
	trgl->rgb = create_color(&line);
	triangle->obj = trgl;
	ft_lstadd_back(scene, ft_lstnew(triangle));
}
