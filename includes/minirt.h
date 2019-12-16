/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 10:37:11 by blacking          #+#    #+#             */
/*   Updated: 2019/12/16 11:27:25 by blacking         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H
# include <stdlib.h>
# include <string.h>
# include <mlx.h>
# include <math.h>
# include <stdio.h>
typedef struct		data_s
{
    void          *mlx_ptr;
    void          *mlx_win;
}					data_t;

typedef struct
{
	float x;
	float y;
	float z;
}			vect;
typedef struct s_window
{
	int			width;
	int			heigth;
}				t_widw;
typedef struct s_ray
{
	vect	origin;
	vect	dir;

}			t_ray;
void	display_loop(data_t data, t_widw widw);

#endif
