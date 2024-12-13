/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 15:13:00 by amaligno          #+#    #+#             */
/*   Updated: 2024/12/13 18:28:31 by amaligno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	within_bounds(t_map map, t_player player)
{
	return (player.pos.x >= 0 && player.pos.y >= 0
		&& player.pos.y < map.length
		&& player.pos.x < ft_strlen(map.str[(int)player.pos.y])
		&& map.str[(int)player.pos.y][(int)player.pos.x] == '0'
	);
}

int	loop(void *param)
{
	t_data		*data;
	t_ray		rays[RAYS];

	data = (t_data *)param;
	move_handler(&data->player);
	look_handler(&data->player);
	cast_rays(data->player, data->map, rays);
	draw_background(&data->image, data->textures);
	if (within_bounds(data->map, data->player))
		draw_rays_3d(&data->image, rays, data->player, data->textures);
	mlx_put_image_to_window(data->mlx, data->window, data->image.image, 0, 0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;
	t_paths	paths;

	if (argc != 2)
	{
		ft_putstr_fd("Incorrect argument amount\n", STDERR_FILENO);
		return (1);
	}
	if (!ft_strnstr(argv[1], ".cub", ft_strlen(argv[1])))
	{
		ft_putstr_fd("Not a .cub file\n", STDERR_FILENO);
		return (1);
	}
	data.map.str = parser(argv[1], &paths);
	init(&data, paths);
	mlx_loop(data.mlx);
}
