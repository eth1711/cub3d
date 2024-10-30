/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlim <etlim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:03:01 by etlim             #+#    #+#             */
/*   Updated: 2024/10/30 19:03:34 by etlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void check_textures(char *map)
{
	int cur_check;
	bool *textures;
	char **checks;

	cur_check = 0;
	textures = (bool[6]){0, 0, 0, 0, 0, 0};
	checks = (char*[6]){"NO ", "SO ", "WE ", "EA ", "F ", "C "};
	if(strncmp())
		
	
	
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