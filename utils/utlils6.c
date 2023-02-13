/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utlils6.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraspors <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:58:41 by mraspors          #+#    #+#             */
/*   Updated: 2023/02/13 16:58:42 by mraspors         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	frame_counter(void *data)
{
	t_data	*img;

	img = (t_data *)data;
	img->frame++;
	raycast(img);
	return (0);
}

int	get_t(int trgb)
{
	return ((trgb >> 24) & 0xFF);
}
