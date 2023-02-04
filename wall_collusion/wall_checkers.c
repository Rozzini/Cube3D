/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_checkers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabdoush <gabdoush@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 04:10:03 by gabdoush          #+#    #+#             */
/*   Updated: 2022/12/30 03:40:41 by gabdoush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../cub3d.h"

/*=======================================================================*/
void	wall_check_coordinates_front(t_base* data)
{
	double	adjacent;
	double	opposite;

	adjacent = data->checker->wall_check_dist * cos(data->vec_angle);
	opposite = data->checker->wall_check_dist * sin(data->vec_angle);
	data->checker->wall_check_front_x = data->player_x + opposite;
	data->checker->wall_check_front_y = data->player_y - adjacent;
}

/*=======================================================================*/
void	wall_check_coordinates_back(t_base* data)
{
	double	adjacent;
	double	opposite;

	adjacent = data->checker->wall_check_dist * cos(data->vec_angle);
	opposite = data->checker->wall_check_dist * sin(data->vec_angle);
	data->checker->wall_check_rev_x = data->player_x - opposite;
	data->checker->wall_check_rev_y = data->player_y + adjacent;
}

/*=======================================================================*/
void	wall_check_coordinates_right(t_base* data)
{
	double	adjacent;
	double	opposite;
	double	angle;

	angle = pi - (data->vec_angle + (pi / 2));
	adjacent = data->checker->wall_check_dist * cos(angle);
	opposite = data->checker->wall_check_dist * sin(angle);
	data->checker->wall_check_right_x = data->player_x + opposite;
	data->checker->wall_check_right_y = data->player_y + adjacent;
}

/*=======================================================================*/
void	wall_check_coordinates_left(t_base* data)
{
	double	adjacent;
	double	opposite;
	double	angle;

	angle = pi - (data->vec_angle + (pi / 2));
	adjacent = data->checker->wall_check_dist * cos(angle);
	opposite = data->checker->wall_check_dist * sin(angle);
	data->checker->wall_check_left_x = data->player_x - opposite;
	data->checker->wall_check_left_y = data->player_y - adjacent;
}

/*=======================================================================*/
void	wall_check_coordinates(t_base *data)
{
	data->player_x = data->char_x + data->chara_size - (data->chara_size / 2);
	data->player_y = data->char_y + data->chara_size - (data->chara_size / 2);

	wall_check_coordinates_front(data);
	wall_check_coordinates_back(data);
	wall_check_coordinates_right(data);
	wall_check_coordinates_left(data);
}

/*=======================================================================*/