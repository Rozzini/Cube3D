/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_direction_value.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabdoush <gabdoush@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 10:50:56 by uisroilo          #+#    #+#             */
/*   Updated: 2022/12/30 03:54:33 by gabdoush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

char	*ft_remove_nl(char *str)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = malloc(sizeof(char) * ft_strlen(str) + 1);
	while (str[i])
	{
		if (str[i] == '\n')
			break ;
		tmp[i] = str[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

int	ft_check_xpm(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	if (i > 4 && str[i - 1] == 'm' && str[i - 2] == 'p'
		&& str[i - 3] == 'x' && str[i - 4] == '.')
		return (0);
	return (1);
}

int	ft_check_direction_value(t_base base)
{
	int		tmp;

	while (base.t_map_content)
	{
		if (ft_strcmp(base.t_map_content->name, "C") != 0
			&& ft_strcmp(base.t_map_content->name, "F") != 0)
		{
			tmp = open(base.t_map_content->value, O_RDONLY);
			if (tmp == -1)
				return (1);
			if (ft_check_xpm(base.t_map_content->value) && tmp == -1)
				return (1);
			close(tmp);
		}
		base.t_map_content = base.t_map_content->next;
	}
	return (0);
}
