/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraspors <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 04:10:22 by mraspors          #+#    #+#             */
/*   Updated: 2022/12/26 05:55:47 by mraspors         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube.h"

void	check_file_name(int argc, char *s, t_game *game)
{
	char	*c;

	if (argc < 2)
	{
		printf("Error\nAdd map\n");
		free_if_er(game);
	}
	c = ft_strnstr(s, ".cub", ft_strlen(s));
	if (ft_strcmp(c, ".cub") != 0)
	{
		printf("Error\nExtension Error\n");
		free_if_er(game);
	}
}

void	check_map_symbols_validity(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i] != NULL)
	{
		j = 0;
		while (game->map[i][j] != '\0')
		{
			if (is_map_symbol(game->map[i][j]) != 1)
			{
				printf("Error\nInvalid map symbol\n");
				free_if_er(game);
			}
			j++;
		}
		i++;
	}
}

void	check_map_validity(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i] != NULL)
	{
		j = 0;
		while (game->map[i][j] != '\0')
		{
			if (game->map[i][j] != '1' && ft_isspace(game->map[i][j]) != 1)
				is_symbol_safe(game, i, j);
			j++;
		}
		i++;
	}
}