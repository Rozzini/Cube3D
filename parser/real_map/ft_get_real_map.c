/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_real_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uisroilo <uisroilo@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:53:11 by uisroilo          #+#    #+#             */
/*   Updated: 2022/12/01 10:23:05 by uisroilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	ft_remove_new_line(t_base base)
{
	char		*tmp_str;

	tmp_str = NULL;
	while (base.real_map)
	{
		tmp_str = base.real_map->str;
		base.real_map->str = ft_remove_nl(base.real_map->str);
		free(tmp_str);
		base.real_map = base.real_map->next;
	}
}

static	t_map	*ft_reach_map(t_base *base)
{
	char		**arr;
	t_map		*tmp;
	t_map		*ret_tmp;

	ret_tmp = NULL;
	tmp = base->map;
	while (base->map)
	{
		arr = ft_split(base->map->line, ' ');
		if (arr[0] && ft_strcmp(arr[0], "\n") == 0)
		{
			base->map = base->map->next;
			free_2d(arr);
			continue ;
		}
		if (ft_break_point(arr))
			break ;
		free_2d(arr);
		base->map = base->map->next;
	}
	ret_tmp = base->map;
	base->map = tmp;
	return (ret_tmp);
}

void	ft_get_real_map(t_base *base)
{
	t_map_real	*data;
	t_map		*head_map;

	data = NULL;
	head_map = ft_reach_map(base);
	while (head_map)
	{
		append_sec(&data, head_map->line);
		head_map = head_map->next;
	}
	base->real_map = data;
}
