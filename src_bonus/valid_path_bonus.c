/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlova <vkozlova@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 21:08:24 by vkozlova          #+#    #+#             */
/*   Updated: 2023/10/01 21:08:24 by vkozlova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

int	find_position(t_map **map, char elem, char **array)
{
	int	i;
	int	j;

	j = 0;
	while (j < (*map)->height)
	{
		i = 0;
		while (i < (*map)->width)
		{
			if (array[j][i] == elem)
			{
				(*map)->start_x = i;
				(*map)->start_y = j;
				return (1);
			}
			i++;
		}
		j++;
	}
	return (0);
}

void	check_edge(char *c, t_map **map);

void	look_around_one_edge(t_map **map)
{
	int	x;
	int	y;

	x = (*map)->start_x;
	y = (*map)->start_y;
	check_edge(&((*map)->path[y][x + 1]), map);
	check_edge(&((*map)->path[y][x - 1]), map);
	check_edge(&((*map)->path[y + 1][x]), map);
	check_edge(&((*map)->path[y - 1][x]), map);
	(*map)->path[y][x] = '*';
}

void	check_edge(char *c, t_map **map)
{
	if (*c == '0')
		*c = '.';
	else if (*c == 'C')
	{
		(*map)->found_collectible++;
		*c = '.';
	}
	else if (*c == 'E')
	{
		(*map)->found_exit++;
	}
}

void	check_validity(t_map **map)
{
	int	not_end;

	not_end = find_position(map, 'P', (*map)->path);
	look_around_one_edge(map);
	while (not_end)
	{
		not_end = find_position(map, '.', (*map)->path);
		look_around_one_edge(map);
	}
	if ((*map)->found_collectible != (*map)->collectible
		|| !(*map)->found_exit)
		clean_and_exit("Map is invalid", map);
	find_position(map, 'P', (*map)->map);
}
