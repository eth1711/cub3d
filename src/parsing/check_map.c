/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:46:23 by amaligno          #+#    #+#             */
/*   Updated: 2024/12/12 14:51:43 by amaligno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	check_char(char **map, int x, int y, bool *start)
{
	if (!y || !x
		|| ft_strchr(" ", map[y][x - 1])
		|| ft_strchr(" ", map[y][x + 1])
		|| ft_strlen(map[y + 1]) <= (size_t)x
		|| ft_strlen(map[y - 1]) <= (size_t)x)
	{
		exit_error("Map not closed\n");
	}
	if (ft_strchr("NSWE", map[y][x]))
	{
		if (*start)
			exit_error("Duplicate start position\n");
		*start = true;
	}
}

void	check_map(char **map)
{
	int		x;
	int		y;
	bool	start;

	y = 0;
	start = false;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (ft_strchr("NWSE0", map[y][x]))
				check_char(map, x, y, &start);
			else if (!ft_strchr("1F ", map[y][x]))
				exit_error("Invalid char\n");
			x++;
		}
		y++;
	}
	if (!start)
		exit_error("Missing player start\n");
}
