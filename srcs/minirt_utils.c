/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 17:28:04 by blacking          #+#    #+#             */
/*   Updated: 2019/12/26 18:56:45 by blacking         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

float	create_float(char **line)
{
	float num;
	float neg;
	float dot;
	int dix_pow;

	dot = 0;
	num = 0;
	dix_pow = 0;
	while(**line == ' ' || **line == ',')
		(*line)++;
	neg = (**line == '-') ? -1 : 1;
	if(neg == -1)
		(*line)++;
	while(ft_isdigit(**line) == 2048 || **line == '.')
	{
		if(dot == 1)
			dix_pow++;
		if(**line == '.')
			dot = 1;
		if(ft_isdigit(**line) == 2048)
			num = num * 10 + ((**line - '0') / pow(10, dix_pow));
		(*line)++;
	}
	return (num);
}
