#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <mlx.h>

typedef struct    data_s
{
    void          *mlx_ptr;
    void          *mlx_win;
}                 data_t;
int main(void)
{
    data_t        data;
	int i = 0;
	int j = 0;
	int hauteur = 1024;
	int largeur = 1024;
    if ((data.mlx_ptr = mlx_init()) == NULL)
        return (EXIT_FAILURE);
	if ((data.mlx_win = mlx_new_window(data.mlx_ptr, hauteur, largeur, "Hello world")) == NULL)
		return (EXIT_FAILURE);
	while(i < hauteur)
	{
		while(j < largeur)
		{
			mlx_pixel_put(data.mlx_ptr, data.mlx_win, i, j, 120);
			j++;
		}
		j = 0;
		i++;
	}
    mlx_loop(data.mlx_ptr);
    return (EXIT_SUCCESS);
}
