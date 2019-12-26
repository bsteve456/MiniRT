/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 16:29:27 by blacking          #+#    #+#             */
/*   Updated: 2019/12/26 18:59:10 by blacking         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void	scene_env(t_list **scene, char *line)
{
	t_list *b;
	if(ft_strncmp(line, "R", 1) == 0)
		resolution(scene, line + 1);
	b = *scene;
	object *c = b->content;
	t_widw *d = c->obj;
}

void	parse_info_scene(t_list **scene, char *line)
{
	if(ft_strncmp(line, "R", 1) == 0 ||
		ft_strncmp(line, "A", 1) == 0 ||
		ft_strncmp(line, "c", 1) == 0)
		scene_env(scene, line);
//	else if(ft_strncmp(line, "sp", 2) == 0)
//		scene_object(scene, line);
}
