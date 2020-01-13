/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 16:29:27 by blacking          #+#    #+#             */
/*   Updated: 2020/01/13 13:45:38 by blacking         ###   ########.fr       */
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
	else if(ft_strncmp(line, "l", 1) == 0)
		light_init(scene, line + 1);
	else if(ft_strncmp(line, "pl", 2) == 0)
		plane(scene, line + 2);
}

void	scene_object(t_list **scene, char *line)
{
	if(ft_strncmp(line, "sp", 2) == 0)
		sphere(scene, line + 2);
}

void	parse_info_scene(t_list **scene, char *line)
{
	if(ft_strncmp(line, "R", 1) == 0 ||
		ft_strncmp(line, "A", 1) == 0 ||
		ft_strncmp(line, "c", 1) == 0 ||
		ft_strncmp(line, "l", 1) == 0 ||
		ft_strncmp(line, "pl", 2) == 0)
		scene_env(scene, line);
	else if(ft_strncmp(line, "sp", 2) == 0)
		scene_object(scene, line);
}
