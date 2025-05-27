/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: britela- <britela-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 18:50:57 by britela-          #+#    #+#             */
/*   Updated: 2025/05/27 20:05:15 by bradley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int	text;
	char	*buffer;
	//si existe pas
	if (fd <0 || BUFFER_SIZE <= 0)
	{
		return (NULL);
	}
	//alloue de la memoire pour buffer
	buffer = malloc(sizeof(char*) *BUFFER_SIZE);
	if (buffer == NULL)
	{
		return (NULL);
	}
	//je lis de mon fd a mon buffer et le nombre que je veux lire
	text = read(fd, buffer, BUFFER_SIZE);
	if (text <= 0)
	{
		free(buffer);
		return (NULL);
	}
	return (buffer);
}
