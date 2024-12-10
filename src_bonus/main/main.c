/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 15:13:00 by amaligno          #+#    #+#             */
/*   Updated: 2024/12/10 23:02:43 by amaligno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	loop(void *param)
{
	t_data		*data;
	t_ray		rays[RAYS];
	static int	frames;

	if (frames != 1250)
	{
		frames++;
		return (0);
	}
	frames = 0;
	data = (t_data *)param;
	move_handler(&data->player, data->map.str);
	look_handler(&data->player);
	cast_rays(data->player, data->map, rays);
	draw_background(&data->image, data->textures);
	draw_rays_3d(&data->image, rays, data->player, data->textures);
	if (data->player.map)
	{
		draw_map(&data->image, data->map);
		draw_player(&data->image, data->player, data->map.wall_size);
		draw_rays_2d(&data->image, rays, data->map.wall_size);
	}
	mlx_put_image_to_window(data->mlx, data->window, data->image.image, 0, 0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
	{
		ft_putstr_fd("Incorrect argument amount\n", STDERR_FILENO);
		return (1);
	}
	data.map.str = parser(argv[1]);
	exit(0);
	init(&data);
	mlx_loop(data.mlx);
}
