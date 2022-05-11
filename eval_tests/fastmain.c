/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fastmain.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elehtora <elehtora@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 22:22:09 by elehtora          #+#    #+#             */
/*   Updated: 2022/05/11 13:51:37 by elehtora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line.h"
#include <fcntl.h>

int main(int argc, char **argv)
{
	char	*line;
	int		fd;
	ssize_t	ret;
	char	*file;

	if (argc != 2)
		return -1;
	file = argv[1];
	fd = open(file, O_RDONLY);
	line = NULL;

	ret = 1;
	while (ret)
	{
		ret = get_next_line(fd, &line);
		free(line);
		/* Uncomment under to get output */
//		if (ret > 0)
//			ft_putendl(line);
	}
	if (ret == -1)
		ft_putendl("\n***\nError was produced. (returned -1)");
	if (ret == 0)
		ft_putendl("\n***\n>>>>>>>>Reading was completed (GNL exited with 0).<<<<<<<<<\n***\n");

	close(fd);
	return 0;
}
