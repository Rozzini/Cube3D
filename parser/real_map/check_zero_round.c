/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_zero_round.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uisroilo <uisroilo@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 12:50:52 by uisroilo          #+#    #+#             */
/*   Updated: 2022/12/03 15:11:09 by uisroilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	find_zero_check(t_map_real *real_map, char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '0' || str[i] == 'N'
			|| str[i] == 'S' || str[i] == 'E' || str[i] == 'W')
		{
			if (str[i + 1] == ' ')
				return (1);
			if (real_map->prev && (i > ft_strlen(real_map->prev->str)))
				return (1);
			else if (real_map->prev && real_map->prev->str[i] == ' ')
				return (1);
			if (real_map->next && (i > ft_strlen(real_map->next->str)))
				return (1);
			else if (real_map->next && real_map->next->str[i] == ' ')
				return (1);
		}
		i++;
	}
	return (0);
}

int	check_zero_round(t_base base)
{
	while (base.real_map)
	{
		if (find_zero_check(base.real_map, base.real_map->str))
			return (1);
		base.real_map = base.real_map->next;
	}
	return (0);
}
