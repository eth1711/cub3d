/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:03:01 by etlim             #+#    #+#             */
/*   Updated: 2024/12/13 14:16:26 by amaligno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

char	*ft_strdup2(char *src)
{
	int		i;
	char	*dest;

	dest = (char *)malloc(ft_strlen(src) * sizeof(char) + 1);
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

int	is_empty_str(char *str)
{
	while (*str && ft_strchr("\t\n ", *str))
		str++;
	if (*str)
		return (0);
	return (1);
}

char	*str_check(int fd, t_paths *nsewfc)
{
	t_parsing	parse;

	parse.textures = (bool[6]){0, 0, 0, 0, 0, 0};
	parse.checks = (char *[6]){"NO", "SO", "WE", "EA", "F", "C"};
	parse.count = 0;
	parse.line = get_next_line(fd);
	while (parse.line != NULL && parse.count < 6)
	{
		if (!is_empty_str(parse.line))
			parse.count = check_texture_rgb(&parse, nsewfc);
		free(parse.line);
		parse.line = get_next_line(fd);
	}
	if (parse.count != 6)
		exit_error("Missing texture or RGB config!");
	return (parse.line);
}

char	*str_alloc(int fd, char *line)
{
	char	*str;
	char	*str2;

	str = NULL;
	str2 = NULL;
	while (line[0] == '\n')
	{
		free(line);
		line = get_next_line(fd);
	}
	str = ft_strdup2(line);
	free(line);
	line = get_next_line(fd);
	while (line)
	{
		if (is_empty_str(line))
			exit_error("Map contains empty line\n");
		str2 = str;
		str = ft_strjoin(str, line);
		free(line);
		free(str2);
		line = get_next_line(fd);
	}
	close(fd);
	return (str);
}

char	**parser(char *map, t_paths *nsewfc)
{
	char	*str;
	char	**str2;
	int		i;
	int		fd;

	i = 0;
	fd = open(map, O_RDONLY);
	if (fd < 0)
		exit_error("Couldn't open map!\n");
	str = str_alloc(fd, str_check(fd, nsewfc));
	str2 = ft_split(str, '\n');
	check_map(str2);
	while (str2[i])
		free(str2[i++]);
	free(str2);
	str2 = ft_split(str, '\n');
	free(str);
	return (str2);
}
