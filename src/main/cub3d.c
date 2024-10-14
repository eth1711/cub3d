/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 15:13:00 by amaligno          #+#    #+#             */
/*   Updated: 2024/10/14 18:45:11 by amaligno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_handler(t_player *player)
{
	if (player->m_up && player->pos.y - 10 >= 0)
		player->pos.y -= 10;
	if (player->m_down && player->pos.y + 10 <= WIN_HEIGHT)
		player->pos.y += 10;
	if (player->m_left && player->pos.x - 10 >= 0)
		player->pos.x -= 10;
	if (player->m_right && player->pos.x + 10 <= WIN_WIDTH)
		player->pos.x += 10;
}

void	init(t_data *data)
{
	data->mlx = mlx_init();
	data->window = mlx_new_window(data->mlx, WIN_WIDTH, WIN_HEIGHT, "cub3d");
	data->image.image = mlx_new_image(data->mlx, WIN_WIDTH, WIN_HEIGHT);
	data->image.addr = mlx_get_data_addr(data->image.image, &data->image.bpp,
			&data->image.line_len, &data->image.endian);
	data->map.map = " \
				1111111\n \
				1000001\n \
				100N001\n \
				1111111\n \
				";
	data->map.width = 7;
	data->map.height = 4;
	data->player.pos.x = 0;
	data->player.pos.y = 0;
	mlx_hook(data->window, ON_DESTROY, 0, on_destroy, NULL);
}

// void	draw_player(t_data *data)
// {
// }

void	draw_background(t_image *image)
{
	t_rect	background;

	background.pos.x = 0;
	background.pos.y = 0;
	background.size.y = WIN_HEIGHT;
	background.size.x = WIN_WIDTH;
	background.color = create_trgb(255, 136, 186, 71);
	draw_rectangle(image, background);
}

int	loop(void *param)
{
	t_data	*data;
	// static int	frames;

	data = (t_data *)param;
	move_handler(&data->player);
	draw_background(&data->image);
	draw_rectangle(&data->image, (t_rect){
		(t_vector){100, 100},
		(t_vector){data->player.pos.x, data->player.pos.y},
		create_trgb(0, 255, 223, 18)
	});
	mlx_put_image_to_window(data->mlx, data->window, data->image.image, 0, 0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	(void)argc;
	(void)argv;
	init(&data);
	mlx_hook(data.window, ON_KEY_DOWN, (1L), on_key_down, (void *)&data);
	mlx_key_hook(data.window, on_key_up, (void *)&data);
	mlx_loop_hook(data.mlx, loop, (void *)&data);
	mlx_loop(data.mlx);
}
