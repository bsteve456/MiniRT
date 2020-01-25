/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenshot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacking <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 18:26:58 by blacking          #+#    #+#             */
/*   Updated: 2020/01/25 21:08:27 by blacking         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void	save_bitmap(char *file_name, t_lst *imga, int dpi)
{
	int fd;
	int image_size = imga->widw->x * imga->widw->y * 4;
	int file_size = 54 + image_size;
	int ppm = dpi * 39.375;
	bih bih1;
	bfh bfh1;
//	char *bmp;
//	bmp = ".bmp";
//	ft_strlcat(file_name, bmp, 4);
	ft_memcpy(&bfh1.bitmap_type, "BM", 2);
	bfh1.file_size       = file_size;
	bfh1.reserved1       = 0;
	bfh1.reserved2       = 0;
	bfh1.offset_bits     = 0;
	bih1.size_header     = sizeof(bih);
	bih1.width           = imga->widw->x;
	bih1.height          = imga->widw->y;
	bih1.planes          = 1;
	bih1.bit_count       = 32;
	bih1.compression     = 0;
	bih1.image_size      = file_size;
	bih1.ppm_x           = ppm;
	bih1.ppm_y           = ppm;
	bih1.clr_used        = 0;
	bih1.clr_important   = 0;
	fd = open(file_name, O_CREAT | O_RDWR, S_IRWXU);
//	fd = open(file_name, O_RDWR);

	write(fd, &bfh1, 14);
	write(fd, &bih1, 40);
	write(fd, imga->img_data, image_size);
	close(fd);
}


void	screenshot_loop(t_lst *imga)
{
	char **file_name = ft_calloc(10, sizeof(char *));
	int i = 0;
	file_name[0] = "0.bmp";
	file_name[1] = "1.bmp";
	file_name[2] = "2.bmp";
	file_name[3] = "3.bmp";
	file_name[4] = "4.bmp";
	file_name[5] = "5.bmp";
	file_name[6] = "6.bmp";
	file_name[7] = "7.bmp";
	file_name[8] = "8.bmp";
	file_name[9] = "9.bmp";
	while(imga)
	{
		save_bitmap(file_name[i], imga, 4000);
		imga = imga->next;
		i++;
	}
	free(file_name);
}
