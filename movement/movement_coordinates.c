/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_coordinates.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabdoush <gabdoush@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 03:52:40 by gabdoush          #+#    #+#             */
/*   Updated: 2023/01/01 22:53:13 by gabdoush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../cub3d.h"

/*=======================================================================*/
void	movement_coordinates_right(t_base* data)
{
	double	adjacent;
	double	opposite;
	double	angle;

	angle = pi - (data->vec_angle + (pi / 2));
	adjacent = data->checker->mv_speed * cos(angle);
	opposite = data->checker->mv_speed * sin(angle);
	data->checker->mv_right_x = data->player_x + opposite;
	data->checker->mv_right_y = data->player_y + adjacent;
}

/*=======================================================================*/
void	movement_coordinates_left(t_base* data)
{
	double	adjacent;
	double	opposite;
	double	angle;

	angle = pi - (data->vec_angle + (pi / 2));
	adjacent = data->checker->mv_speed * cos(angle);
	opposite = data->checker->mv_speed * sin(angle);
	data->checker->mv_left_x = data->player_x - opposite;
	data->checker->mv_left_y = data->player_y - adjacent;
}

/*=======================================================================*/
void	movement_coordinates_reverse(t_base* data)
{
	double	adjacent;
	double	opposite;

	adjacent = data->checker->mv_speed * cos(data->vec_angle);
	opposite = data->checker->mv_speed * sin(data->vec_angle);
	data->checker->mv_rev_x = data->player_x - opposite;
	data->checker->mv_rev_y = data->player_y + adjacent;
}

/*=======================================================================*/
void	movement_coordinates_forward(t_base* data)
{
	double	adjacent;
	double	opposite;

	
	adjacent = data->checker->mv_speed * cos(data->vec_angle);
	opposite = data->checker->mv_speed * sin(data->vec_angle);
	data->checker->mv_x = data->player_x + opposite;
	data->checker->mv_y = data->player_y - adjacent;
}

/*=======================================================================*/
void	movement_coordinates(t_base *data)
{
	data->player_x = data->char_x + data->chara_size - (data->chara_size / 2);
	data->player_y = data->char_y + data->chara_size - (data->chara_size / 2);
	movement_coordinates_forward(data);
	movement_coordinates_reverse(data);
	movement_coordinates_right(data);
	movement_coordinates_left(data);
}

/*=======================================================================*/