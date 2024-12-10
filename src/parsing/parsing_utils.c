/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:55:32 by etlim             #+#    #+#             */
/*   Updated: 2024/12/10 18:56:55 by amaligno         ###   ########.fr       */
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

static int	joinlen(char *s1, char *s2)
{
	int	l;

	l = ft_strlen(s1) + ft_strlen(s2);
	return (l);
}

char	*joinstr(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*dest;

	if (!(s1) || !(s2))
		return (NULL);
	dest = (char *)malloc((joinlen(s1, s2)) * (sizeof(char)) + 1);
	if (!(dest))
		return (NULL);
	i = 0;
	j = 0;
	while (s1[j] != '\0')
		dest[i++] = s1[j++];
	// dest[i++] = '\n';
	j = 0;
	while (s2[j] != '\0')
		dest[i++] = s2[j++];
	dest[i] = '\0';
	free(s1);
	return (dest);
}