/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 15:13:00 by amaligno          #+#    #+#             */
/*   Updated: 2024/11/06 17:17:21 by amaligno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	loop(void *param)
{
	t_data		*data;
	t_ray		rays[FOV];
	// static int	frame;

	// frame++;
	data = (t_data *)param;
	// printf("frame: %i\n", frame);
	move_handler(&data->player, data->map.map);
	look_handler(&data->player);
	cast_rays(data->player, data->map, rays);
	draw_background(&data->image);
	draw_rays_3d(&data->image, rays, data->map, data->player);
	if (data->player.map)
	{
		draw_map(&data->image, data->map);
		draw_player(&data->image, data->player, data->map.wall_size);
		draw_rays_2d(&data->image, rays);
	}
	mlx_put_image_to_window(data->mlx, data->window, data->image.image, 0, 0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	(void)argc;
	(void)argv;
	data.map.map = (char *[]){
		"1111111",
		"1000001",
		"100P001",
		"1001111",
		"1000001",
		"1111111",
		NULL
	};
	init(&data);
	mlx_loop(data.mlx);
}
