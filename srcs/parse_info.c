/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 16:29:27 by blacking          #+#    #+#             */
/*   Updated: 2019/12/24 16:41:53 by blacking         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void	ft_parsing(scene *object, char *line)
{
	if(ft_strmcmp(line, "R", 2) == 0 ||
		ft_strmcmp(line, "A", 2) == 0 ||
		ft_strmcmp(line, "c", 2) == 0)
		scene_env(object, line + 2);
	else if(ft_strmcmp(line, "sp", 2) == 0)
		scene_object(object, line + 2);
}
