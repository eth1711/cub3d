/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 17:43:47 by amaligno          #+#    #+#             */
/*   Updated: 2024/11/28 22:40:34 by amaligno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// void	get_pixel(int x, int y, t_rect *rect, t_textures s_textures)
// {
	
// }

void	draw_textured_ray(t_image *img, t_rect rect,
		t_ray ray, t_textures textures, t_map map)
{
	t_vectori	xy;
	t_vectord	color;
	double		tstep_y;

	(void)ray;
	(void)textures;
	(void)map;
	xy.x = 0;
	xy.y = xy.x;
	color.y = 0;
	tstep_y =  32.0 / rect.size.y;
	if (!ray.vert)
		color.x = (ray.end.x - floor(ray.end.x)) * 32;
	else
		color.x = (ray.end.y - floor(ray.end.y)) * 32;
	while (xy.y < rect.size.y && xy.y + rect.pos.y <= WIN_HEIGHT
		&& xy.x + rect.pos.x <= WIN_WIDTH)
	{
		xy.x = 0;
		while (xy.x < rect.size.x && xy.y + rect.pos.y >= 0)
		{
			rect.color = *((int *)textures.north.addr + ((int)(color.y) * textures.north.line_len/sizeof(int) + (int)(color.x)));
			if (xy.x + rect.pos.x >= 0)
				img_pix_put(img, (xy.x + rect.pos.x), (xy.y + rect.pos.y),
					rect.color);
			xy.x++;
		}
		xy.y++;
		color.y += tstep_y;
	}
}
