/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: britela- <britela-@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 15:00:31 by britela-          #+#    #+#             */
/*   Updated: 2025/05/21 23:25:06 by bradley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(int argc, char **argv)
{
	int	fd;
	char	lettre;
	char	*text;

	if (argc != 2)
	{
		return (-1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		return (-1);
	}
	else
	{
		text = get_next_line(fd);
		while(text != NULL) // signifie que on est arriver a la fin du fichir.
		{
			printf("%s", text);
			text = get_next_line(fd);
		}
		close(fd);
	}
	return (0);
}
