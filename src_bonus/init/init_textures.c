/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 18:23:22 by amaligno          #+#    #+#             */
/*   Updated: 2024/12/10 15:35:06 by amaligno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

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
	data->textures.ceiling = create_trgb(0, 194, 12, 240);
	data->textures.floor = 0;
}
