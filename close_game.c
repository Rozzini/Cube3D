/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabdoush <gabdoush@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 03:06:20 by gabdoush          #+#    #+#             */
/*   Updated: 2023/01/02 05:55:01 by gabdoush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include "cub3d.h"


/*=======================================================================*/
void	closing_esc(int key, t_base *data)
{
	if (key == 53)
	{
		free_structs(data);
		exit(EXIT_SUCCESS);
	}
}

/*=======================================================================*/
int	closing_x(t_base *data)
{
	free_structs(data);
	exit(EXIT_SUCCESS);
}

/*=======================================================================*/
void	free_2d(char **data)
{
	int	i;

	i = 0;
	while (data[i])
	{
		free(data[i]);
		data[i] = NULL;
		i++;
	}
	free(data);
	data = NULL;
}

/*=======================================================================*/
void	free_structs(t_base *data)
{
	// free_2d(data->raw_map);
	if (data->map)
		delete_list(data->map);
	if (data->t_map_content->name)
		delete_list3(data->t_map_content);
	if (data->real_map && data->real_map->str)
	if (data->real_map && data->real_map->str)
		delete_list2(data->real_map);
	/**
	 ** @brief free the four struct that had been allocated at the beginning.*/
	free(data->line);
	free(data->ray);
	free(data->img);
	free(data->vars_3D);
	free(data->checker);
	free(data->colors);
	free(data->mouse);
	free(data->gun);
	free(data->minimap);
	free(data->border);
}

/*=======================================================================*/
void	free_list(t_map *data)
{
	t_map	*tmp1;
	t_map	*tmp2;

	tmp1 = data;
	while (tmp1)
	{
		tmp2 = tmp1;
		tmp1 = tmp1->next;
		free(tmp2);
	}
}

/*=======================================================================*/