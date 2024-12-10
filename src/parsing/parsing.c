/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlim <etlim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:03:01 by etlim             #+#    #+#             */
/*   Updated: 2024/12/10 23:32:23 by etlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int check_rgb(char *line)
{
	int r;
	int g;
	int b;
	int cur;
	int *values;
	
	values = (int[3]){-1, -1, -1};
	cur = 0;

	while (*line && cur < 3)
	{
		values[cur++] = ft_atoi(line);
		while (*line && *line != ',')
			line++;
		if (*line == ',')
			line++;
	}
	r = values[0];
	g = values[1];
	b = values[2];
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255 )
		return -1;
	return 0;
}

int set_texture_rgb(char *line, char **checks, bool *textures, int count)
{
	int cur_check;
	char *str = NULL;
	
	cur_check = 0;
	while (cur_check < 6)
	{
		if (!ft_strncmp(line, checks[cur_check], ft_strlen(checks[cur_check])))
		{
			line = line + ft_strlen(checks[cur_check]);
			if (!textures[cur_check])
			{
				str = ft_strdup(line);
				if (textures[cur_check] == 1)
					return (-1);
				if ((cur_check < 4 && ((open(str, O_RDONLY)) > 0)) ||
					((cur_check >= 4) && !check_rgb(line)))
				{
					textures[cur_check] = 1;
					count++;
					free(str);
					return count;
				}
			}
		}
		cur_check++;
	}
	free(str);
	return (-1);
}

void check_textures(int fd)
{
	int 	count;
	int		cur_check;
	bool	*textures;
	char	*line;
	char	**checks;

	textures = (bool[6]){0, 0, 0, 0, 0, 0};
	checks = (char*[6]){"NO ", "SO ", "WE ", "EA ", "F ", "C "};
	count = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		count = set_texture_rgb(line, checks, textures, count);
		if (count == 6)
		{
			cur_check = -1;
			while (++cur_check < 6)
				if (!textures[cur_check])
					exit_error("Error: Missing texture or RGB config!");
			free(line);
			return ;
		}
		free(line);
	}
}
	

char *str_alloc(int fd)
{
	char	*str;
	char	*str2;
	char	*line;
	
	str = NULL;
	str2 = NULL;
	line = get_next_line(fd);
	while(line[0] == '\n')
	{
		free(line);	
		line = get_next_line(fd);
	}
	str = ft_strdup2(line);
	free(line);
	line = get_next_line(fd);
	while (line)
	{
		str2 = str;
		str = ft_strjoin(str, line);
		free(line);
		free(str2);
		line = get_next_line(fd);
	}
	close(fd);
	return (str);
}

char **parser(char *map)
{
	char	*str;
	char	**str2;
	// int		lw;
	int		fd;
	int		i;
	int		j;
	
	i = 0;
	j = 0;
	fd = open(map, O_RDONLY);
	if (fd < 0)
		exit_error("Couldn't open map!\n");
	check_textures(fd);
	str = str_alloc(fd);
	str2 = ft_split(str, 12);
	free(str);
	// while(str2[i])
	// {
	// 	j = 0;
	// 	while(str2[i][j])
	// 	{
	// 		printf("%c", str2[i][j]);
	// 		j++;
	// 	}
	// 	printf("\n");
	// 	free(str2[i]);
	// 	i++;
	// }
	return(str2);
}