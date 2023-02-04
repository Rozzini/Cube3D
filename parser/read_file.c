/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabdoush <gabdoush@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 15:42:05 by uisroilo          #+#    #+#             */
/*   Updated: 2022/12/05 15:12:01 by gabdoush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	read_file(char *map_file, t_base *base)
{
	int		fd;
	char	*next_line;
	t_map	*data;

	data = NULL;
	if (!map_file)
		extension_error();
	fd = open(map_file, O_RDONLY);
	next_line = get_next_line(fd);
	while (next_line)
	{
		append(&data, next_line);
		free(next_line);
		next_line = get_next_line(fd);
	}
	/**
	 ** Link t_map to the t_base structure.
	 * */
	base->map = data;
	close(fd);
}

/*=======================================================================*/
void	extracting_raw_map(t_base *data)
{
	t_map_real	*tmp_map;
	char	**tmp_char;
	int		size;

	size = 0;
	tmp_map = data->real_map;
	while (data->real_map != NULL)
	{
		data->real_map = data->real_map->next;
		size++;
	}
	data->raw_map = ft_calloc(sizeof(char *), (size + 1));
	tmp_char = data->raw_map;
	size = 0;
	data->real_map = tmp_map;
	data->map_w = ft_strlen(data->real_map->str) - 1;
	while (data->real_map != NULL && data->real_map->str)
	{
		data->raw_map[size] = ft_strdup(data->real_map->str);
		data->real_map = data->real_map->next;
		size++;
	}
	data->map_h = size;
	data->raw_map[size] = NULL;
	/**
	 ** Moving the pointer for the first location of the map.
	 ** To make it ready to delete the linked list.
	 **/
	data->real_map = tmp_map;
	data->raw_map = tmp_char;
}

/*=======================================================================*/