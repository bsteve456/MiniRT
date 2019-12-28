/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 17:28:04 by blacking          #+#    #+#             */
/*   Updated: 2019/12/28 15:37:03 by blacking         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

float	create_float(char **line)
{
	float num;
	float neg;
	float dot;

	dot = 0;
	num = 0;
	while(**line == ' ' || **line == ',')
		(*line)++;
	neg = (**line == '-') ? -1 : 1;
	if(neg == -1)
		(*line)++;
	while(ft_isdigit(**line) == 2048 || **line == '.')
	{
		if(dot >= 1)
			dot++;
		if(**line == '.')
			dot = 1;
		if(ft_isdigit(**line) == 2048 && dot == 0)
			num = num * 10 + ((**line - '0') / pow(10, dot));
		if(ft_isdigit(**line) == 2048 && dot == 1)
			num += ((**line - '0') / pow(10, dot));
		(*line)++;
	}
	return (num * neg);
}

float	create_color(char **line)
{
	float r;
	float g;
	float b;

	r = 65536 * create_float(line);
	g = 256 * create_float(line);
	b = create_float(line);
	return (r + g + b);
}

vect	create_vect(char **line)
{
	vect res;

	res.x = create_float(line);
	res.y = create_float(line);
	res.z = create_float(line);
	return (res);
}
