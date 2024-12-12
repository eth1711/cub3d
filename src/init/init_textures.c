/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 18:23:22 by amaligno          #+#    #+#             */
/*   Updated: 2024/12/13 00:15:06 by amaligno         ###   ########.fr       */
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

void	set_image_struct(void *mlx, t_image *image, char *path)
{
	image->image = mlx_xpm_file_to_image(
			mlx, path, &image->width, &image->height);
	if (!image->image)
		exit_error("Xpm file error\n");
	set_mlx_image(image);
}

void	init_textures(t_data *data, t_paths paths)
{
	set_image_struct(data->mlx, &data->textures.north, paths.north);
	set_image_struct(data->mlx, &data->textures.east, paths.east);
	set_image_struct(data->mlx, &data->textures.south, paths.south);
	set_image_struct(data->mlx, &data->textures.west, paths.west);
	data->textures.ceiling = paths.ceiling;
	data->textures.floor = paths.floor;
}
