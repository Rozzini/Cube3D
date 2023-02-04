/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uisroilo <uisroilo@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 15:12:19 by uisroilo          #+#    #+#             */
/*   Updated: 2022/11/29 15:12:43 by uisroilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/*=======================================================================*/
void	extension_error(void)
{
	ft_putendl_fd("Wrong file extension!!!!!", 2);
	ft_putendl_fd("Just <.cub> extension", 2);
	exit(EXIT_FAILURE);
}

/*=======================================================================*/
void	check_extension(int argc, char **argv)
{
	char	*extension;
	char	*ptr;
	int		tmp_fd;

	extension = "";
	ptr = ".cub";
	if (argc == 2)
	{
		tmp_fd = open(argv[1], O_RDONLY);
		if (tmp_fd == -1)
				extension_error();
		close(tmp_fd);
		extension = ft_strrchr(argv[1], '.');
		if (!extension || ft_strcmp(extension, ptr))
			extension_error();
	}
}

/*=======================================================================*/