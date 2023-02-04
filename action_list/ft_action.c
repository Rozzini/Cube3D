/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_action.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uisroilo <uisroilo@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 17:12:44 by uisroilo          #+#    #+#             */
/*   Updated: 2022/11/28 12:24:07 by uisroilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_print_list(t_base data)
{
	while (data.map)
	{
		printf("RESUlt is = %s", data.map->line);
		data.map = data.map->next;
	}
}

void	ft_print_map_cont(t_base data)
{
	while (data.t_map_content)
	{
		printf("is = %s", data.t_map_content->name);
		printf(" %s\n", data.t_map_content->value);
		data.t_map_content = data.t_map_content->next;
	}
}
