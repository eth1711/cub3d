/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlim <etlim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 15:10:07 by etlim             #+#    #+#             */
/*   Updated: 2024/10/18 15:22:31 by etlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


// void my_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char *pixel;
	
// 	pixel = data->addr + (y * data->len_line + x * (data->bpp));
// }

int handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(data->mlx, data->win);
		data->win = NULL;
	}
	return (0);
}

int render(t_data *data)
{
	if(data->win != NULL)
		mlx_pixel_put(data->mlx, data->win, WIN_WIDTH / 2, WIN_HEIGHT / 2, RED);
	return (0);
}

int main(void)
{
    t_data	data;
    
    data.mlx = mlx_init();
    data.win = mlx_new_window(data.mlx, WIN_WIDTH, WIN_HEIGHT, "Hello my first window");
    // data.img = mlx_new_image(data.mlx, 1920, 1080);
	// data.addr = mlx_get_data_addr(data.img, &data.bpp, &data.len_line, &data.endian);
	mlx_loop_hook(data.mlx, &render, &data);
    mlx_hook(data.win, KeyPress, KeyPressMask, &handle_keypress, &data);
	mlx_loop(data.mlx);
}
