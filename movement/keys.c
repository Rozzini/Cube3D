/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabdoush <gabdoush@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 17:52:30 by gabdoush          #+#    #+#             */
/*   Updated: 2023/01/02 05:14:14 by gabdoush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../cub3d.h"

/*=======================================================================*/
void	key_W(t_base *data)
{
	if (clear_front(data))
	{
		data->char_x = data->checker->mv_x - (data->chara_size / 2);
		data->char_y = data->checker->mv_y - (data->chara_size / 2);

		data->minimap->player_pos_x = data->char_x / data->minimap->scale;
		data->minimap->player_pos_y = data->char_y / data->minimap->scale;
	}
	draw_map(data);
	hold_gun(data);
	draw_border(data);
}

/*=======================================================================*/
void	key_D(t_base *data)
{
	if (clear_right(data))
	{		
		data->char_x = data->checker->mv_right_x - (data->chara_size / 2);
		data->char_y = data->checker->mv_right_y - (data->chara_size / 2);
		
		data->minimap->player_pos_x = data->char_x / data->minimap->scale;
		data->minimap->player_pos_y = data->char_y / data->minimap->scale;
	}
	draw_map(data);
	hold_gun(data);
	draw_border(data);
}

/*=======================================================================*/
void	key_A(t_base *data)
{
	if (clear_left(data))
	{
		data->char_x = data->checker->mv_left_x - (data->chara_size / 2);
		data->char_y = data->checker->mv_left_y - (data->chara_size / 2);
		
		data->minimap->player_pos_x = data->char_x / data->minimap->scale;
		data->minimap->player_pos_y = data->char_y / data->minimap->scale;
	}
	draw_map(data);
	hold_gun(data);
	draw_border(data);
}

/*=======================================================================*/
void	key_S(t_base *data)
{
	if (clear_back(data))
	{
		data->char_x = data->checker->mv_rev_x - (data->chara_size / 2);
		data->char_y = data->checker->mv_rev_y - (data->chara_size / 2);

		data->minimap->player_pos_x = data->char_x / data->minimap->scale;
		data->minimap->player_pos_y = data->char_y / data->minimap->scale;
	}
	draw_map(data);
	hold_gun(data);
	draw_border(data);
}

/*=======================================================================*/
void	key_left(t_base *data, double angle_type)
{
	if ((data->vec_angle - angle_type) < 0)
		data->vec_angle = (data->vec_angle - angle_type) + (2 * pi);
	else
		data->vec_angle -= angle_type;
	draw_map(data);
	hold_gun(data);
	draw_border(data);
}

/*=======================================================================*/
void	key_right(t_base *data, double angle_type)
{
	if (data->vec_angle + angle_type > (pi * 2))
		data->vec_angle = (data->vec_angle + angle_type)  - (pi * 2);
	else
		data->vec_angle += angle_type;
	draw_map(data);
	hold_gun(data);
	draw_border(data);
}

/*============================================================================*/
void	key_up(t_base *data)
{
	data->vars_3D->mid_plane_y += 10;
	draw_map(data);
	hold_gun(data);
	draw_border(data);
}

/*============================================================================*/
void	key_down(t_base *data)
{
	data->vars_3D->mid_plane_y -= 10;
	draw_map(data);
	hold_gun(data);
	draw_border(data);
}

/*=======================================================================*/
void	speed_up(t_base *data)
{
	if (data->faster == 0)
	{
		data->checker->mv_speed = data->chara_size + 5;
		data->faster = 1;
	}
	else if (data->faster == 1)
	{
		data->checker->mv_speed = data->chara_size / 2;
		data->faster = 0;
	}
}

/*=======================================================================*/
int	handle_moving(int key, t_base *data)
{
	if (key == A)
		key_A(data);
	else if (key == S)
		key_S(data);
	else if (key == D)
		key_D(data);
	else if (key == W)
		key_W(data);
	else if (key == LEFT)
		key_left(data, data->rotation_angle);
	else if (key == RIGHT)
		key_right(data, data->rotation_angle);

	else if (key == UP)
		key_up(data);
	else if (key == DOWN)
		key_down(data);

	else if (key == Q)
	{
		mlx_mouse_hide();
		data->mouse->move = 1;
	}
	else if (key == E)
	{
		mlx_mouse_show();
		data->mouse->move = 0;
	}

	else if (key == SP)
		speed_up(data);

	closing_esc(key, data);
	return (0);
}

/*=======================================================================*/
