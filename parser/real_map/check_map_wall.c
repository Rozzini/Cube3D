/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_wall.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uisroilo <uisroilo@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 06:55:55 by uisroilo          #+#    #+#             */
/*   Updated: 2022/12/04 09:19:03 by uisroilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	ft_check_start_end(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ')
		{
			i++;
			continue ;
		}
		else if (str[i] != '1')
			return (1);
		i++;
	}
	return (0);
}

int	ft_skip_space(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ')
		{
			i++;
			continue ;
		}
		break ;
	}
	return (i);
}

int	ft_check_left_right(char *str)
{
	int	i;
	int	tmp;

	i = ft_skip_space(str);
	tmp = i;
	while (str[i])
	{
		if (str[tmp] != '1')
			return (1);
		i++;
	}
	i = i - 1;
	while (str[i])
	{
		if (str[i] == ' ')
		{
			i--;
			continue ;
		}
		break ;
	}
	if (str[i] != '1')
		return (1);
	return (0);
}

int	check_map_border(t_base base)
{
	while (base.real_map)
	{
		if (base.real_map->prev == NULL)
		{
			if (ft_check_start_end(base.real_map->str))
				return (1);
		}
		else if (base.real_map->next == NULL)
		{
			if (ft_check_start_end(base.real_map->str))
				return (1);
		}
		else
		{
			if (ft_check_left_right(base.real_map->str))
				return (1);
		}
		base.real_map = base.real_map->next;
	}
	return (0);
}
