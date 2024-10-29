/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlim <etlim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:03:01 by etlim             #+#    #+#             */
/*   Updated: 2024/10/29 21:30:39 by etlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char **str_alloc(char *map, int *lw)
{
	char	**str;
	char	*line;
	int		fd;
	int		i;
	
	fd = open(map, O_RDONLY);
	
	
}

int parser(char *map)
{
	char	**str;
	int		*lw;

	lw = 0;
	str = str_alloc(map, &lw);
	
	
}