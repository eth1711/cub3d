/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pringles <pringles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 15:13:00 by amaligno          #+#    #+#             */
/*   Updated: 2024/12/09 20:47:57 by pringles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	loop(void *param)
{
	t_data		*data;
	t_ray		rays[RAYS];

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
	init(&data);
	mlx_loop(data.mlx);
}
