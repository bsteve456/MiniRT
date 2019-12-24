/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 10:42:18 by blacking          #+#    #+#             */
/*   Updated: 2019/12/24 17:04:50 by blacking         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minirt.h"

void	minirt(char *info)
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
		parse_info_scene(scene, line);
	}
}


int main(int ac, char **av)
{
	if(ac == 2)
		minirt(av[1]);
}
