/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angle_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 16:02:55 by amaligno          #+#    #+#             */
/*   Updated: 2024/11/22 19:08:34 by amaligno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	reset_angle(double angle)
{
	if (angle < 0)
		angle += M_PI * 2;
	if (angle > M_PI * 2)
		angle -= M_PI * 2;
	return (angle);
}

double	deg_to_rad(double degrees)
{
	return ((M_PI / 180.0f) * degrees);
}
