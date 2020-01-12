/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 17:28:04 by blacking          #+#    #+#             */
/*   Updated: 2020/01/12 10:24:49 by blacking         ###   ########.fr       */
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
		if(**line == '.')
			dot = 1;
		if(ft_isdigit(**line) == 2048 && dot == 0)
			num = num * 10 + ((**line - '0') / pow(10, dot));
		if(ft_isdigit(**line) == 2048 && dot >= 1)
		{
			num += ((float)(**line - '0') / pow(10, dot));
			dot++;
		}
		(*line)++;
	}
	return (num * neg);
}

color	create_color(char **line)
{

	color rgb;

	rgb.r = create_float(line);
	rgb.g = create_float(line);
	rgb.b = create_float(line);
	return (rgb);
}

vect	create_vect(char **line)
{
	vect res;

	res.x = create_float(line);
	res.y = create_float(line);
	res.z = create_float(line);
	return (res);
}
