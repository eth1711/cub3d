/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:46:23 by amaligno          #+#    #+#             */
/*   Updated: 2024/12/13 01:14:11 by amaligno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	check_char(char **map, t_vectori pos, t_vectori *start, int *count)
{
	if (map[pos.y][pos.x] == '0'
		&& (!pos.y || !pos.x || !map[pos.y + 1]
		|| ft_strchr(" ", map[pos.y][pos.x - 1])
		|| ft_strchr(" ", map[pos.y][pos.x + 1])
		|| ft_strlen(map[pos.y + 1]) <= (size_t)pos.x
		|| ft_strlen(map[pos.y - 1]) <= (size_t)pos.x))
	{
		exit_error("Map not closed\n");
	}
	if (ft_strchr("NSWE", map[pos.y][pos.x]))
	{
		if (start->x >= 0)
			exit_error("Duplicate start position\n");
		*start = (t_vectori){pos.x, pos.y};
	}
	if (ft_strchr("NSWE01", map[pos.y][pos.x]))
		(*count)++;
}

static void	floodfill(char **map, t_vectori pos, int *count)
{
	char	c;

	c = map[pos.y][pos.x];
	map[pos.y][pos.x] = 'F';
	(*count)++;
	if (pos.x && c && !ft_strchr(" F", map[pos.y][pos.x - 1]))
		floodfill(map, (t_vectori){pos.x - 1, pos.y}, count);
	if (map[pos.y][pos.x + 1] && c && !ft_strchr(" F", map[pos.y][pos.x + 1]))
		floodfill(map, (t_vectori){pos.x + 1, pos.y}, count);
	if (pos.y && c && ft_strlen(map[pos.y - 1]) > (size_t)pos.x
		&& !ft_strchr(" F", map[pos.y - 1][pos.x]))
		floodfill(map, (t_vectori){pos.x, pos.y - 1}, count);
	if (map[pos.y + 1] && c && pos.y && c
		&& ft_strlen(map[pos.y + 1]) > (size_t)pos.x
		&& !ft_strchr(" F", map[pos.y + 1][pos.x]))
		floodfill(map, (t_vectori){pos.x, pos.y + 1}, count);
}

void	check_map(char **map)
{
	int			count;
	int			fill;
	t_vectori	start;
	t_vectori	pos;

	pos.y = -1;
	count = 0;
	fill = 0;
	start = (t_vectori){-1, -1};
	while (map[++pos.y])
	{
		pos.x = -1;
		while (map[pos.y][++pos.x])
		{
			if (ft_strchr("NWSE01", map[pos.y][pos.x]))
				check_char(map, pos, &start, &count);
			else if (!ft_strchr("1 ", map[pos.y][pos.x]))
				exit_error("Invalid char\n");
		}
	}
	if (start.x < 0)
		exit_error("Missing player start\n");
	floodfill(map, start, &fill);
	if (fill != count)
		exit_error("Map contains island\n");
}
