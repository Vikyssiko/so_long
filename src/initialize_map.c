/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlova <vkozlova@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 19:39:24 by vkozlova          #+#    #+#             */
/*   Updated: 2023/10/19 19:39:24 by vkozlova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "../libft/header/libft.h"
#include "../header/so_long.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void	exit_with_error(char *message)
{
	printf("Error\n");
	printf("%s\n", message);
	exit(1);
}

t_map	*create_map(void)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		exit_with_error("Error of malloc");
	map->path = NULL;
	map->map = NULL;
	map->stack = NULL;
	map->height = 0;
	map->width = 0;
	map->start = 0;
	map->exit = 0;
	map->collectible = 0;
	map->start_x = 0;
	map->start_y = 0;
	map->found_collectible = 0;
	map->found_exit = 0;
	map->moves = 0;
	map->mlx_ptr = NULL;
	map->mlx_window = NULL;
	map->img_ptr = NULL;
	map->dead = 0;
	map->anim = NULL;
	map->enemy_array = NULL;
	return (map);
}

char	**malloc_map(t_map **map)
{
	char	**map_array;
	int		j;

	j = 0;
	map_array = malloc((*map)->height * sizeof(char *));
	if (!map_array)
		clean_and_exit("Error of malloc", map);
	while (j < (*map)->height)
	{
		map_array[j] = malloc((*map)->width);
		if (!(map_array[j]))
			clean_and_exit("Error of malloc", map);
		j++;
	}
	return (map_array);
}

char	**initialize_map(t_map **map)
{
	t_stack	*temp;
	int		i;
	int		j;
	char	**array;

	j = 0;
	temp = (*map)->stack;
	(*map)->width = ft_strlen(temp->str) - 1;
	(*map)->height = ft_stcksize((*map)->stack);
	array = malloc_map(map);
	while ((*map)->stack)
	{
		i = 0;
		while (i < (*map)->width)
		{
			array[j][i] = (*map)->stack->str[i];
			i++;
		}
		(*map)->stack = (*map)->stack->next;
		j++;
	}
	(*map)->stack = temp;
	return (array);
}
