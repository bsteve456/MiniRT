/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 16:29:27 by blacking          #+#    #+#             */
/*   Updated: 2019/12/28 15:10:44 by blacking         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void	scene_env(t_list **scene, char *line)
{
	if(ft_strncmp(line, "R", 1) == 0)
		resolution(scene, line + 1);
	else if(ft_strncmp(line, "A", 1) == 0)
		A_light(scene, line + 1);
	else if(ft_strncmp(line, "c", 1) == 0)
		camera(scene, line + 1);
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
