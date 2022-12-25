/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_config.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraspors <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 05:29:00 by mraspors          #+#    #+#             */
/*   Updated: 2022/12/25 05:37:09 by mraspors         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube.h"

void	check_files_existence(t_game *game, char *s)
{
	int	fd;

	fd = 0;
	fd = open(s, O_RDONLY);
	if (fd < 0)
	{
		printf("File: %s does not exist\n", s);
		free_if_er(game);
	}
}

void	check_map_config(t_game *game)
{
    check_files_existence(game, game->NO_texture);
	check_files_existence(game, game->SO_texture);
	check_files_existence(game, game->WE_texture);
	check_files_existence(game, game->EA_texture);
}