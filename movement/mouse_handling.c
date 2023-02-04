/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabdoush <gabdoush@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 03:23:50 by gabdoush          #+#    #+#             */
/*   Updated: 2022/12/25 03:28:49 by gabdoush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../cub3d.h"


/*============================================================================*/
int	mouse_movement(int x, int y, t_base *data)
{
	(void)	y;

	if (data->mouse->move == 1)
	{
		if (x > data->win_w / 2)
			key_right(data, data->mouse->mouse_rotation);
		else
			key_left(data, data->mouse->mouse_rotation);
		mlx_mouse_move(data->win, data->win_w / 2, data->win_h / 2);
	}
	return (0);
}

/*============================================================================*/