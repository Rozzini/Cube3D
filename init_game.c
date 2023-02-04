/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabdoush <gabdoush@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 01:34:00 by gabdoush          #+#    #+#             */
/*   Updated: 2023/01/02 05:56:24 by gabdoush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


/*============================================================================*/
void	init_vals(t_base *data)
{
	data->width = 100;
	data->height = 100;
	
	data->win_w = 2640;
	data->win_h = 1330;

	data->img_x = 0;
	data->img_y = 0;

	data->img_size = 100;
	data->chara_size = 20;

	data->vec_angle = 0;
	data->rotation_angle = 0.04;
	data->mouse->mouse_rotation = 0.02;
	data->checker->mv_speed = data->chara_size - 2;
	data->checker->wall_check_dist = data->chara_size * 2;
	data->vars_3D->wall_top_x = data->win_w;
	data->vars_3D->mid_plane_y = data->win_h / 2;
	data->mouse->mouse_x = 0;
	data->mouse->mouse_y = 0;
	data->start_game = 0;
	data->faster = 0;
	data->mouse->move = 0;
	
	/**
	 **-------------------*
	 ** MINIMAP VARIABLE 
	 **-------------------*/
	data->minimap->scale = 3;
	data->minimap->minimap_blocks = 3;
	data->minimap->vec_len = 10;
	data->minimap->minimap_img_size = data->img_size / data->minimap->scale;
	data->minimap->minimap_chara_size = data->chara_size / data->minimap->scale;
}

/*============================================================================*/
void	put_player(t_base *data, int i, int j)
{
	data->char_x = (data->img_x) + ((data->img_size / 2) - (data->chara_size / 2));
	data->char_y = (data->img_y) + ((data->img_size / 2) - (data->chara_size / 2));

	data->minimap->player_pos_x = data->char_x / data->minimap->scale;
	data->minimap->player_pos_y = data->char_y / data->minimap->scale;
	
	data->img_x += data->img_size;
	data->player_dir = data->raw_map[i][j];
}

/*============================================================================*/
void	get_player_position(t_base *data)
{
	int	i;
	int	j;
	
	i = 0;
	while (data->raw_map[i] != NULL)
	{
		j = 0;
		while (data->raw_map[i][j] != '\0')
		{
			if (data->raw_map[i][j] == '1' || data->raw_map[i][j] == '0' || data->raw_map[i][j] == ' ')
				data->img_x += data->img_size;
			else if (data->raw_map[i][j] == 'N' || data->raw_map[i][j] == 'S' || data->raw_map[i][j] == 'W' || data->raw_map[i][j] == 'E')
				put_player(data, i, j);
			j++;
			if (data->raw_map[i][j] == '\0')
			{
				data->img_x = 0;
				data->img_y += data->img_size;
			}
		}
		i++;
	}
	data->img_x = 0;
	data->img_y = 0;
}

/*=======================================================================*/
void	init_vec_angle(t_base *data)
{
	int	i;
	int	j;
	
	i = 0;
	while (data->raw_map[i] != NULL)
	{
		j = 0;
		while (data->raw_map[i][j] != '\0')
		{
			if (data->raw_map[i][j] == 'N'
				|| data->raw_map[i][j] == 'S' 
				|| data->raw_map[i][j] == 'W' 
				|| data->raw_map[i][j] == 'E')
				data->player_dir = data->raw_map[i][j];
			j++;
		}
		i++;
	}
	if (data->player_dir == 'N')
		data->vec_angle = 0;
	else if (data->player_dir == 'S')
		data->vec_angle = pi;
	else if (data->player_dir == 'E')
		data->vec_angle = pi / 2;
	else if (data->player_dir == 'W')
		data->vec_angle = ((3 * pi) / 2);
}

/*=======================================================================*/