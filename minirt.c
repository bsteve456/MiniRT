/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 10:42:18 by blacking          #+#    #+#             */
/*   Updated: 2019/12/28 16:12:42 by blacking         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minirt.h"

void	minirt(char *info)
{
	int fd;
	int rfile;
	char *line;
	t_list *scene;
	object *a;
	scene = NULL;
	fd = open(info, O_RDONLY);
	line = NULL;
	rfile = 1;
	while(rfile > 0)
	{
		rfile = get_next_line(fd, &line);
		parse_info_scene(&scene, line);
	}
	while(scene)
	{
		a = scene->content;
		printf("type : %d\n", a->type);
		scene = scene->next;
	}
}


int main(int ac, char **av)
{
	if(ac == 2)
		minirt(av[1]);
}
