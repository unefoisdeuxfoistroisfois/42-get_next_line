/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bradley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 18:20:17 by bradley           #+#    #+#             */
/*   Updated: 2025/05/28 21:44:54 by britela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char const *str)
{
	size_t	i;

	i = 0;
	while(str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newword;
	int		i;
	int		j;

	newword = malloc(sizeof(char) * ((ft_strlen(s1) + ft_strlen(s2)) + 1));
	if (newword == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		newword[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		newword[i] = s2[j];
		i++;
		j++;
	}
	newword[i] = '\0';
	return (newword);
}
