/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 19:01:34 by amaligno          #+#    #+#             */
/*   Updated: 2024/11/04 19:11:35 by amaligno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	calc_hyp(t_vectord side1, t_vectord side2)
{
	return (sqrt((pow(side1.x - side2.x, 2)) + (pow(side1.y - side2.y, 2))));
}
