/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 17:12:44 by amaligno          #+#    #+#             */
/*   Updated: 2023/05/08 15:54:56 by amaligno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*strtrim(char *tocut, char *line)
{
	int		start;
	int		end;
	int		i;
	char	*new;

	if (!line)
		return (NULL);
	start = 0;
	i = 0;
	end = length(line);
	while ((tocut[start] == line[start]) && tocut[start] && line[start])
		start++;
	new = malloc(sizeof(char) * (end - start + 1));
	new[end - start] = '\0';
	if (!new)
		return (NULL);
	while (start < end)
		new[i++] = line[start++];
	return (new);
}

char	*newstr(char **stash, char *buf, int fd)
{
	char	*temp;

	if (!stash[fd])
	{
		stash[fd] = malloc(sizeof(char) * 1);
		stash[fd][0] = '\0';
	}
	temp = ft_strjoin(stash[fd], buf);
	free(stash[fd]);
	stash[fd] = temp;
	return (stash[fd]);
}

char	*sender(char **stash, char *temp, int fd)
{
	char	*send;

	send = to_send(stash[fd]);
	temp = strtrim(send, stash[fd]);
	free(stash[fd]);
	stash[fd] = temp;
	return (send);
}

char	*get_next_line(int fd)
{
	int			read_value;
	char		buf[BUFFER_SIZE + 1];
	static char	*stash[4096];

	read_value = 1;
	while (read_value)
	{
		read_value = read(fd, buf, BUFFER_SIZE);
		buf[read_value] = '\0';
		if (read_value <= 0 && !stash[fd])
			return (NULL);
		stash[fd] = newstr(stash, buf, fd);
		if (strcheck(stash[fd]) || read_value <= 0)
			break ;
	}
	if (read_value || stash[fd][0])
	{
		return (sender(stash, stash[fd], fd));
	}
	free(stash[fd]);
	stash[fd] = NULL;
	return (NULL);
}

// int	main(void)
// {
// 	static int	fd;
// 	static int	fd2;
// 	int			i;

// 	i = 0;
// 	fd = open("fart.txt", O_RDONLY);
// 	fd2 = open("hello.txt", O_RDONLY);
// 	if (fd == -1)
// 	{
// 		printf("Failed to open & read file.\n");
// 		return (1);
// 	}
// 	while (i++ < 5)
// 	{
// 		printf("main: [%s]\n", get_next_line(fd));
// 		printf("main: [%s]\n", get_next_line(fd + 1));
// 	}
// 	system("leaks a.out");
// }
