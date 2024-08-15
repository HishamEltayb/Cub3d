/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heltayb <heltayb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 12:45:15 by heltayb           #+#    #+#             */
/*   Updated: 2024/08/04 12:35:56 by heltayb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	free_fn(char **ptr)
{
	if (*ptr)
		free(*ptr);
	*ptr = NULL;
}

void	line_extract(char **join, char **remain,
	char **buffer, ssize_t *letters)
{
	char	*temp;

	temp = NULL;
	if (*remain)
	{
		*join = ft_strdup(*remain);
		free_fn(remain);
	}
	if (*letters > 0)
	{
		if (!*join)
			*join = ft_strdup(*buffer);
		else if (*join)
		{
			temp = ft_strdup(*join);
			free_fn(join);
			*join = ft_strjoin(temp, *buffer);
			free_fn(&temp);
		}
	}
}

char	*return_new_line(char **join, char **remain)
{
	char	*new_line;
	char	*temp;

	new_line = NULL;
	temp = NULL;
	if (*join)
		new_line = ft_strchr(*join, '\n');
	if (new_line)
	{
		*(new_line) = '\0';
		temp = ft_strdup(*join);
		free_fn(join);
		*join = ft_strdup(temp);
		free_fn(&temp);
		return (*join);
	}
	return (free_fn(remain), *join);
}

char	*get_next_line(int fd)
{
	static char	*remain;
	ssize_t		letters;
	char		*buffer;
	char		*join;

	join = NULL;
	letters = 1;
	if (fd < 0 || BUFFER_SIZE < 0 || BUFFER_SIZE >= INT_MAX)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (letters > 0)
	{
		letters = read(fd, buffer, BUFFER_SIZE);
		if ((letters < 0))
			return (free_fn(&join), free_fn(&buffer), free_fn(&remain), NULL);
		buffer[letters] = '\0';
		line_extract(&join, &remain, &buffer, &letters);
		if (letters == 0 || ft_strchr(join, '\n'))
			break ;
	}
	free_fn(&buffer);
	return (return_new_line(&join, &remain));
}
