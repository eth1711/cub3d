/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 21:06:50 by amaligno          #+#    #+#             */
/*   Updated: 2024/10/30 22:15:27 by amaligno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// void	(t_player )
// {
	
// }

// void	render_ray()
// {
	
// }

void	cast_rays(t_image *image, t_player *player, t_map map)
{
	t_ray		ray;
	t_vectord	offset;
	double		arctan;
	int			dof;

	dof = 0;
	ray.angle = player->angle;
	ray.color = create_trgb(0, 118, 137, 245);
	arctan = -1 / tan(player->angle);
	offset.y = 0;
	ray.len = -1;
	// if (!ray.angle || ray.angle == M_PI)
	// {
	// 	ray.end.y = player->pos.y;
	// 	ray.end.x = player->pos.x;
	// 	dof = DOF;
	// }
	if (ray.angle > M_PI)
	{
		ray.end.y = (int)player->pos.y - 0.0001;
		offset.y = -1;
	}
	else if (ray.angle < M_PI)
	{
		ray.end.y = (int)player->pos.y + 1;
		offset.y = 1;
	}
	ray.end.x = (player->pos.y - ray.end.y) * arctan + player->pos.x;
	offset.x = -offset.y * arctan;
	while (dof < DOF)
	{
		printf("ray.end.y %lf\n", ray.end.y);
		printf("ray.end.x %lf\n", ray.end.x);
		if (ray.end.x < 0 || ray.end.x > map.width
			|| map.map[(int)ray.end.y][(int)ray.end.x] == '1')
			break ;
		else
		{
			ray.end.x += offset.x;
			ray.end.y += offset.y;
			dof++;
		}
	}
	ray.start.x = player->pos.x * map.wall_size;
	ray.start.y = player->pos.y * map.wall_size;
	ray.end.x *= map.wall_size;
	ray.end.y *= map.wall_size;
	draw_ray(image, ray);
}