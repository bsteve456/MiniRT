/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 16:29:27 by blacking          #+#    #+#             */
/*   Updated: 2019/12/24 17:07:52 by blacking         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void	parse_info_scene(t_list *scene, char *line)
{
	if(ft_strncmp(line, "R", 2) == 0 ||
		ft_strncmp(line, "A", 2) == 0 ||
		ft_strncmp(line, "c", 2) == 0)
		scene_env(scene, line);
	else if(ft_strncmp(line, "sp", 2) == 0)
		scene_object(scene, line);
}
