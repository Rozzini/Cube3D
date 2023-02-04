/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabdoush <gabdoush@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 01:05:22 by gabdoush          #+#    #+#             */
/*   Updated: 2022/12/29 08:38:56 by gabdoush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../cub3d.h"


/*============================================================================*/
static void	get_floor_color_value(t_base *data, char *color_value)
{
	char	**splitted_color;

	splitted_color = ft_split(color_value, ',');
	data->colors->floor_red = ft_atoi(splitted_color[0]);
	data->colors->floor_green = ft_atoi(splitted_color[1]);
	data->colors->floor_blue = ft_atoi(splitted_color[2]);
	free_2d(splitted_color);
}

/*============================================================================*/
static void	get_ceiling_color_value(t_base *data, char *color_value)
{
	char	**splitted_color;

	splitted_color = ft_split(color_value, ',');
	data->colors->ceiling_red = ft_atoi(splitted_color[0]);
	data->colors->ceiling_green = ft_atoi(splitted_color[1]);
	data->colors->ceiling_blue = ft_atoi(splitted_color[2]);
	free_2d(splitted_color);
}

/*============================================================================*/
static void	get_floor_color(t_base *data)
{
	t_map_cont	*tmp;

	tmp = data->t_map_content;
	while (data->t_map_content)
	{
		if (ft_strcmp(data->t_map_content->name, "F") == 0)
		{
			get_floor_color_value(data, data->t_map_content->value);
			data->t_map_content = tmp;
			break ;
		}
		data->t_map_content = data->t_map_content->next;
	}
	data->t_map_content = tmp;
}

/*============================================================================*/
static void	get_ceiling_color(t_base *data)
{
	t_map_cont	*tmp;

	tmp = data->t_map_content;
	while (data->t_map_content)
	{
		if (ft_strcmp(data->t_map_content->name, "C") == 0)
		{
			get_ceiling_color_value(data, data->t_map_content->value);
			data->t_map_content = tmp;
			break ;
		}
		data->t_map_content = data->t_map_content->next;
	}
	data->t_map_content = tmp;
}

/*============================================================================*/
void	rgb_to_int(t_base *data)
{
	get_floor_color(data);
	get_ceiling_color(data);
	data->colors->floor_color = (data->colors->floor_red << 16) | (data->colors->floor_green << 8) | data->colors->floor_blue;
	data->colors->ceiling_color = (data->colors->ceiling_red << 16) | (data->colors->ceiling_green << 8) | data->colors->ceiling_blue;
}

/*============================================================================*/