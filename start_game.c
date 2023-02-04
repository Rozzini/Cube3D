/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabdoush <gabdoush@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 09:40:14 by gabdoush          #+#    #+#             */
/*   Updated: 2023/01/02 03:32:13 by gabdoush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"


/*============================================================================*/
void	assemble_player(t_base *data)
{
	movement_coordinates(data);
	wall_check_coordinates(data);
}

/*============================================================================*/
void	draw_map(t_base * data)
{
	data->img->img = mlx_new_image(data->mlx, data->win_w, data->win_h);
	data->img->addr = mlx_get_data_addr(data->img->img, &data->img->bits_per_pixel, &data->img->line_length, &data->img->endian);
	if (data->start_game == 0)
		get_player_position(data);
	data->start_game = 1;
	assemble_player(data);
	casting_rays(data);
	draw_minimap(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img->img, 0, 0);
	mlx_destroy_image(data->mlx, data->img->img);
}

/*============================================================================*/