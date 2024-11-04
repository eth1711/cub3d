/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 21:06:50 by amaligno          #+#    #+#             */
/*   Updated: 2024/11/04 18:09:06 by amaligno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_cast_h(t_player *player, t_ray *ray, t_vectord *offset, int *dof)
{
	double	arctan;

	arctan = -1 / tan(player->angle);
	ray->angle = player->angle;
	ray->color = create_trgb(0, 214, 15, 15);
	offset->y = 0;
	ray->len = -1;
	if (!ray->angle || ray->angle == M_PI)
	{
		ray->end.y = player->pos.y;
		ray->end.x = player->pos.x;
		*dof = DOF;
	}
	if (ray->angle > M_PI)
	{
		ray->end.y = (int)player->pos.y - 0.0001;
		offset->y = -1;
	}
	else
	{
		ray->end.y = (int)player->pos.y + 1;
		offset->y = 1;
	}
	ray->end.x = (player->pos.y - ray->end.y) * arctan + player->pos.x;
	offset->x = -offset->y * arctan;
}

void	init_cast_v(t_player *player, t_ray *ray, t_vectord *offset, int *dof)
{
	double	ntan;

	ntan = -tan(player->angle);
	ray->angle = player->angle;
	ray->color = create_trgb(0, 118, 137, 245);
	ray->len = -1;
	if (ray->angle == M_PI_2 || ray->angle == M_PI_2 * 3)
	{
		ray->end.y = player->pos.y;
		ray->end.x = player->pos.x;
		*dof = DOF;
	}
	if (ray->angle > M_PI_2 && ray->angle < M_PI_2 * 3)
	{
		ray->end.x = (int)player->pos.x - 0.0001;
		offset->x = -1;
	}
	else
	{
		ray->end.x = (int)player->pos.x + 1;
		offset->x = 1;
	}
	ray->end.y = (player->pos.x - ray->end.x) * ntan + player->pos.y;
	offset->y = -offset->x * ntan;
}

void	render_ray(t_image *image, t_ray ray, t_player *player, t_map map)
{
	ray.start.x = player->pos.x * map.wall_size;
	ray.start.y = player->pos.y * map.wall_size;
	ray.end.x *= map.wall_size;
	ray.end.y *= map.wall_size;
	draw_ray(image, ray);
}

void	cast_ray(t_ray *ray, t_map map, t_vectord offset, int dof)
{
	while (dof < DOF)
	{
		printf("ray.end.y %lf\n", ray->end.y);
		printf("ray->end.x %lf\n", ray->end.x);
		if (ray->end.x < 0 || ray->end.x > map.width
			|| ray->end.y < 0 || ray->end.y > map.length)
			break ;
		if (map.map[(int)ray->end.y][(int)ray->end.x] == '1')
			break ;
		else
		{
			ray->end.x += offset.x;
			ray->end.y += offset.y;
			dof++;
		}
	}
}

void	cast_rays(t_image *image, t_player *player, t_map map)
{
	t_ray		ray_v;
	t_ray		ray_h;
	t_vectord	offset_h;
	t_vectord	offset_v;
	int			dof;

	dof = 0;
	init_cast_h(player, &ray_h, &offset_h, &dof);
	init_cast_v(player, &ray_v, &offset_v, &dof);
	cast_ray(&ray_h, map, offset_h, dof);
	cast_ray(&ray_v, map, offset_v, dof);
	if (ray_h.len < ray_h.len)
		render_ray(image, &ray_h, player, map);
	else
		render_ray(image, &ray_v, player, map);
}
