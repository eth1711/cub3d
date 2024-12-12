/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:55:32 by etlim             #+#    #+#             */
/*   Updated: 2024/12/12 23:14:28 by amaligno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_texture_rgb(t_parsing *parse, t_paths *nsewfc, char *str)
{
	if (parse->cur_check == NO)
		nsewfc->north = str;
	else if (parse->cur_check == SO)
		nsewfc->south = str;
	else if (parse->cur_check == WE)
		nsewfc->west = str;
	else if (parse->cur_check == EA)
		nsewfc->east = str;
	else
		free(str);
}

void	get_rgb(char *line, int *r, int *g, int *b)
{
	int	cur;
	int	*values;

	values = (int [3]){-1, -1, -1};
	cur = -1;
	while (*line && ++cur < 3)
	{
		if (ft_isdigit(*line))
			values[cur] = ft_atoi(line);
		else
			exit_error("RGB value incorrect\n");
		while (*line && ft_isdigit(*line))
			line++;
		if (*line != '\n' && *line != ',' && !ft_isdigit(*line))
			exit_error("RGB value incorrect\n");
		line++;
	}
	*r = values[0];
	*g = values[1];
	*b = values[2];
}

int	check_rgb(t_parsing *parse, t_paths *nsewfc)
{
	int	r;
	int	g;
	int	b;

	get_rgb(parse->tmp, &r, &g, &b);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		return (-1);
	if (parse->cur_check == F)
		nsewfc->floor = create_trgb(0, r, g, b);
	else if (parse->cur_check == C)
		nsewfc->ceiling = create_trgb(0, r, g, b);
	return (0);
}

int	check_texture_rgb2(t_parsing *parse, t_paths *nsewfc)
{
	char	*str;

	if (!parse->textures[parse->cur_check])
	{
		str = ft_strdup(parse->tmp);
		if ((parse->cur_check < 4 && ((open(str, O_RDONLY)) > 0))
			|| ((parse->cur_check >= 4) && !check_rgb(parse, nsewfc)))
		{
			set_texture_rgb(parse, nsewfc, str);
			parse->textures[parse->cur_check] = 1;
			parse->count++;
			return (parse->count);
		}
		free(str);
	}
	return (-1);
}

int	check_texture_rgb(t_parsing *parse, t_paths *nsewfc)
{
	parse->cur_check = 0;
	while (parse->cur_check < 6)
	{
		if (!ft_strncmp(parse->line, parse->checks[parse->cur_check],
				ft_strlen(parse->checks[parse->cur_check])))
		{
			parse->tmp = parse->line
				+ ft_strlen(parse->checks[parse->cur_check]);
			while (*parse->tmp && *parse->tmp == ' ')
				parse->tmp++;
			parse->count = check_texture_rgb2(parse, nsewfc);
			return (parse->count);
		}
		parse->cur_check++;
	}
	return (-1);
}
