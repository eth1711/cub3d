/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pringles <pringles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 18:23:22 by amaligno          #+#    #+#             */
/*   Updated: 2024/12/09 10:38:56 by pringles         ###   ########.fr       */
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
	set_mlx_image(image);
}

void	init_textures(t_data *data)
{
	set_image_struct(data->mlx, &data->textures.north, "textures/mario.xpm");
	set_image_struct(data->mlx, &data->textures.east, "textures/cat_32.xpm");
	set_image_struct(data->mlx, &data->textures.south, "textures/funny.xpm");
	set_image_struct(data->mlx, &data->textures.west, "textures/funny_me.xpm");
}
