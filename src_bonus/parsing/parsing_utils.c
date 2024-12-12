/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:55:32 by etlim             #+#    #+#             */
/*   Updated: 2024/12/12 19:34:57 by amaligno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

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

static int	joinlen(char *s1, char *s2)
{
	int	l;

	l = len(s1) + len(s2);
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
	j = 0;
	while (s2[j] != '\0')
		dest[i++] = s2[j++];
	dest[i] = '\0';
	free(s1);
	return (dest);
}
