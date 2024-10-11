/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 15:13:00 by amaligno          #+#    #+#             */
/*   Updated: 2024/10/11 18:47:48 by amaligno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>
#include <time.h>

void	init(t_data *data)
{
	data->mlx = mlx_init();
	data->window = mlx_new_window(data->mlx, WIN_WIDTH, WIN_HEIGHT, "cub3d");
	data->image.image = mlx_new_image(data->mlx, WIN_WIDTH, WIN_HEIGHT);
	data->image.addr = mlx_get_data_addr(data->image.image, &data->image.bpp,
			&data->image.line_len, &data->image.endian);
	data->map.map = " \
				1111111\n \
				1000001\n \
				100N001\n \
				1111111\n \
				";
	data->map.width = 7;
	data->map.height = 4;
	data->player.x = 3 * 100;
	data->player.y = 2 * 100;
	mlx_hook(data->window, ON_DESTROY, 0, on_destroy, NULL);
}

void	draw_player(t_data *data)
{
	t_vector	box_pos;
	t_vector	box_size;

	box_pos.x = data->player.x - 10;
	box_pos.y = data->player.y - 10;
	box_size.x = 20;
	box_size.y = 20;
}

void	draw_background(t_data *data)
{
	t_rect	background;

	background.pos.x = 0;
	background.pos.y = 0;
	background.size.y = WIN_HEIGHT;
	background.size.x = WIN_WIDTH;
	background.color = create_trgb(256, 136, 186, 71);
	draw_rectangle(&data->image, background);
}

int	loop(void *param)
{
	t_data		*data;
	// static int	frames;

	data = (t_data *)param;
	draw_background(data);
	mlx_put_image_to_window(data->mlx, data->window, data->image.image, 0, 0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	(void)argc;
	(void)argv;
	init(&data);
	mlx_loop_hook(data.mlx, loop, (void *)&data);
	mlx_loop(data.mlx);
}
