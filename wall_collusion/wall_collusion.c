/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_collusion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabdoush <gabdoush@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 05:02:26 by gabdoush          #+#    #+#             */
/*   Updated: 2023/01/02 05:13:45 by gabdoush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../cub3d.h"


/*============================================================================*/
int	clear_front(t_base *data)
{
	double	adjacent;
	double	opposite;
	double	angle;
	int		x;
	int		y;

	double	start_x = data->char_x + data->chara_size - (data->chara_size / 2);
	double	start_y = data->char_y + data->chara_size - (data->chara_size / 2);
	angle = data->vec_angle + (pi / 6);
	while (angle >= data->vec_angle - (pi / 6))
	{
		adjacent = (data->chara_size + data->chara_size / 2) * cos(angle);
		opposite = (data->chara_size + data->chara_size / 2) * sin(angle);
		x = start_x + opposite;;
		y = start_y - adjacent;
		if (data->raw_map[(int)(y / data->img_size)][(int)(x / data->img_size)] == '1'
			|| data->raw_map[(int)(y / data->img_size)][(int)(x / data->img_size)] == ' ')
			return (0);
		angle -= 0.001;
	}
	return (1);
}

/*============================================================================*/
int	clear_back(t_base *data)
{
	double	adjacent;
	double	opposite;
	double	angle;
	int		x;
	int		y;

	double	start_x = data->char_x + data->chara_size - (data->chara_size / 2);
	double	start_y = data->char_y + data->chara_size - (data->chara_size / 2);
	angle = data->vec_angle + (pi / 6);
	while (angle >= data->vec_angle - (pi / 6))
	{
		adjacent = (data->chara_size + 10) * cos(angle);
		opposite = (data->chara_size + 10) * sin(angle);
		x = start_x - opposite;;
		y = start_y + adjacent;
		if (data->raw_map[(int)(y / data->img_size)][(int)(x / data->img_size)] == '1'
			|| data->raw_map[(int)(y / data->img_size)][(int)(x / data->img_size)] == ' ')
			return (0);
		angle -= 0.001;
	}
	return (1);
}

/*============================================================================*/
int	clear_right(t_base *data)
{
	int	col;
	int	row;
	int	x;
	int	y;

	x = data->checker->wall_check_right_x;
	y = data->checker->wall_check_right_y;
	
	col = y / data->img_size;
	row = x / data->img_size;
	if (data->raw_map[col][row] == '1' || data->raw_map[col][row] == ' ')
		return (0);
	return (1);
}

/*=======================================================================*/
int	clear_left(t_base *data)
{
	int	col;
	int	row;
	int	x;
	int	y;

	x = data->checker->wall_check_left_x;
	y = data->checker->wall_check_left_y;
	
	col = y / data->img_size;
	row = x / data->img_size;
	if (data->raw_map[col][row] == '1' || data->raw_map[col][row] == ' ')
		return (0);
	return (1);
}

/*=======================================================================*/