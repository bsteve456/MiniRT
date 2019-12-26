/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_scene_lst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 17:09:47 by blacking          #+#    #+#             */
/*   Updated: 2019/12/26 18:56:43 by blacking         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void	resolution(t_list **scene, char *line)
{
	object *widw;
	t_widw	*window;
	
	window = ft_calloc(1, sizeof(t_widw));
	widw = ft_calloc(1, sizeof(object));
	widw->type = 1;
	window->x = create_float(&line);
	window->y = create_float(&line);
	widw->obj = window;
	ft_lstadd_back(scene, ft_lstnew(widw));
}
