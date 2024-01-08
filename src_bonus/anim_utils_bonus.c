/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlova <vkozlova@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 13:31:04 by vkozlova          #+#    #+#             */
/*   Updated: 2023/10/20 13:31:04 by vkozlova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

int	rotate(t_stack **stack)
{
	t_stack	*second;
	t_stack	*first;
	t_stack	*last;

	if (*stack && (*stack)->next)
	{
		second = (*stack)->next;
		first = (*stack);
		last = ft_stcklast(*stack);
		last->next = first;
		first->prev = last;
		first->next = NULL;
		(*stack) = second;
		second->prev = NULL;
	}
	return (1);
}

void	create_anim_stack(t_map **map)
{
	char	*enemy;
	char	*naked_mine;
	char	*bomb;

	enemy = "textures/mine32.xpm";
	naked_mine = "textures/naked_mine.xpm";
	bomb = "textures/bomb.xpm";
	(*map)->anim = (ft_stcknew(enemy));
	ft_stckadd_back(&(*map)->anim, ft_stcknew(naked_mine));
	ft_stckadd_back(&(*map)->anim, ft_stcknew(bomb));
	ft_stckadd_back(&(*map)->anim, ft_stcknew(naked_mine));
}

int	count_enemies(t_map **map)
{
	int	x;
	int	y;
	int	enemies;

	y = 0;
	enemies = 0;
	while (y < (*map)->height)
	{
		x = 0;
		while (x < (*map)->width)
		{
			if ((*map)->map[y][x] == 'M')
				enemies++;
			x++;
		}
		y++;
	}
	return (enemies);
}

void	create_enemy(t_map **map, int x, int y, int enemies)
{
	(*map)->enemy_array[enemies - 1] = malloc(sizeof(t_enemy));
	if (!(*map)->enemy_array[enemies - 1])
		clean_and_exit("Error of malloc", map);
	(*map)->enemy_array[enemies - 1]->x = x;
	(*map)->enemy_array[enemies - 1]->y = y;
}

void	find_enemies(t_map **map)
{
	int		x;
	int		y;
	int		enemies;

	y = 0;
	enemies = count_enemies(map);
	(*map)->enemy_array = malloc(sizeof(t_enemy) * enemies);
	if (!(*map)->enemy_array)
		clean_and_exit("Error of malloc", map);
	while (y < (*map)->height)
	{
		x = 0;
		while (x < (*map)->width)
		{
			if ((*map)->map[y][x] == 'M')
			{
				create_enemy(map, x, y, enemies);
				enemies--;
			}
			x++;
		}
		y++;
	}
}
