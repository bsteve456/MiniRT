/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 10:42:18 by blacking          #+#    #+#             */
/*   Updated: 2019/12/24 16:22:54 by blacking         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minirt.h"

void	minirt(char *info)
{
	int fd;
	int read_file;
	char *line;

	line = NULL;
	read_file = 1;
	fd = open(info, O_RDONLY);
	while(read_file > 0)
	{
		read_file = get_next_line(fd, &line);
		printf("%s\n", line);
	}
}


int main(int ac, char **av)
{
	if(ac == 2)
		minirt(av[1]);
}
