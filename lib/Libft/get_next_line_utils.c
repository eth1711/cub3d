/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 17:14:27 by amaligno          #+#    #+#             */
/*   Updated: 2023/05/08 16:06:59 by amaligno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	size_t		i;
	size_t		len;
	char		*str;

	i = 0;
	len = (length(s1) + length(s2));
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (*s2)
	{
		str[i] = *s2;
		i++;
		s2++;
	}
	str[i] = '\0';
	return (str);
}

int	strcheck(char *s)
{
	int	count;
	int	len;

	count = -1;
	len = length(s) + 1;
	while (++count < len)
	{
		if (s[count] == '\n')
			return (1);
	}
	return (0);
}

size_t	length(char *str)
{
	int		num;

	num = 0;
	while (str[num])
		num++;
	return (num);
}

char	*to_send(char *str)
{
	int		index;
	char	*nl;

	index = 0;
	while (str[index] != '\n' && str[index] != '\0')
		index++;
	nl = malloc(sizeof(char) * (index + 2));
	nl[index + 1] = '\0';
	if (!nl)
		return (NULL);
	index = 0;
	while (str[index] != '\n' && str[index] != '\0')
	{
		nl[index] = str[index];
		index++;
	}
	if (str[index] && str[index == '\n'])
	{
		nl[index] = str[index];
		return (nl);
	}
	nl[index] = '\0';
	return (nl);
}
