/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraspors <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 03:21:19 by mraspors          #+#    #+#             */
/*   Updated: 2022/12/25 03:53:39 by mraspors         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"


void	close_game()
{
	return ;
}

void	move()
{
	return ;
}

int	main(int argc, char **argv)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	init_struct(game);
	check_file_name(argc, argv[1], game);
	read_check_map(argv[1], game);
	// game->mlx = mlx_init();
	// if (!game->mlx)
	// 	return (0);
	// draw_map(game);
	// mlx_hook(game->mlx_win, 2, 1L << 0, move, game);
	// mlx_hook(game->mlx_win, 17, (1L << 17), close_game, game);
	// mlx_loop(game->mlx);
	return (0);
}
