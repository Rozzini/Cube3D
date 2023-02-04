/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uisroilo <uisroilo@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 17:25:14 by gabdoush          #+#    #+#             */
/*   Updated: 2022/12/01 10:17:47 by uisroilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../cub3d.h"


/*=======================================================================*/
void	append(t_map **head_ref, char *str)
{
	t_map	*new_node;
	t_map	*last;
	
	new_node = (t_map *)malloc(sizeof(t_map));
	last = *head_ref;
	new_node->line = ft_strdup(str);
	new_node->next = NULL;
	if (*head_ref == NULL)
	{
		new_node->prev = NULL;
		*head_ref = new_node;
		return;
	} 
	while (last->next != NULL)
		last = last->next;
	last->next = new_node;
	new_node->prev = last;
}

void	append_sec(t_map_real **head_ref, char *str)
{
	t_map_real	*new_node;
	t_map_real	*last;
	
	new_node = (t_map_real *)malloc(sizeof(t_map_real));
	last = *head_ref;
	new_node->str = ft_strdup(str);
	new_node->next = NULL;
	if (*head_ref == NULL)
	{
		new_node->prev = NULL;
		*head_ref = new_node;
		return;
	} 
	while (last->next != NULL)
		last = last->next;
	last->next = new_node;
	new_node->prev = last;
}

/*=======================================================================*/
void	ft_add_back(char *name, char *value, t_map_cont **head_ref)
{
	t_map_cont	*new_node;
	t_map_cont	*last;
	
	new_node = (t_map_cont *)malloc(sizeof(t_map_cont));
	last = *head_ref;
	new_node->name = ft_strdup(name);
	new_node->value = ft_strdup(value);
	new_node->next = NULL;
	if (*head_ref == NULL)
	{
		new_node->prev = NULL;
		*head_ref = new_node;
		return;
	} 
	while (last->next != NULL)
		last = last->next;
	last->next = new_node;
	new_node->prev = last;
}

/*=======================================================================*/
void	delete_list(t_map *map)
{
	t_map* temp;
	
	while (map != NULL)
	{
		temp = map;
		map = map->next;
		if (temp)
		{
			free(temp->line);
			temp->line = NULL;
			free(temp);
			temp = NULL;
		}
		temp = NULL;
	}
}

void	delete_list2(t_map_real *map)
{
	t_map_real* temp;
	
	while (map != NULL)
	{
		temp = map;
		map = map->next;
		if (temp)
		{
			free(temp->str);
			temp->str = NULL;
			free(temp);
			temp = NULL;
		}
		temp = NULL;
	}
}

void	delete_list3(t_map_cont *map)
{
	t_map_cont* temp;
	
	while (map != NULL)
	{
		temp = map;
		map = map->next;
		if (temp)
		{
			free(temp->name);
			free(temp->value);
			temp->name = NULL;
			temp->value = NULL;
			free(temp);
			temp = NULL;
		}
		temp = NULL;
	}
}

/*=======================================================================*/
/* Forword printing: */
// void print_list(t_map *map)
// {
// 	t_map   *last;

// 	while (map != NULL)
// 	{
// 		printf("%s", map->line);
// 		last = map;
// 		map = map->next;
// 	}
// }

/*=======================================================================*/