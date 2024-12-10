/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 16:08:21 by amaligno          #+#    #+#             */
/*   Updated: 2024/12/10 17:55:32 by amaligno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	on_destroy(void *param)
{
	(void)param;
	exit(0);
}

int	on_key_down(int key, void *param)
{
	t_data	*data;

	data = (t_data *)param;
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
	else if (key == KEY_E)
		data->player.use = !data->player.use;
	else if (key == KEY_M)
		data->player.map = !data->player.map;
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

int	on_mouse_move(int x, int y, void *param)
{
	static int	prev_x = WIN_HEIGHT / 2;
	t_data		*data;

	(void)y;
	data = (t_data *)param;
	if (prev_x < x)
		data->player.angle += 0.01;
	else if (prev_x > x)
		data->player.angle -= 0.01;
	else
		return (0);
	data->player.angle = reset_angle(data->player.angle);
	prev_x = x;
	mlx_mouse_move(data->mlx, data->window, WIN_HEIGHT / 2, WIN_WIDTH / 2);
	return (0);
}
