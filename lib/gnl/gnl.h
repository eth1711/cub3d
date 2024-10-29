/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaligno <amaligno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 22:05:57 by amaligno          #+#    #+#             */
/*   Updated: 2024/10/29 22:12:08 by amaligno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef gnl_H
# define gnl_H

# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stdbool.h>
# include <stdlib.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*ft_strjoin(char *s1, char *s2);
char	*to_send(char *str);

void	*ft_memcpy(void *dst, void *src, size_t n);

size_t	length(char *str);
int		strcheck(char *s);

#endif