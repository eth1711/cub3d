/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlim <etlim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:03:01 by etlim             #+#    #+#             */
/*   Updated: 2024/10/31 19:09:38 by etlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void check_textures(char *map)
{
	int		fd;
	int		cur_check;
	bool	*textures;
	char	**checks;
	char	*line;
	char	*path;

	cur_check = 0;
	textures = (bool[6]){0, 0, 0, 0, 0, 0};
	checks = (char*[6]){"NO ", "SO ", "WE ", "EA ", "F ", "C "};
	fd = open(map, O_RDONLY);
	if (fd < 0)
		return (NULL);
	line = get_next_line(fd);
	while (line)
	{
		if (ft_strncmp(line, checks[cur_check], 3) && !textures[cur_check])
			path = line + 3;
			if (open(path, O_RDONLY) > 0 && cur_check < 4)
			{
				textures[cur_check] = 1;
			}
			if (cur_check >= 4 && path)//needa think of how to check rgb elements
			{
				textures[cur_check] = 1;
			}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}
char **str_alloc(char *map, int *lw)
{
	char	**str;
	char	*line;
	int		fd;
	int		i;
	
	fd = open(map, O_RDONLY);
	if (fd < 0)
		return (NULL);
	line = get_next_line(fd);
}

int parser(char *map)
{
	char	**str;
	int		*lw;

	check_textures(map);
	str = str_alloc(map, &lw);
	
	
}