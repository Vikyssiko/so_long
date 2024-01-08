/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlova <vkozlova@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 23:33:41 by vkozlova          #+#    #+#             */
/*   Updated: 2023/10/08 23:33:41 by vkozlova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	up(t_map **map)
{
	check_exit(map, (*map)->start_y - 1, (*map)->start_x);
	if ((*map)->map[(*map)->start_y - 1][(*map)->start_x] == 'C')
		(*map)->collectible--;
	if ((*map)->map[(*map)->start_y - 1][(*map)->start_x] == 'M')
	{
		(*map)->moves++;
		(*map)->dead = 1;
	}
	if ((*map)->map[(*map)->start_y - 1][(*map)->start_x] == '0' ||
		(*map)->map[(*map)->start_y - 1][(*map)->start_x] == 'C')
	{
		(*map)->map[(*map)->start_y][(*map)->start_x] = '0';
		(*map)->map[(*map)->start_y - 1][(*map)->start_x] = 'P';
		(*map)->start_y--;
		(*map)->moves++;
		ft_printf("Moves: %i\n", (*map)->moves);
	}
	draw(map);
}

void	down(t_map **map)
{
	check_exit(map, (*map)->start_y + 1, (*map)->start_x);
	if ((*map)->map[(*map)->start_y + 1][(*map)->start_x] == 'C')
		(*map)->collectible--;
	if ((*map)->map[(*map)->start_y + 1][(*map)->start_x] == 'M')
	{
		(*map)->moves++;
		(*map)->dead = 1;
	}
	if ((*map)->map[(*map)->start_y + 1][(*map)->start_x] == '0' ||
		(*map)->map[(*map)->start_y + 1][(*map)->start_x] == 'C')
	{
		(*map)->map[(*map)->start_y][(*map)->start_x] = '0';
		(*map)->map[(*map)->start_y + 1][(*map)->start_x] = 'P';
		(*map)->start_y++;
		(*map)->moves++;
		ft_printf("Moves: %i\n", (*map)->moves);
	}
	draw(map);
}

void	left(t_map **map)
{
	check_exit(map, (*map)->start_y, (*map)->start_x - 1);
	if ((*map)->map[(*map)->start_y][(*map)->start_x - 1] == 'C')
		(*map)->collectible--;
	if ((*map)->map[(*map)->start_y][(*map)->start_x - 1] == 'M')
	{
		(*map)->moves++;
		(*map)->dead = 1;
	}
	if ((*map)->map[(*map)->start_y][(*map)->start_x - 1] == '0' ||
		(*map)->map[(*map)->start_y][(*map)->start_x - 1] == 'C')
	{
		(*map)->map[(*map)->start_y][(*map)->start_x] = '0';
		(*map)->map[(*map)->start_y][(*map)->start_x - 1] = 'P';
		(*map)->start_x--;
		(*map)->moves++;
		ft_printf("Moves: %i\n", (*map)->moves);
	}
	draw(map);
}

void	right(t_map **map)
{
	check_exit(map, (*map)->start_y, (*map)->start_x + 1);
	if ((*map)->map[(*map)->start_y][(*map)->start_x + 1] == 'C')
		(*map)->collectible--;
	if ((*map)->map[(*map)->start_y][(*map)->start_x + 1] == 'M')
	{
		(*map)->moves++;
		(*map)->dead = 1;
	}
	if ((*map)->map[(*map)->start_y][(*map)->start_x + 1] == '0' ||
		(*map)->map[(*map)->start_y][(*map)->start_x + 1] == 'C')
	{
		(*map)->map[(*map)->start_y][(*map)->start_x] = '0';
		(*map)->map[(*map)->start_y][(*map)->start_x + 1] = 'P';
		(*map)->start_x++;
		(*map)->moves++;
		ft_printf("Moves: %i\n", (*map)->moves);
	}
	draw(map);
}

void	check_exit(t_map **map, int y, int x)
{
	if ((*map)->map[y][x] == 'E' && (*map)->collectible == 0)
	{
		(*map)->map[y][x] = 'P';
		(*map)->moves++;
		clean_and_exit_no_error(map);
	}
}
