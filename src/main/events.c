/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 16:08:21 by amaligno          #+#    #+#             */
/*   Updated: 2024/10/15 22:04:53 by amaligno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	on_destroy(void *param)
{
	(void)param;
	exit(0);
}

int	on_key_down(int key, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	// printf("key pressed: %i\n", key);
	if (key == KEY_W)
		data->player.m_up = true;
	if (key == KEY_S)
		data->player.m_down = true;
	if (key == KEY_A)
		data->player.m_left = true;
	if (key == KEY_D)
		data->player.m_right = true;
	if (key == KEY_ESC)
		exit(0);
	return (0);
}

int	on_key_up(int key, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (key == KEY_W)
		data->player.m_up = false;
	if (key == KEY_S)
		data->player.m_down = false;
	if (key == KEY_A)
		data->player.m_left = false;
	if (key == KEY_D)
		data->player.m_right = false;
	return (0);
}
