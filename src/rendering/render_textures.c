/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 17:43:47 by amaligno          #+#    #+#             */
/*   Updated: 2024/11/22 22:20:27 by amaligno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_textured_ray(t_image *img, t_rect rect,
		t_ray ray, t_textures textures)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (y < rect.size.y && y + rect.pos.y <= WIN_HEIGHT
		&& x + rect.pos.x <= WIN_WIDTH)
	{
		x = 0;
		while (x < rect.size.x && y + rect.pos.y >= 0)
		{
			if (x + rect.pos.x >= 0)
				img_pix_put(img, roundf(x + rect.pos.x), roundf(y + rect.pos.y),
					rect.color);
			x++;
		}
		y++;
	}
}
