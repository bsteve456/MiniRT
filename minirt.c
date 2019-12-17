/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 10:42:18 by blacking          #+#    #+#             */
/*   Updated: 2019/12/17 19:28:29 by blacking         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minirt.h"

int main(void)
{
    data_t		data;
	t_widw		window;

	window.heigth = 1000;
	window.width = 1000;
	if ((data.mlx_ptr = mlx_init()) == NULL)
		return (EXIT_FAILURE);
	if ((data.mlx_win = mlx_new_window(data.mlx_ptr, window.width, window.heigth, "Hello world")) == NULL)
		return (EXIT_FAILURE);
	display_loop(data, window);
    mlx_loop(data.mlx_ptr);
    return (EXIT_SUCCESS);
}
