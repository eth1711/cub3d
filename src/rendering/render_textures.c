/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 17:43:47 by amaligno          #+#    #+#             */
/*   Updated: 2024/11/29 19:21:32 by amaligno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_texture(t_ray ray, t_textures textures, t_image *texture,
	double *color_x)
{
	if (!ray.vert)
	{
		*color_x = (ray.end.x - floor(ray.end.x));
		if (ray.angle < M_PI && ray.angle > 0)
		{
			*texture = textures.south;
			*color_x = 1.0 - *color_x;
		}
		else
			*texture = textures.north;
	}
	else
	{
		*color_x = (ray.end.y - floor(ray.end.y));
		if (ray.angle < 3 * M_PI_2 && ray.angle > M_PI_2)
		{
			*texture = textures.east;
			*color_x = 1.0 - *color_x;
		}
		else
			*texture = textures.west;
	}
	*color_x *= texture->line_len / sizeof(int);
}

void	draw_textured_ray(t_image *img, t_rect rect, t_ray ray,
	t_textures textures)
{
	t_vectori	xy;
	t_vectord	color;
	t_image		texture;
	double		tstep_y;

	xy.x = 0;
	xy.y = 0;
	color.y = 0;
	get_texture(ray, textures, &texture, &color.x);
	tstep_y = texture.height / rect.size.y;
	while (xy.y < rect.size.y && xy.y + rect.pos.y <= WIN_HEIGHT
		&& xy.x + rect.pos.x <= WIN_WIDTH)
	{
		xy.x = 0;
		while (xy.x < rect.size.x && xy.y + rect.pos.y >= 0)
		{
			rect.color = ((int *)texture.addr)
			[(int)(color.y) *(texture.line_len / sizeof(int)) + (int)(color.x)];
			if (xy.x + rect.pos.x >= 0)
				img_pix_put(img, (xy.x + rect.pos.x), (xy.y + rect.pos.y),
					rect.color);
			xy.x++;
		}
		xy.y++;
		color.y += tstep_y;
	}
}
