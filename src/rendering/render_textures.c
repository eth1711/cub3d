/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pringles <pringles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 17:43:47 by amaligno          #+#    #+#             */
/*   Updated: 2024/11/26 14:38:19 by pringles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// void	get_pixel(int x, int y, t_rect *rect, t_textures s_textures)
// {
	
// }

void	draw_textured_ray(t_image *img, t_rect rect,
		t_ray ray, t_textures textures)
{
	t_vectori	xy;
	t_vectord	color;
	t_vectord	tstep;

	(void)ray;
	xy.x = 0;
	xy.y = xy.x;
	color.y = 0;
	color.x = (int)(ray.end.x) % 32;
	tstep.y = 64/rect.size.y;
	while (xy.y < rect.size.y && xy.y + rect.pos.y <= WIN_HEIGHT
		&& xy.x + rect.pos.x <= WIN_WIDTH)
	{
		xy.x = 0;
		while (xy.x < rect.size.x && xy.y + rect.pos.y >= 0)
		{
			rect.color = textures.north.addr[(char)(color.y) * textures.north.line_len + (char)(color.x) * (textures.north.bpp/8)];
			rect.color = (rect.color << 8) & 0xFF;
			if (xy.x + rect.pos.x >= 0)
				img_pix_put(img, (xy.x + rect.pos.x), (xy.y + rect.pos.y),
					rect.color);
			xy.x++;
		}
		xy.y++;
		color.y += tstep.y;
	}
}
