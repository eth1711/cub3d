/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlim <etlim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:03:01 by etlim             #+#    #+#             */
/*   Updated: 2024/11/03 01:45:54 by etlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int check_rgb(char *line)
{
	int *values;
	int cur;
	int r;
	int g;
	int b;
	
	values = (int){-1, -1, -1};
	cur = 0;

	while (*line && cur < 3)
	{
		values[cur++] = ft_atoi(line);
		while (*line && *line != ",")
			line++;
		if (*line == ",")
			line++;
	}
	r = values[0];
	g = values[1];
	b = values[2];
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255 )
		return -1;
	return 0;
}

void check_textures(char *map)
{
	int		fd;
	int		cur_check;
	bool	*textures;
	char	**checks;
	char	*line;

	cur_check = 0;
	textures = (bool[6]){0, 0, 0, 0, 0, 0};
	checks = (char*[6]){"NO ", "SO ", "WE ", "EA ", "F ", "C "};
	fd = open(map, O_RDONLY);
	if (fd < 0)
		return (NULL);
	line = get_next_line(fd);
	while (line)
	{
		if (ft_strncmp(line, checks[cur_check], ft_strlen(checks[cur_check])) && !textures[cur_check])
			line = line + ft_strlen(checks[cur_check]);
			if (open(line, O_RDONLY) > 0 && cur_check < 4)
				textures[cur_check] = 1;
			if (cur_check >= 4 && !check_rgb(line))
				textures[cur_check] = 1;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	cur_check = 0;
	while (cur_check++ < 6)
		if (!textures[cur_check])
			return false;
}
//insert exit function with error code

// char **str_alloc(char *map, int *lw)
// {
// 	char	**str;
// 	char	*line;
// 	int		fd;
// 	int		i;
	
// 	fd = open(map, O_RDONLY);
// 	if (fd < 0)
// 		return (NULL);
// 	line = get_next_line(fd);
// }

int parser(char *map)
{
	char	**str;
	int		*lw;

	check_textures(map);
	str = str_alloc(map, &lw);
	
	
}