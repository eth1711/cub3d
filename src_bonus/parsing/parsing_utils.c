/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:55:32 by etlim             #+#    #+#             */
/*   Updated: 2024/12/10 22:24:21 by amaligno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

// void *ft_realloc(char **str, size_t old_size, size_t new_size)
// {
// 	char **new_str;

// 	if (new_size == 0)
// 	{
// 		free(str);
// 		return (NULL);
// 	}
// 	if (str == NULL)
// 	{
// 		str = (char **)ft_calloc(sizeof(char *), new_size);
// 		return (str);
// 	}
// 	new_str = (char **)ft_calloc(sizeof(char *), new_size);
// 	if (new_str == NULL)
// 		return (NULL);
// 	ft_memcpy(new_str, str,sizeof(char *) * old_size);
// 	free(str);
// 	return(new_str);
// }

void	free_2d(char **arr)
{
	while (arr)
		free(*arr++);
}

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

void	exit_error(char *str)
{
	ft_putstr_fd(str, 2);
	exit(1);
}

// static int	joinlen(char *s1, char *s2)
// {
// 	int	l;

// 	l = ft_strlen(s1) + ft_strlen(s2);
// 	return (l);
// }
