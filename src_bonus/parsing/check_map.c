/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:46:23 by amaligno          #+#    #+#             */
/*   Updated: 2024/12/11 18:44:30 by amaligno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	count_spaces(char **map, t_vectori *start)
{
	int	x;
	int	y;
	int	spaces;

	y = 0;
	spaces = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (!ft_strchr("NWSE0", map[y][x]))
				spaces++;
			else if (ft_strchr("NSWE", map[y][x]))
			{
				start->x = x;
				start->y = y;
			}
			else if (!ft_strchr("1F ", map[y][x]))
				exit_error("Error\nInvalid char");
			x++;
		}
		y++;
	}
	return (spaces);
}

void	check_char(char **map, t_vectori pos, int *count)
{
	map[pos.y][pos.x] = 'F';
	(*count)++;
	if (!pos.y || !pos.x || !map[pos.y + 1] || !map[pos.y][pos.x + 1]
		|| ft_strlen(map[pos.y + 1]) <= (size_t)pos.x
		|| ft_strlen(map[pos.y - 1]) <= (size_t)pos.x)
	{
		exit_error("Error\nMap not closed\n");
	}
}

void	floodfill(char **map, t_vectori pos, int *count)
{
	char	c;

	c = map[pos.y][pos.x];
	check_char(map, pos, count);
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

	start.x = -1;
	start.y = -1;
	count = 0;
	spaces = count_spaces(map, &start);
	if (start.x < 0 && start.y < 0)
		exit_error("Error\nMissing Player start");
	floodfill(map, start, &count);
	if (count != spaces)
		exit_error("Error\nInvalid map\n");
}
