/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 10:42:18 by blacking          #+#    #+#             */
/*   Updated: 2020/01/26 11:07:51 by blacking         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minirt.h"

void	minirt(char *info, int n)
{
	int fd;
	int rfile;
	char *line;
	t_list *scene;

	scene = NULL;
	fd = open(info, O_RDONLY);
	line = NULL;
	rfile = 1;
	while(rfile > 0)
	{
		rfile = get_next_line(fd, &line);
		parse_info_scene(&scene, line);
	}
	camera_loop(scene,  n);
}

int main(int ac, char **av)
{
	if(ac == 2)
		minirt(av[1], 0);
	else if(ac == 3 && ft_strncmp(av[2], "-save", 5) == 0)
		minirt(av[1], 1);
}
