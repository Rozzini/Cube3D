/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraspors <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 04:10:22 by mraspors          #+#    #+#             */
/*   Updated: 2022/12/25 03:55:42 by mraspors         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube.h"

void	check_file_name(int argc, char *s, t_game *game)
{
	char	*c;

	if (argc < 2)
	{
		ft_printf("Error\nAdd map\n");
		free_if_er(game);
	}
	c = ft_strnstr(s, ".cub", ft_strlen(s));
	if (ft_strcmp(c, ".cub") != 0)
	{
		ft_printf("Error\nExtension Error\n");
		free_if_er(game);
	}
}