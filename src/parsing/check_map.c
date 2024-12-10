/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 18:19:44 by amaligno          #+#    #+#             */
/*   Updated: 2024/12/10 21:55:27 by amaligno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	count_spaces(char **map, t_vectori *start)
{
	int	x;
	int	y;
	int	spaces;

	y = 0;
	x = 0;
	spaces = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (!ft_strchr("1 ", map[y][x]))
				spaces++;
			if (ft_strchr("NSWE", map[y][x]))
			{
				start->x = x;
				start->y = y;
			}
			x++;
		}
		y++;
	}
	return (spaces);
}

void	check_char(char **map, char c, t_vectori pos, int *count)
{
	if (c && !ft_strchr("1F ", c))
	{
		map[pos.y][pos.x] = 'F';
		(*count)++;
	}
	if (!pos.y || !pos.x || !map[pos.y + 1] || !map[pos.y][pos.x + 1]
		|| (int)ft_strlen(map[pos.y + 1]) <= pos.x
		|| (int)ft_strlen(map[pos.y - 1]) <= pos.x)
	{
		ft_putstr_fd("Error\nmap not closed\n", STDERR_FILENO);
		exit(0);
	}
}

void	floodfill(char **map, t_vectori pos, int *count)
{
	char	c;

	c = map[pos.y][pos.x];
	check_char(map, c, pos, count);
	if (pos.x && c && !ft_strchr("1F", map[pos.y][pos.x - 1]))
		floodfill(map, (t_vectori){pos.x - 1, pos.y}, count);
	if (map[pos.y][pos.x + 1] && c && !ft_strchr("1F", map[pos.y][pos.x + 1]))
		floodfill(map, (t_vectori){pos.x + 1, pos.y}, count);
	if (pos.y && c && !ft_strchr("1F", map[pos.y - 1][pos.x]))
		floodfill(map, (t_vectori){pos.x, pos.y - 1}, count);
	if (map[pos.y + 1] && c && !ft_strchr("1F", map[pos.y + 1][pos.x]))
		floodfill(map, (t_vectori){pos.x, pos.y + 1}, count);
}

void	check_map(char **map)
{
	t_vectori	start;
	int			spaces;
	int			count;

	start.x = 0;
	start.y = 0;
	count = 0;
	spaces = count_spaces(map, &start);
	floodfill(map, start, &count);
	if (count != spaces)
	{
		ft_putstr_fd("Error\nInvalid map\n", STDERR_FILENO);
		exit(0);
	}
}
