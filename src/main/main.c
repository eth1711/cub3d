/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 15:13:00 by amaligno          #+#    #+#             */
/*   Updated: 2024/10/25 15:51:58 by amaligno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	loop(void *param)
{
	t_data		*data;
	static int	frames;

	data = (t_data *)param;
	frames++;
	move_handler(&data->player);
	look_handler(&data->player);
	if (frames == 60)
	{
		frames = 0;
		return (0);
	}
	draw_background(&data->image);
	draw_map(&data->image, data->map);
	draw_player(&data->image, &data->player);
	mlx_put_image_to_window(data->mlx, data->window, data->image.image, 0, 0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	(void)argc;
	(void)argv;
	init(&data);
	data.map = (char *[]){
		"1111111\n",
		"1000001\n",
		"100P00111\n",
		"100000101\n",
		"100000111\n",
		"1111111\n",
		NULL
	};
	mlx_loop(data.mlx);
}
