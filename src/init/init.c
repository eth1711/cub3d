/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pringles <pringles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 18:55:11 by amaligno          #+#    #+#             */
/*   Updated: 2024/12/09 14:58:39 by pringles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_hooks(t_data *data)
{
	mlx_hook(data->window, ON_DESTROY, 0, on_destroy, NULL);
	mlx_hook(data->window, ON_KEY_DOWN, (1L), on_key_down, (void *)data);
	mlx_key_hook(data->window, on_key_up, (void *)data);
	mlx_loop_hook(data->mlx, loop, (void *)data);
}

void	init_map(t_map *map)
{
	char	*tmp;
	int		m_size;
	int		y;
	int		x;

	y = 0;
	x = 0;
	map->width = 0;
	map->length = 0;
	tmp = *map->str;
	map->str = ft_split(tmp, '\n');
	free(tmp);
	while (map->str[y])
	{
		x = 0;
		while (map->str[y][x])
			x++;
		if (x > map->width)
			map->width = x;
		y++;
		if (y > map->length)
			map->length = y;
	}
	m_size = (MMAP_RATIO * 0.01) * WIN_WIDTH;
	map->wall_size = m_size / map->width;
}

void	init_mlx(t_data *data)
{
	data->mlx = mlx_init();
	data->window = mlx_new_window(data->mlx, WIN_WIDTH, WIN_HEIGHT, "cub3d");
	data->image.image = mlx_new_image(data->mlx, WIN_WIDTH, WIN_HEIGHT);
	data->image.addr = mlx_get_data_addr(
			data->image.image,
			&data->image.bpp,
			&data->image.line_len,
			&data->image.endian
			);
}

void	init(t_data *data)
{
	init_map(&data->map);
	init_mlx(data);
	init_textures(data);
	init_hooks(data);
	init_player(&data->player, &data->map);
}
