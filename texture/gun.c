/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gun.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabdoush <gabdoush@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 13:52:04 by gabdoush          #+#    #+#             */
/*   Updated: 2023/01/02 05:54:06 by gabdoush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../cub3d.h"

/*=======================================================================*/
void	hold_gun(t_base *data)
{
	data->gun->gun_path = "./xpm/gun.xpm";
	data->gun->curser_path = "./xpm/curser.xpm";

	data->gun->gun_x = (data->vars_3D->fov / 2);
	data->gun->gun_y = (data->win_h / 2) + 150;
	data->gun->gun_w = 1;
	data->gun->gun_h = 1;

	data->gun->gun_img = mlx_xpm_file_to_image(data->mlx, data->gun->gun_path, &data->gun->gun_w, &data->gun->gun_h);
	data->gun->curser_img = mlx_xpm_file_to_image(data->mlx, data->gun->curser_path, &data->gun->gun_w, &data->gun->gun_h);

	mlx_put_image_to_window(data->mlx, data->win, data->gun->gun_img, data->gun->gun_x, data->gun->gun_y);
	mlx_put_image_to_window(data->mlx, data->win, data->gun->curser_img, (data->win_w / 2), (data->win_h / 2) + 20);

	mlx_destroy_image(data->mlx, data->gun->curser_img);
	mlx_destroy_image(data->mlx, data->gun->gun_img);
}

/*=======================================================================*/