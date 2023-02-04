/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map_content.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uisroilo <uisroilo@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 17:04:28 by uisroilo          #+#    #+#             */
/*   Updated: 2022/11/30 17:26:45 by uisroilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

/*=======================================================================*/

int	ft_check_isdigit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 1)
			return (1);
		i++;
	}
	return (0);
}

/*=======================================================================*/

int	ft_check_lenth(t_base base)
{
	int	i;

	i = 0;
	while (base.t_map_content)
	{
		i++;
		base.t_map_content = base.t_map_content->next;
	}
	if (i == 6)
		return (0);
	return (1);
}

/*=======================================================================*/

void	ft_get_map_content(t_base *base)
{
	char		**arr;
	t_map_cont	*data;
	t_map		*tmp;
	char	*tmp_str;

	tmp_str = NULL;
	data = NULL;
	tmp = base->map;
	while (base->map)
	{
		tmp_str = base->map->line;
		base->map->line = ft_remove_nl(base->map->line);
		free(tmp_str);
		arr = ft_split(base->map->line, ' ');
		if (base->map->line[0] && arr[0] == NULL)
			break ;
		if (ft_break_point(arr))
			break ;
		if (arr[0] && arr[1])
			ft_add_back(arr[0], arr[1], &data);
		free_2d(arr);
		base->map = base->map->next;
	}
	base->t_map_content = data;
	base->map = tmp;
}

/*=======================================================================*/

int	ft_check_items_exist(t_base base)
{
	t_content	data;

	ft_init(&data);
	while (base.t_map_content)
	{
		if (ft_strcmp(base.t_map_content->name, "NO") == 0)
			data.no = 1;
		else if (ft_strcmp(base.t_map_content->name, "SO") == 0)
			data.so = 1;
		else if (ft_strcmp(base.t_map_content->name, "EA") == 0)
			data.ea = 1;
		else if (ft_strcmp(base.t_map_content->name, "WE") == 0)
			data.we = 1;
		else if (ft_strcmp(base.t_map_content->name, "C") == 0)
			data.c = 1;
		else if (ft_strcmp(base.t_map_content->name, "F") == 0)
			data.f = 1;
		base.t_map_content = base.t_map_content->next;
	}
	if (data.no && data.so && data.we && data.ea && data.c && data.f)
		return (0);
	return (1);
}

/*=======================================================================*/

int	get_map_content(t_base *base)
{
	ft_get_map_content(base);
	if (ft_check_lenth(*base) || ft_check_items_exist(*base))
		return (1);
	if (ft_check_cf_value(*base) || ft_check_direction_value(*base))
		return (1);
	return (0);
}

/*=======================================================================*/
