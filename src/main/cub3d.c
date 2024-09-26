/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 15:13:00 by amaligno          #+#    #+#             */
/*   Updated: 2024/09/26 18:58:07 by amaligno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

int	on_destroy(void *param)
{
	(void)param;
	exit(0);
}

void	init(t_data *data)
{
	data->player.x = 300;
	data->player.y = 300;
	data->mlx = mlx_init();
	data->window = mlx_new_window(data->mlx, WIN_WIDTH, WIN_HEIGHT, "cub3d");
	mlx_hook(data->window, ON_DESTROY, 0, on_destroy, NULL);

}

void	loop(void *param)
{
	t_data	*data;

	data = (t_data *)param;
}

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	t_data	data;
	
	init(&data);
	mlx_loop_hook(data.mlx, (void *)&data, loop);
	mlx_loop(data.mlx);
}
