/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays_casting_2D.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabdoush <gabdoush@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 23:59:56 by gabdoush          #+#    #+#             */
/*   Updated: 2023/01/02 06:33:29 by gabdoush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../cub3d.h"


/*=======================================================================*/
int	check_assets(t_base *data)
{
	if (data->raw_map[data->line->col][data->line->row] == '1' ||
		data->raw_map[data->line->col][data->line->row] == '0' ||
		data->raw_map[data->line->col][data->line->row] == 'N' ||
		data->raw_map[data->line->col][data->line->row] == 'S' ||
		data->raw_map[data->line->col][data->line->row] == 'W' ||
		data->raw_map[data->line->col][data->line->row] == 'E')
			return (1);
	else
		return (0);
}

/*=======================================================================*/
void	fined_ray_end_point(t_base* data)
{
	double	radius;
	double	adjacent;
	double	opposite;

	radius = 50000;

	adjacent = radius * cos(data->ray->ray_angle);
	opposite = radius * sin(data->ray->ray_angle);

	data->ray->ray_start_x = data->player_x;
	data->ray->ray_start_y = data->player_y;
	
	data->ray->ray_dist_x = data->ray->ray_start_x + opposite;
	data->ray->ray_dist_y = data->ray->ray_start_y - adjacent;
}

/*=======================================================================*/
void	find_ray_len(t_base *data)
{
	double	power_x_subtract;
	double	power_y_subtract;

	power_x_subtract = pow((data->ray->ray_dist_x - data->ray->ray_start_x), 2);
	power_y_subtract = pow(data->ray->ray_dist_y - data->ray->ray_start_y, 2);
	data->ray->ray_dist = sqrt(power_x_subtract + power_y_subtract);
}

/*=======================================================================*/
void	draw_2d(t_base *data)
{
	fined_ray_end_point(data);
	draw_one_ray(data, data->ray->ray_start_x, data->ray->ray_start_y, data->ray->ray_dist_x, data->ray->ray_dist_y);
	find_ray_len(data);
}

/*=======================================================================*/
void	casting_rays(t_base *data)
{
	/********* 120 FOV *********/
	// data->ray->ray_angle_rotation = ((pi / 3) * 2) / data->win_w;
	// data->ray->ray_angle = data->vec_angle + (pi / 3);

	/*********  90 FOV  *********/
	data->ray->ray_angle_rotation = (pi / 2) / data->win_w;
	data->ray->ray_angle = data->vec_angle + (pi / 4);

	// while (data->ray->ray_angle >= data->vec_angle - (pi / 3))
	while (data->ray->ray_angle >= data->vec_angle - (pi / 4))
	{
		draw_2d(data);
		draw_3d(data);
		data->vars_3D->wall_top_x-- ;
		data->ray->ray_angle -= data->ray->ray_angle_rotation;
	}
	/********* Reseting the ray angle and drawing width.********/
	// data->ray->ray_angle = data->vec_angle + (pi / 3);

	data->ray->ray_angle = data->vec_angle + (pi / 4);
	data->vars_3D->wall_top_x = data->win_w;
}

/*=======================================================================*/