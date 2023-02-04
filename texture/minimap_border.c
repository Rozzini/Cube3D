/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_border.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabdoush <gabdoush@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 02:32:21 by gabdoush          #+#    #+#             */
/*   Updated: 2023/01/02 05:54:51 by gabdoush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include "../cub3d.h"
/*=======================================================================*/
void	draw_border(t_base *data)
{
	data->border->minimap_border_path = "./xpm/border.xpm";

	data->border->border_x = -1;
	data->border->border_y = -1;
	data->border->border_w = 1;
	data->border->border_h = 1;

	data->border->border_img = mlx_xpm_file_to_image(data->mlx, data->border->minimap_border_path, &data->border->border_w, &data->border->border_h);
	mlx_put_image_to_window(data->mlx, data->win, data->border->border_img, data->border->border_x, data->border->border_y);
	mlx_destroy_image(data->mlx, data->border->border_img);
}

/*=======================================================================*/