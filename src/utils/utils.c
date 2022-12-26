/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraspors <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 05:58:11 by mraspors          #+#    #+#             */
/*   Updated: 2022/12/26 05:57:50 by mraspors         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube.h"

void	init_struct(t_game *game)
{
	game->i_pars = 0;
	game->p_x = 0;
	game->p_y = 0;
	game->w = 0;
	game->h = 0;
	game->map = NULL;
	game->map_data = NULL;
	game->NO_texture = NULL;
	game->SO_texture = NULL;
	game->WE_texture = NULL;
	game->EA_texture = NULL;
	game->C_color = NULL;
	game->F_color = NULL;
}

//if its one of map symbol (1, 0, N,S,E or Wreturns 1
int		is_map_symbol(char c)
{
	if (c == '1' || c == '0' || c == 'N' || c == 'S' || 
		c == 'E' || c == 'W' || ft_isspace(c) == 1)
		return (1);
	return (0);
}

void	is_symbol_safe(t_game *game, int i, int j)
{
	int	err;

	err = 0;
	if (i == 0)
		err++;
	else if (i == game->h - 1)
		err++;
	else if (j == 0)
		err++;
	else if (game->map[i][j + 1] == '\0')
		err++;
	else
	{
		err += ft_isspace(game->map[i - 1][j]);
		err += ft_isspace(game->map[i + 1][j]);
		err += ft_isspace(game->map[i][j + 1]);
		err += ft_isspace(game->map[i][j - 1]);
	}
	if (err != 0)
	{
		printf("Error\nInvalid Map\n");
		free_if_er(game);
	}
}