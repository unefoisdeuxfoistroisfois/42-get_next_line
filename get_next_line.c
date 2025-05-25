/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: britela- <britela-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 18:50:57 by britela-          #+#    #+#             */
/*   Updated: 2025/05/25 17:58:12 by britela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*text;
	char	*buffer;

	text = NULL;
	if (fd < 0 || read(fd, text, 0) < 0) //Si notre fichier n'est pas lisbile
	{
		return (NULL);
	}
	buffer = malloc(sizeof(char*) *BUFFER_SIZE);
	if (buffer == NULL)
	{
		return (NULL);
	}
	while (read(fd , &buffer, BUFFER_SIZE) > 0) // je lis de mon fd a mon buffer et le nombre que je veux lire
	{
	
	return (text);
}
