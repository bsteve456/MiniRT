/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_object_lst.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 15:53:04 by blacking          #+#    #+#             */
/*   Updated: 2020/01/16 11:31:30 by blacking         ###   ########.fr       */
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
	sphr->radius = create_float(&line);
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

