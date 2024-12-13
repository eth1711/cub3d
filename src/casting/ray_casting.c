/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 21:06:50 by amaligno          #+#    #+#             */
/*   Updated: 2024/12/13 15:29:40 by amaligno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_ray_h(t_player player, t_ray *ray, t_vectord *offset)
{
	double	arctan;

	arctan = -1 / tan(player.angle);
	ray->angle = player.angle;
	ray->vert = false;
	ray->color = create_trgb(0, 214, 15, 15);
	if (ray->angle == 0 || ray->angle == M_PI)
	{
		ray->end = (t_vectord){1000000, 1000000};
		*offset = (t_vectord){0, 0};
	}
	if (ray->angle > M_PI)
	{
		ray->end.y = (int)player.pos.y - 0.0001;
		offset->y = -1;
	}
	else
	{
		ray->end.y = (int)player.pos.y + 1;
		offset->y = 1;
	}
	ray->end.x = (player.pos.y - ray->end.y) * arctan + player.pos.x;
	offset->x = -offset->y * arctan;
}

void	init_ray_v(t_player player, t_ray *ray, t_vectord *offset)
{
	double	ntan;

	ntan = -tan(player.angle);
	ray->angle = player.angle;
	ray->vert = true;
	ray->color = create_trgb(0, 118, 137, 245);
	if (ray->angle == M_PI_2 || ray->angle == M_PI_2 * 3)
	{
		ray->end = (t_vectord){1000000, 1000000};
		*offset = (t_vectord){0, 0};
		return ;
	}
	if (ray->angle > M_PI_2 && ray->angle < M_PI_2 * 3)
	{
		ray->end.x = (int)player.pos.x - 0.0001;
		offset->x = -1;
	}
	else
	{
		ray->end.x = (int)player.pos.x + 1;
		offset->x = 1;
	}
	ray->end.y = (player.pos.x - ray->end.x) * ntan + player.pos.y;
	offset->y = -offset->x * ntan;
}

void	cast_ray(t_ray *ray, t_map map, t_vectord offset)
{
	int	dof;

	dof = 0;
	while (dof < DOF && offset.x)
	{
		if (ray->end.y < 0 || ray->end.y >= map.length
			|| ray->end.x < 0
			|| ray->end.x >= ft_strlen(map.str[(int)ray->end.y]))
			break ;
		if (map.str[(int)ray->end.y][(int)ray->end.x] == '1')
			break ;
		else
		{
			ray->end.x += offset.x;
			ray->end.y += offset.y;
			dof++;
		}
	}
}

t_ray	longer_ray(t_ray ray1, t_ray ray2, t_player player)
{
	ray1.start = player.pos;
	ray2.start = player.pos;
	ray1.len = (calc_hyp(ray1.start, ray1.end));
	ray2.len = (calc_hyp(ray2.start, ray2.end));
	if (ray1.len < ray2.len)
		return (ray1);
	return (ray2);
}

void	cast_rays(t_player player, t_map map, t_ray *rays)
{
	t_ray		ray_vh[2];
	t_vectord	offset_vh[2];
	double		angle;
	int			i;

	i = 0;
	angle = (M_PI / 180) * (FOV / (double)RAYS);
	player.angle -= angle * (RAYS / 2);
	while (i < RAYS)
	{
		player.angle = reset_angle(player.angle);
		init_ray_h(player, &ray_vh[0], &offset_vh[0]);
		init_ray_v(player, &ray_vh[1], &offset_vh[1]);
		cast_ray(&ray_vh[1], map, offset_vh[1]);
		cast_ray(&ray_vh[0], map, offset_vh[0]);
		rays[i] = longer_ray(ray_vh[1], ray_vh[0], player);
		i++;
		player.angle += angle;
	}
}
