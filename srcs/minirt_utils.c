/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 17:28:04 by blacking          #+#    #+#             */
/*   Updated: 2020/01/31 14:16:11 by stbaleba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

float	create_float_utils(char **line, float *dot, float num)
{
	if (**line == '.')
		*dot = 1;
	if (ft_isdigit(**line) == 2048 && *dot == 0)
		num = num * 10 + ((**line - '0') / pow(10, *dot));
	if (ft_isdigit(**line) == 2048 && *dot >= 1)
	{
		num += ((float)(**line - '0') / pow(10, *dot));
		(*dot)++;
	}
	return (num);
}

float	create_float(char **line)
{
	float num;
	float neg;
	float dot;

	dot = 0;
	num = 0;
	while (**line == ' ' || **line == ',')
		(*line)++;
	neg = (**line == '-') ? -1 : 1;
	if (neg == -1)
		(*line)++;
	while (ft_isdigit(**line) == 2048 || **line == '.')
	{
		num = create_float_utils(line, &dot, num);
		(*line)++;
	}
	return (num * neg);
}

int		create_color(color *rgb, char **line)
{
	if (check_params1(*line) == -1)
		return (-1);
	(*rgb).r = create_float(line);
	if (check_params1(*line) == -1)
		return (-1);
	(*rgb).g = create_float(line);
	if (check_params1(*line) == -1)
		return (-1);
	(*rgb).b = create_float(line);
	if (check_rgb(*rgb) == -1)
		return (-1);
	return (1);
}

t_vect	create_vect(char **line)
{
	t_vect res;

	res.x = create_float(line);
	res.y = create_float(line);
	res.z = create_float(line);
	return (res);
}

void	check_order_object(data_t *data, int n, int obj_type)
{
	if (data->temp >= 0)
	{
		if (data->t == -1)
		{
			data->t = data->temp;
			data->Pt = data->Ptemp;
			data->N = data->Ntemp;
			data->rgb = data->rgbt;
			data->n = n;
			data->type = obj_type;
		}
		else if (data->t > data->temp)
		{
			data->t = data->temp;
			data->Pt = data->Ptemp;
			data->N = data->Ntemp;
			data->rgb = data->rgbt;
			data->n = n;
			data->type = obj_type;
		}
	}
}
