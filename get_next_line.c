/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: britela- <britela-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 18:50:57 by britela-          #+#    #+#             */
/*   Updated: 2025/05/31 00:02:40 by bradley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_verif_mot(char *str)
{
	int	i;
	char	*newword;

	i = 0;
	while(str[i] != '\0' && str[i] != '\n')
	{
		i++;
	}
	if (str[i] != '\n')
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
	static	char *conc;

	conc = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		return (NULL);
	}

	word = malloc(sizeof(char) *BUFFER_SIZE + 1);
	if (word == NULL)
	{
		return (NULL);
	}
	//je lis de mon fd a mon word et le nombre que je veux lire
	while ((i = read(fd, word, BUFFER_SIZE)) > 0)
	{
		word[i + 1] = '\0';
		conc = ft_strjoin(conc, word); 
	}
	free(word);
	return (conc);
}
