/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 16:08:09 by amaligno          #+#    #+#             */
/*   Updated: 2024/10/23 19:26:47 by amaligno         ###   ########.fr       */
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

void	draw_ray(t_image *img, t_ray ray)
{
	int	len;

	len = 0;
	ray.len = sqrt((pow(ray.start.x - ray.end.x, 2)) + (pow(ray.start.y - ray.end.y, 2)));
	printf("ray.start.x: %lf\n", ray.start.x);
	printf("ray.start.y: %lf\n", ray.start.y);
	printf("ray.end.x: %lf\n", ray.end.x);
	printf("ray.end.y: %lf\n", ray.end.y);
	while (len < ray.len)
	{
		ray.start.x += cos(ray.angle);
		ray.start.y += sin(ray.angle);
		if (ray.start.y < 0 || ray.start.y > WIN_HEIGHT || ray.start.x < 0 || ray.start.x > WIN_WIDTH)
			break;
		img_pix_put(img, round(ray.start.x * len), round(ray.start.y * len), ray.color);
	}
}