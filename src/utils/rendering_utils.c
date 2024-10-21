/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 16:08:09 by amaligno          #+#    #+#             */
/*   Updated: 2024/10/21 16:31:25 by amaligno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	img_pix_put(t_image *img, int x, int y, int color)
{
	char	*pixel;
	int		i;

	i = img->bpp - 8;
	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	while (i >= 0)
	{
		/* big endian, MSB is the leftmost bit */
		if (img->endian != 0)
			*pixel++ = (color >> i) & 0xFF;
		/* little endian, LSB is the leftmost bit */
		else
			*pixel++ = (color >> (img->bpp - 8 - i)) & 0xFF;
		i -= 8;
	}
}

void	draw_rectangle(t_image *img, t_rect rect)
{
	int	y;
	int	x;

	y = 0;
	while (y < rect.size.y)
	{
		x = 0;
		while (x < rect.size.x)
		{
			img_pix_put(img, x + rect.pos.x, y + rect.pos.y,
				rect.color);
			x++;
		}
		y++;
	}
}

void	draw_ray(t_image *img, t_vectorf start, double angle, int color)
{
	int	length;

	
	length = 0;
	while (length < 50)
	{
		start.x += cos(angle);
		start.y += sin(angle);
		length++;
		img_pix_put(img, round(start.x), round(start.y), color);
	}
}
