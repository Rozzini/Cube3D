/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_real_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uisroilo <uisroilo@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:43:30 by uisroilo          #+#    #+#             */
/*   Updated: 2022/12/05 08:13:57 by uisroilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	ft_check_each_charac(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] == '0' || str[i] == '1' || str[i] == 'N'
				|| str[i] == 'S' || str[i] == 'E'
				|| str[i] == 'W' || str[i] == ' '))
			return (1);
		i++;
	}
	return (0);
}

int	ft_check_starting_point(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == 'N' || str[i] == 'S' || str[i] == 'E' || str[i] == 'W')
			count++;
		i++;
	}
	return (count);
}

int	ft_check_elements(t_base base)
{
	int	sum;

	sum = 0;
	while (base.real_map)
	{
		sum += ft_check_starting_point(base.real_map->str);
		if (ft_check_each_charac(base.real_map->str))
			return (1);
		base.real_map = base.real_map->next;
	}
	if (sum != 1)
		return (1);
	return (0);
}

int	check_map_after_map(t_base base)
{
	while (base.real_map)
	{
		if (ft_strcmp(base.real_map->str, "") == 0 && (base.real_map->next))
			return (1);
		base.real_map = base.real_map->next;
	}
	return (0);
}

int	get_real_map(t_base *base)
{
	ft_get_real_map(base);
	ft_remove_new_line(*base);
	if (ft_check_elements(*base))
	{
		printf("ress1\n");
		return (1);
	}
	if (check_map_after_map(*base))
	{
		printf("ress2\n");
		return (1);
	}
	if (check_map_border(*base))
	{
		printf("ress3\n");
		return (1);
	}
	if (check_zero_round(*base))
		return (1);
	return (0);
}
