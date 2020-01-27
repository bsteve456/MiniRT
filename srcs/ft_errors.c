/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stbaleba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 18:10:19 by stbaleba          #+#    #+#             */
/*   Updated: 2020/01/27 18:34:29 by stbaleba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int		check_params1(char *line)
{
	if(*line != '\0' && *line != ' ' && *line != '\n')
	{
		write(2, "Error\nsomething wrong with resolution params\n",45);
		return (-1);
	}
	return (1);
}

int		check_rgb(color rgb)
{
	if(rgb.b < 0 || rgb.g < 0 || rgb.r < 0)
	{
		write(2, "Error\nnegative color\n",21);
		return (-1);
	}
	return (1);
}
