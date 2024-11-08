/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlim <etlim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 15:13:00 by amaligno          #+#    #+#             */
/*   Updated: 2024/11/09 01:19:45 by etlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	loop(void *param)
{
	t_data		*data;
	// static int	frame;

	// frame++;
	data = (t_data *)param;
	// printf("frame: %i\n", frame);
	move_handler(&data->player, data->map.map);
	look_handler(&data->player);
	draw_background(&data->image);
	if (data->player.map)
	{
		draw_rays(&data->image, &data->player, data->map.map);
		draw_map(&data->image, data->map);
		draw_player(&data->image, data->player, data->map.wall_size);
	}
	mlx_put_image_to_window(data->mlx, data->window, data->image.image, 0, 0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	(void)argc;
	(void)argv;
	data.map.map = parser(argv[1]);
	// init(&data);
	// mlx_loop(data.mlx);
}
