/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 16:29:27 by blacking          #+#    #+#             */
/*   Updated: 2020/01/27 17:36:41 by stbaleba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int	scene_env(t_list **scene, char *line)
{
	if(ft_strncmp(line, "R", 1) == 0)
		return (resolution(scene, line + 1));
	else if(ft_strncmp(line, "A", 1) == 0)
		return (A_light(scene, line + 1));
	else if(ft_strncmp(line, "c", 1) == 0)
		return (camera(scene, line + 1));
	else if(ft_strncmp(line, "l", 1) == 0)
		return (light_init(scene, line + 1));
	return (1);
}

int	scene_object(t_list **scene, char *line)
{
	if (ft_strncmp(line, "sp", 2) == 0)
		return (sphere(scene, line + 2));
	else if (ft_strncmp(line, "sq", 2) == 0)
		return (square(scene, line + 2));
	else if (ft_strncmp(line, "cy", 2) == 0)
		return (cylinder(scene, line + 2));
	else if (ft_strncmp(line, "tr", 2) == 0)
		return (triangle(scene, line + 2));
	else if (ft_strncmp(line, "pl", 2) == 0)
		return (plane(scene, line + 2));
	return (1);
}

int	parse_info_scene(t_list **scene, char *line)
{
	if(ft_strncmp(line, "R", 1) == 0 ||
		ft_strncmp(line, "A", 1) == 0 ||
		(ft_strncmp(line, "c", 1) == 0 &&
		 ft_strncmp(line, "cy", 2) != 0) ||
		ft_strncmp(line, "l", 1) == 0)
		return (scene_env(scene, line));
	else if(ft_strncmp(line, "sp", 2) == 0 ||
		ft_strncmp(line, "sq", 2) == 0 || 
		ft_strncmp(line, "cy", 2) == 0 ||
		ft_strncmp(line, "tr", 2) == 0 ||
		ft_strncmp(line, "pl", 2) == 0)
		return(scene_object(scene, line));
	free(line);
	return (1);
}
