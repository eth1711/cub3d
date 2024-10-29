/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlim <etlim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:03:01 by etlim             #+#    #+#             */
/*   Updated: 2024/10/29 22:13:12 by etlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char *split_map(char *map)
{
	
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

	split_map();
	str = str_alloc(map, &lw);
	
	
}