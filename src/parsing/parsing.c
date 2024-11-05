/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlim <etlim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:03:01 by etlim             #+#    #+#             */
/*   Updated: 2024/11/05 17:30:21 by etlim            ###   ########.fr       */
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

void set_texture_rgb(char *line, char **checks, bool *textures, int count)
{
	int cur_check;

	cur_check = 0;
	while (cur_check++ < 6)
	{
		if (ft_strncmp(line, checks[cur_check], ft_strlen(checks[cur_check])) && !textures[cur_check])
		{
			line = line + ft_strlen(checks[cur_check]);
			if (cur_check < 4 && open(line, O_RDONLY) > 0)
			{
				textures[cur_check] = 1;
				count++;
			}
			else if(cur_check >= 4 && !check_rgb(line))
			{
				textures[cur_check] = 1;
				count++;
			}
		}
		else if (textures[cur_check])
			exit_error("Duplicate found!");
	}		
}

void check_textures(char *map, int fd)
{
	int		cur_check;
	int 	count;
	bool	*textures;
	char	**checks;
	char	*line;

	textures = (bool[6]){0, 0, 0, 0, 0, 0};
	checks = (char*[6]){"NO ", "SO ", "WE ", "EA ", "F ", "C "};
	count = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		set_texture_rgb(line, &checks, &textures, &count);
		if (count == 6)
		{
			cur_check = 0;
			while (cur_check++ < 6)
				if (!textures[cur_check])
					exit_error("Error: Missing texture or RGB config!");
			free(line);
			break ;
		}
		free(line);
	}
}
	

char **str_alloc(char *map, int *lw, int fd)
{
	char	**str;
	char	*line;
	
	line = get_next_line(fd);
	while (line)
	{
		str = ft_calloc(sizeof(char *), (*lw + 1));
		str[*lw] = line;
		free(line);
		line = get_next_line(fd);
		*lw += 1;
	}
	str = ft_calloc(sizeof(char *), (*lw + 1));
	str[*lw] = NULL;
	
	
}

int parser(char *map)
{
	char	**str;
	char	*line;
	int		lw;
	int		fd;

	fd = open(map, O_RDONLY);
	if (fd < 0)
		return (NULL);
	check_textures(map, fd);
	str = str_alloc(map, &lw, fd);
}