/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 16:08:21 by amaligno          #+#    #+#             */
/*   Updated: 2024/10/21 19:55:13 by amaligno         ###   ########.fr       */
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
	else if (key == KEY_S)
		data->player.m_down = true;
	else if (key == KEY_A)
		data->player.m_left = true;
	else if (key == KEY_D)
		data->player.m_right = true;
	else if (key == KEY_LEFT)
		data->player.l_left = true;
	else if (key == KEY_RIGHT)
		data->player.l_right = true;
	else if (key == KEY_ESC)
		exit(0);
	return (0);
}

int	on_key_up(int key, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (key == KEY_W)
		data->player.m_up = false;
	else if (key == KEY_S)
		data->player.m_down = false;
	else if (key == KEY_A)
		data->player.m_left = false;
	else if (key == KEY_D)
		data->player.m_right = false;
	else if (key == KEY_LEFT)
		data->player.l_left = false;
	else if (key == KEY_RIGHT)
		data->player.l_right = false;
	return (0);
}
