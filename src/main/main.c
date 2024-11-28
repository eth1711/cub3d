/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 15:13:00 by amaligno          #+#    #+#             */
/*   Updated: 2024/11/28 18:35:10 by amaligno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	loop(void *param)
{
	t_data		*data;
	t_ray		rays[RAYS];

	data = (t_data *)param;
	// static int	frame;

	// frame++;
	// printf("frame: %i\n", frame);
	move_handler(&data->player, data->map.map);
	look_handler(&data->player);
	cast_rays(data->player, data->map, rays);
	draw_background(&data->image);
	draw_rays_3d(&data->image, rays, data->player, data->textures, data->map);
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
		"1111111111111",
		"1000000000111",
		"100P001110111",
		"1001111110111",
		"1000000000001",
		"1000001110001",
		"1000001110001",
		"1000000000111",
		"1111111111111",
		NULL
	};
	init(&data);
	printf("line len: %i\n", data.textures.north.line_len);
	printf("bpp: %i\n", data.textures.north.bpp);
	mlx_loop(data.mlx);
}
