/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 16:08:09 by amaligno          #+#    #+#             */
/*   Updated: 2024/11/22 22:19:08 by amaligno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

/* big endian, MSB is the leftmost bit */
/* little endian, LSB is the leftmost bit */
void	img_pix_put(t_image *img, int x, int y, int color)
{
	char	*pixel;
	int		i;

	i = img->bpp - 8;
	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	while (i >= 0)
	{
		if (img->endian != 0)
			*pixel++ = (color >> i) & 0xFF;
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
	x = 0;
	while (y < rect.size.y && y + rect.pos.y <= WIN_HEIGHT
		&& x + rect.pos.x <= WIN_WIDTH)
	{
		x = 0;
		while (x < rect.size.x && y + rect.pos.y >= 0)
		{
			if (x + rect.pos.x >= 0)
				img_pix_put(img, x + rect.pos.x, y + rect.pos.y,
					rect.color);
			x++;
		}
		y++;
	}
}

void	draw_ray(t_image *img, t_ray ray)
{
	unsigned long	len;

	len = 0;
	while (len < ray.len)
	{
		len++;
		ray.start.x += cos(ray.angle);
		ray.start.y += sin(ray.angle);
		if (ray.start.y < 0 || ray.start.y > WIN_HEIGHT
			|| ray.start.x < 0 || ray.start.x > WIN_WIDTH)
			break ;
		img_pix_put(img, round(ray.start.x), round(ray.start.y), ray.color);
	}
}
	// printf("ray.start.x: %lf\n", ray.start.x);
	// printf("ray.start.y: %lf\n", ray.start.y);
	// printf("ray.end.x: %lf\n", ray.end.x);
	// printf("ray.end.y: %lf\n", ray.end.y);
