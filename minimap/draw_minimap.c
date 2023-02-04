/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabdoush <gabdoush@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 01:47:34 by gabdoush          #+#    #+#             */
/*   Updated: 2023/01/02 03:29:26 by gabdoush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../cub3d.h"


/*============================================================================*/
void	vec_cord(t_base* data)
{
	double	adjacent;
	double	opposite;

	
	adjacent = data->minimap->vec_len * cos(data->vec_angle);
	opposite = data->minimap->vec_len * sin(data->vec_angle);
	data->minimap->vec_x = (data->minimap->mini_win_end_x / 2) + opposite;
	data->minimap->vec_y = (data->minimap->mini_win_end_y / 2) - adjacent;
}

/*============================================================================*/
void	draw_minimap_player(t_base *data)
{
	vec_cord(data);
	draw_circle(data,
				data->minimap->mini_win_end_x / 2, 
				data->minimap->mini_win_end_y / 2, 
				data->minimap->minimap_chara_size , 0x663444);
	draw_slice(data, data->minimap->mini_win_end_x / 2, 
				data->minimap->mini_win_end_y / 2, 
				data->minimap->vec_x, 
				data->minimap->vec_y,
				0x663444);
}

/*============================================================================*/
static void	init_minimap_borders(t_base *data)
{
	data->minimap->mini_win_start_x = 0;
	data->minimap->mini_win_start_y = 0;
	data->minimap->mini_win_end_x = 495;
	data->minimap->mini_win_end_y = 285;

	data->minimap->start_x = data->minimap->player_pos_x - (data->minimap->mini_win_end_x / 2);
	data->minimap->start_y = data->minimap->player_pos_y - (data->minimap->mini_win_end_y / 2);
	
	data->minimap->end_x =  data->player_x + (data->minimap->mini_win_end_x / 2);
	data->minimap->end_y =  data->player_y + (data->minimap->mini_win_end_y / 2);
}

/*============================================================================*/
static void	loop_map_x(t_base *data)
{
	data->minimap->row = ((int)data->minimap->start_x / (int)data->minimap->minimap_img_size);
	if (data->minimap->start_y < 0 || data->minimap->start_x < 0)
		my_mlx_pixel_put(data, data->minimap->mini_win_start_x, data->minimap->mini_win_start_y,  0xbc8f8f);

	else if (data->minimap->row > data->map_w|| data->minimap->col > data->map_h - 1)
		my_mlx_pixel_put(data, data->minimap->mini_win_start_x, data->minimap->mini_win_start_y,  0xbc8f8f);


	else if (data->raw_map[data->minimap->col][data->minimap->row] == '1')
		my_mlx_pixel_put(data, data->minimap->mini_win_start_x, data->minimap->mini_win_start_y, 0x68838b);
	else if (data->raw_map[data->minimap->col][data->minimap->row] == ' ')
		my_mlx_pixel_put(data, data->minimap->mini_win_start_x, data->minimap->mini_win_start_y, 0xbc8f8f);
	else if (data->raw_map[data->minimap->col][data->minimap->row] == '0'
			|| data->raw_map[data->minimap->col][data->minimap->row] == 'N'
			|| data->raw_map[data->minimap->col][data->minimap->row] == 'S'
			|| data->raw_map[data->minimap->col][data->minimap->row] == 'E'
			|| data->raw_map[data->minimap->col][data->minimap->row] == 'W')
		my_mlx_pixel_put(data, data->minimap->mini_win_start_x, data->minimap->mini_win_start_y, 0xcdba96);
	data->minimap->mini_win_start_x++;
	data->minimap->start_x++;
}

/*============================================================================*/
void	draw_minimap(t_base *data)
{
	double	tmp_start_x;

	init_minimap_borders(data);
	tmp_start_x = data->minimap->start_x;
	while (data->minimap->mini_win_start_y <= data->minimap->mini_win_end_y)
	{
		data->minimap->col = ((int)data->minimap->start_y / (int)data->minimap->minimap_img_size);
		while (data->minimap->mini_win_start_x <= data->minimap->mini_win_end_x)
			loop_map_x(data);
		data->minimap->mini_win_start_x = 0;
		data->minimap->mini_win_start_y++;
		data->minimap->start_x = tmp_start_x;
		data->minimap->start_y++;
	}
	draw_minimap_player(data);
}

/*============================================================================*/