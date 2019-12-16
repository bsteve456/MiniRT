/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 10:37:11 by blacking          #+#    #+#             */
/*   Updated: 2019/12/16 10:44:53 by blacking         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H
# include <stdlib.h>
# include <string.h>
# include <mlx.h>

typedef struct		data_s
{
    void          *mlx_ptr;
    void          *mlx_win;
}					data_t;
void	display_loop(data_t data, int haut, int large);

#endif
