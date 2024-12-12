/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlim <etlim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:03:01 by etlim             #+#    #+#             */
/*   Updated: 2024/12/12 17:37:33 by etlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	len(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strdup2(char *src)
{
	int		i;
	char	*dest;

	dest = (char *)malloc(len(src) * sizeof(char) + 1);
	if (!(dest))
	{
		return (NULL);
	}
	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void str_check(int fd, t_textures *nsewfc)
{
	t_parsing parse;
	
	parse.textures = (bool[6]){0, 0, 0, 0, 0, 0};
	parse.checks = (char*[6]){"NO ", "SO ", "WE ", "EA ", "F ", "C "};
	parse.count = 0;
	parse.line = get_next_line(fd);
	while (parse.line != NULL)
	{
		parse.count = check_texture_rgb(&parse, nsewfc);
		if (parse.count == 6)
		{
			parse.cur_check = -1;
			while (++parse.cur_check < 6)
				if (!parse.textures[parse.cur_check])
					exit_error("Error: Missing texture or RGB config!");
			free(parse.line);
			return ;
		}
		printf("line: %s\n", parse.line);
		free(parse.line);
		parse.line = get_next_line(fd);
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

char **parser(char *map, t_textures *nsewfc)
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
	str_check(fd, nsewfc);
	str = str_alloc(fd);
	str2 = ft_split(str, '\n');
	free(str);
	
	while(str2[i])
	{
		printf("%s", str2[i]);
		printf("\n");
		free(str2[i]);
		i++;
	}
	free(str2);
	return(str2);
}
