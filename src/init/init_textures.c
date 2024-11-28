/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 18:23:22 by amaligno          #+#    #+#             */
/*   Updated: 2024/11/27 18:06:32 by amaligno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_mlx_image(t_image *image)
{
	image->addr = mlx_get_data_addr(
			image->image,
			&image->bpp,
			&image->line_len,
			&image->endian
			);
}

void	init_textures(t_data *data)
{
	int	x;
	int	y;

	data->textures.north.image = mlx_xpm_file_to_image(
			data->mlx, "./textures/cat_32.xpm", &x, &y);
	set_mlx_image(&data->textures.north);
	// data->textures.south = mlx_xpm_file_to_image(data->mlx, "", 32, 32);
	// data->textures.east = mlx_xpm_file_to_image(data->mlx, "", 32, 32);
	// data->textures.west = mlx_xpm_file_to_image(data->mlx, "", 32, 32);
}