/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_object_lst.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 15:53:04 by blacking          #+#    #+#             */
/*   Updated: 2019/12/28 16:02:35 by blacking         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void	sphere(t_list **scene, char *line)
{
	object *sphere;
	t_sphere *sphr;
	if(!(sphere = ft_calloc(1, sizeof(object))))
		sphere = 0;
	if(!(sphr = ft_calloc(1, sizeof(t_cam))))
		sphr = 0;
	sphere->type = 3;
	sphr->center = create_vect(&line);
	sphr->radius = create_float(&line);
	sphr->rgb = create_color(&line);
	sphere->obj = sphr;
	ft_lstadd_back(scene, ft_lstnew(sphere));
}
