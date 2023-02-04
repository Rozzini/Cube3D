/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uisroilo <uisroilo@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 11:49:29 by uisroilo          #+#    #+#             */
/*   Updated: 2022/12/04 10:06:08 by uisroilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	ft_array_length(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

int	ft_count_comma(char *str)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == ',')
			count++;
		i++;
	}
	if (count != 2)
		return (1);
	return (0);
}

void	ft_init(t_content *data)
{
	data->c = 0;
	data->f = 0;
	data->ea = 0;
	data->no = 0;
	data->so = 0;
	data->we = 0;
}

int	ft_break_point(char **arr)
{
	if (ft_array_length(arr) != 2
		&& (arr[0] && ft_strcmp(arr[0], "F") != 0 && ft_strcmp(arr[0], "C") != 0))
	{
		free_2d(arr);
		return (1);
	}
	if (arr[0] && ft_check_isdigit(arr[0]))
	{
		free_2d(arr);
		return (1);
	}
	return (0);
}
