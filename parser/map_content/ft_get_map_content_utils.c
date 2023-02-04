/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map_content_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uisroilo <uisroilo@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 10:57:32 by uisroilo          #+#    #+#             */
/*   Updated: 2022/12/04 14:11:37 by uisroilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	ft_check_each_char(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!((str[i] >= '0' && str[i] <= '9')
				|| str[i] == ' ' || str[i] == '\n'))
			return (1);
		i++;
	}
	return (0);
}

int	ft_check_each_value(char **arr)
{
	int	i;
	int	tmp;

	tmp = 0;
	i = 0;
	while (arr[i])
	{
		if (ft_check_each_char(arr[i]))
			return (1);
		tmp = ft_atoi(arr[i]);
		if ((tmp < 0) || (tmp > 255))
			return (1);
		i++;
	}
	return (0);
}

char	*ft_get_color_value(t_base base, char *str)
{
	char	**arr;
	char	*joined_str;
	int		i;
	char	*tmp;

	while (base.map)
	{
		arr = ft_split(base.map->line, ' ');
		if (arr[0] && ft_strcmp(arr[0], str) == 0)
		{
			i = 1;
			if (arr[i])
				joined_str = ft_strdup(arr[i]);
			while (arr[i] && arr[i + 1])
			{
				tmp = joined_str;
				joined_str = ft_strjoin(joined_str, arr[i + 1]);
				free(tmp);
				i++;
			}
		}
		free_2d(arr);
		base.map = base.map->next;
	}
	return (joined_str);
}

int	ft_helper(t_map_cont **data,
			t_base base, char *color_name)
{
	char	**arr;
	char	*tmp;
	char *joined_str;

	joined_str = ft_get_color_value(base, color_name);
	if (joined_str && ft_count_comma(joined_str))
		{
			free(joined_str);
			return (1);
		}
	if (joined_str)
	{
		arr = ft_split(joined_str, ',');
		if (ft_array_length(arr) != 3 || ft_check_each_value(arr))
		{
			free_2d(arr);
			free(joined_str);
			return (1);
		}
		free_2d(arr);
		tmp = (*data)->value;
		(*data)->value = ft_strdup(joined_str);
		free(joined_str);
		free(tmp);
	}
	return (0);
}

int	ft_check_cf_value(t_base base)
{

	while (base.t_map_content)
	{
		if (ft_strcmp(base.t_map_content->name, "C") == 0)
		{
			if (ft_helper(&base.t_map_content, base, "C"))
				return (1);
		}
		else if (ft_strcmp(base.t_map_content->name, "F") == 0)
		{
			if (ft_helper(&base.t_map_content, base, "F"))
				return (1);
		}
		base.t_map_content = base.t_map_content->next;
	}
	return (0);
}
