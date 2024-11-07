/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlim <etlim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:55:32 by etlim             #+#    #+#             */
/*   Updated: 2024/11/07 19:42:08 by etlim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void *ft_realloc(char **str, size_t old_size, size_t new_size)
{
	char **new_str;

	if (new_size == 0)
	{
		free(str);
		return (NULL);
	}
	if (str == NULL)
	{
		str = (char **)ft_calloc(sizeof(char *), new_size);
		return (str);
	}
	new_str = (char **)ft_calloc(sizeof(char *), new_size);
	if (new_str == NULL)
		return (NULL);
	ft_memcpy(new_str, str,sizeof(char *) * old_size);
	free(str);
	return(new_str);
}