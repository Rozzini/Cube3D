/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays_casting_3D.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabdoush <gabdoush@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 17:53:18 by gabdoush          #+#    #+#             */
/*   Updated: 2023/01/02 06:25:54 by gabdoush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../cub3d.h"


/*===========================================================================*/
void	calc_pend_angle(t_base *data)
{
	// comp variable is just a flag to decide if the ray on the 
	// left or right side of the vector
	
	// angle here to calculate the peduncular distance of the ray.
	
	double	ray_angle;
	double	vec_ray_angle;
	int		comp;

	ray_angle = data->ray->ray_angle;
	comp = 0;
	
	/*-------------------------------------------------------*/
	// ray on the right side
	if (ray_angle >= data->vec_angle)
		comp = 1;
	// ray on the left side
	else
		comp = 0;
	/*-------------------------------------------------------*/
	// edit the ray angle to be between 0 and 360 deg
	if (ray_angle > (pi * 2))
		ray_angle = ray_angle - (2 * pi);
	/*-------------------------------------------------------*/
	/**
	 * ! if the vector angle is between 0 and 90 deg */
	if (data->vec_angle >= 0 && data->vec_angle <= (pi / 2) && comp == 1)
	{
		vec_ray_angle = ray_angle - data->vec_angle;
		data->ray->pend_angle = (pi / 2) - vec_ray_angle;
	}
	else if (data->vec_angle >= 0 && data->vec_angle <= (pi / 2) && comp == 0 && ray_angle > 0)
	{
		vec_ray_angle =  data->vec_angle - ray_angle;
		data->ray->pend_angle = (pi / 2) - vec_ray_angle;
	}
	// Edge case, when the ray angle is negative and the vector angle is between 0 and 90 deg.
	else if (data->vec_angle >= 0 && data->vec_angle <= (pi / 2) && comp == 0 && ray_angle < 0)
	{
		ray_angle *= (-1);
		vec_ray_angle =  data->vec_angle + ray_angle;
		data->ray->pend_angle = (pi / 2) - vec_ray_angle;
	}
	/*-------------------------------------------------------*/
	/**
	 * ! if the vector angle is between 90 and 180 deg */
	else if (data->vec_angle > (pi / 2) && data->vec_angle <= pi && comp == 1)
	{
		vec_ray_angle =  ray_angle - data->vec_angle;
		data->ray->pend_angle = (pi / 2) - vec_ray_angle;
	}
	else if (data->vec_angle > (pi / 2) && data->vec_angle <= pi && comp == 0)
	{
		vec_ray_angle =  data->vec_angle - ray_angle;
		data->ray->pend_angle = (pi / 2) - vec_ray_angle;
	}
	/*-------------------------------------------------------*/
	/**
	 * ! if the vector angle is between 180 and 270 deg*/
	// ((3 * pi) / 2) = 270 degree
	else if (data->vec_angle > pi && data->vec_angle <= ((3 * pi) / 2) && comp == 1)
	{
		vec_ray_angle =  ray_angle - data->vec_angle;
		data->ray->pend_angle = (pi / 2) - vec_ray_angle;
	}
	else if (data->vec_angle > pi && data->vec_angle <= ((3 * pi) / 2) && comp == 0)
	{
		vec_ray_angle =  data->vec_angle - ray_angle;
		data->ray->pend_angle = (pi / 2) - vec_ray_angle;
	}
	/*-------------------------------------------------------*/
	/**
	 * ! if the vector angle is between 270 and 360 deg */
	else if (data->vec_angle > (3 * pi) / 2 && data->vec_angle <= (2 * pi) && comp == 1)
	{
		vec_ray_angle =  ray_angle - data->vec_angle;
		data->ray->pend_angle = (pi / 2) - vec_ray_angle;
	}
	else if (data->vec_angle > (3 * pi) / 2 && data->vec_angle <= (2 * pi) && comp == 0)
	{
		vec_ray_angle = data->vec_angle - ray_angle;
		data->ray->pend_angle = (pi / 2) - vec_ray_angle;
	}
	// Edge case, when the ray angle is between (0 and 90), and the vector angle is between (270, 360).
	else if (data->vec_angle > (3 * pi) / 2 && data->vec_angle <= (2 * pi) && comp == 0 && ray_angle >= 0 && ray_angle < (pi / 2))
	{
		vec_ray_angle =  data->vec_angle + ray_angle;
		data->ray->pend_angle = (pi / 2) - vec_ray_angle;
	}
}

/*============================================================================*/
void	draw_3d_floor(t_base *data)
{
	// Floor
	data->vars_3D->floor_top_y = data->vars_3D->wall_down_y;
	data->vars_3D->floor_down_y = data->win_h;
	data->vars_3D->floor_top_x = data->vars_3D->wall_top_x;
	data->vars_3D->floor_down_x = data->vars_3D->wall_down_x;
	draw_slice(data, data->vars_3D->floor_top_x, data->vars_3D->floor_top_y, data->vars_3D->floor_down_x, data->vars_3D->floor_down_y, data->colors->floor_color);
}

/*============================================================================*/
void	draw_3d_ceiling(t_base *data)
{
	//Ceiling
	data->vars_3D->ceiling_top_y = 0;
	data->vars_3D->ceiling_down_y = data->vars_3D->wall_top_y;
	data->vars_3D->ceiling_top_x = data->vars_3D->wall_top_x;
	data->vars_3D->ceiling_down_x = data->vars_3D->wall_down_x;
	draw_slice(data, data->vars_3D->ceiling_top_x, data->vars_3D->ceiling_top_y, data->vars_3D->ceiling_down_x, data->vars_3D->ceiling_down_y, data->colors->ceiling_color);
}

/*============================================================================*/
void	draw_3d_wall(t_base *data)
{
	calc_pend_angle(data);
	data->ray->pend_dist = data->ray->ray_dist * sin(data->ray->pend_angle);
	data->vars_3D->slice_hight = (data->img_size / data->ray->pend_dist) * data->vars_3D->proj_plane_dist;
	data->vars_3D->wall_top_y = data->vars_3D->mid_plane_y - (data->vars_3D->slice_hight / 2);
	data->vars_3D->wall_down_x = data->vars_3D->wall_top_x;
	data->vars_3D->wall_down_y = data->vars_3D->mid_plane_y + (data->vars_3D->slice_hight / 2);
	draw_slice(data, data->vars_3D->wall_top_x, data->vars_3D->wall_top_y, data->vars_3D->wall_down_x, data->vars_3D->wall_down_y, 0x88C278);
}

/*============================================================================*/
void	draw_3d(t_base *data)
{
	/* cause i have 2560 ray beeing casted. */
	data->vars_3D->fov = 2560;
	
	/* all the view angle is 120 deg, half of it is = (pi / 3)) */
	data->vars_3D->proj_plane_dist = ((data->vars_3D->fov / 2) / tan(pi / 5));
	draw_3d_wall(data);
	draw_3d_floor(data);
	draw_3d_ceiling(data);
}

/*============================================================================*/