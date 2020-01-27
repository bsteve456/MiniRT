/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 10:42:18 by blacking          #+#    #+#             */
/*   Updated: 2020/01/27 17:46:52 by stbaleba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minirt.h"

int	minirt(char *info, int n)
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
		if((rfile = get_next_line(fd, &line)) == -1)
		{
			perror("Error\n");
			return (-1);
		}
		if(parse_info_scene(&scene, line) == -1)
			return (-1);
	}
	camera_loop(scene,  n);
	return (1);
}

int main(int ac, char **av)
{
	if(ac == 2)
		minirt(av[1], 0);
	else if(ac == 3 && ft_strncmp(av[2], "-save", 5) == 0)
		minirt(av[1], 1);
	else
		write(2, "Error\nno file\n", 14);
}
