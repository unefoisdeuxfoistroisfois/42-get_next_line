/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: britela- <britela-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 18:50:57 by britela-          #+#    #+#             */
/*   Updated: 2025/05/28 21:35:25 by britela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	ssize_t	i;// peut contenir un -
	char	*word;
	static	char *conc;

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
	conc = "";
	while ((i = read(fd, word, BUFFER_SIZE)) > 0)
	{
		if (word[i] == '\n')
		{
			return (word);
		}
		conc = ft_strjoin(conc, word); 
	}
	free(word);
	return (conc);
}
