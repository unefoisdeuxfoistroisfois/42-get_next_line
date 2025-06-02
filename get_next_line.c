/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: britela- <britela-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 18:50:57 by britela-          #+#    #+#             */
/*   Updated: 2025/06/02 22:46:39 by britela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_reste(char *str)
{
	int	i;
	int	j;
	char	*rest;

	i = 0;
	j = 0;
	if (str == NULL)
		return (NULL);
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (str[i] != '\0') // pas de \n
	{
		free(str);
		return (NULL);
	}
	i++; // sauter le \n
	rest = malloc(ft_strlen(str) - i + 1);
	if (rest == NULL)
		return (NULL);
	while (str[i] != '\0')
		rest[j] = str[i];
		i++;
		j++;
	rest[j] = '\0';
	free(str);
	return (rest);
}

char	*ft_verif_mot(char *str)
{
	int	i;
	char	*newword;

	i = 0;
	if (str == NULL)
		return (NULL);
	while(str[i] != '\0' && str[i] != '\n')
	{
		i++;
	}
	if (str[i] == '\n')
	{
		i++;
	}
	newword = ft_substr(str,0,i);
	return (newword);
}

char	*get_next_line(int fd)
{
	ssize_t	i;// peut contenir un -
	char	*word;
	static	char *conc = NULL;
	char	*line;
	char	*position;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	word = malloc(sizeof(char) *BUFFER_SIZE + 1);
	if (word == NULL)
		return (NULL);
	//je lis de mon fd a mon word et le nombre que je veux lire
	position = ft_strchr(conc, '\n');
	while ((conc == NULL || position == NULL) && (i = read(fd, word, BUFFER_SIZE)) > 0)
	{
		word[i] = '\0';
		conc = ft_strjoin(conc, word); 
	}
	free(word);
	if (conc == NULL || conc[0] == '\0')
	{
		free(conc);
		conc = NULL;
		return (NULL);
	}
	line = ft_verif_mot(conc);
	conc = ft_reste(conc); 
	return (line);
}
