/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 15:13:00 by amaligno          #+#    #+#             */
/*   Updated: 2024/10/21 21:04:57 by amaligno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_handler(t_player *player)
{
	int	sign;
	if (player->m_up || player->m_down)
	{
		sign = 1;
		if (player->m_down)
			sign = -1;
		player->pos.y += round(player->delta.y) * sign;
		player->pos.x += round(player->delta.x) * sign;
	}
	if (player->l_right || player->l_left)
	{
		if (player->l_right)
			player->angle += PLAYER_LOOK;
		else
			player->angle -= PLAYER_LOOK;
		if (player->angle > M_PI * 2)
			player->angle -= M_PI * 2;
		else if ((player->angle < 0))
			player->angle += M_PI * 2;
		player->delta.x = cos(player->angle) * PLAYER_SPEED;
		player->delta.y = sin(player->angle) * PLAYER_SPEED;
	}
	printf("Player angle: %lf\n", player->angle);
	printf("Player pos: (%i, %i)\n", player->pos.x, player->pos.y);
}

int	loop(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	move_handler(&data->player);
	draw_background(&data->image);
	draw_map(&data->image, data->map);
	draw_player(&data->image, &data->player);
	mlx_put_image_to_window(data->mlx, data->window, data->image.image, 0, 0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	(void)argc;
	(void)argv;
	init(&data);
	data.map.map = (char *[]){"1111111\n",
		"1000001\n",
		"100000111\n",
		"100000101\n",
		"100000111\n",
		"1111111\n",
		NULL
	};
	mlx_loop(data.mlx);
}
