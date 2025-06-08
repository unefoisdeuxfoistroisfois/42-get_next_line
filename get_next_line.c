/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: britela- <britela-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 18:50:57 by britela-          #+#    #+#             */
/*   Updated: 2025/06/08 12:18:16 by britela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_free(char *str)
{
	if (str != NULL)
	{
		free(str);
	}
}

char	*ft_reste(char *str)
{
	int		i;
	int		j;
	char	*rest;

	i = 0;
	j = 0;
	if (str == NULL)
		return (NULL);
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (str[i] == '\0')
	{
		ft_free(str);
		return (NULL);
	}
	i++;
	rest = malloc(ft_strlen(str) - i + 1);
	if (rest == NULL)
		return (NULL);
	while (str[i] != '\0')
		rest[j++] = str[i++];
	rest[j] = '\0';
	ft_free(str);
	return (rest);
}

char	*ft_verif_mot(char *str)
{
	int		i;
	char	*newword;

	i = 0;
	if (str == NULL)
		return (NULL);
	while (str[i] != '\0' && str[i] != '\n')
	{
		i++;
	}
	if (str[i] == '\n')
	{
		i++;
	}
	newword = ft_substr(str, 0, i);
	return (newword);
}

char	*get_next_line(int fd)
{
	ssize_t		i;
	char		*word;
	char		*line;
	char		*position;
	static char	*conc;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	word = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (word == NULL)
		return (NULL);
	position = ft_strchr(conc, '\n');
	while (position == NULL && i > 0)
	{
		i = read(fd, word, BUFFER_SIZE);
		if (i < 0)
		{
			ft_free(word);
			return (NULL);
		}
		word[i] = '\0';
		conc = ft_strjoin(conc, word);
	}
	ft_free(word);
	if (conc == NULL || conc[0] == '\0')
	{
		ft_free(conc);
		return (NULL);
	}
	line = ft_verif_mot(conc);
	conc = ft_reste(conc);
	return (line);
}
