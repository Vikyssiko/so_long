/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_middle_line.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlova <vkozlova@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 15:01:24 by vkozlova          #+#    #+#             */
/*   Updated: 2023/09/28 15:01:24 by vkozlova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"
//#include "../libft/header/libft.h"
#include <fcntl.h>

int	check_width(int width, char *line)
{
	int	len;

	len = (int)ft_strlen(line);
	if ((len - 1 == width && line[len - 1] == '\n')
		|| (len == width && line[len - 1] != '\n'))
		return (1);
	return (0);
}

void	check_lines(t_map **map)
{
	t_stack	*temp_stack;

	temp_stack = (*map)->stack;
	check_first_last_line(temp_stack->str, map);
	while (temp_stack && temp_stack->str)
	{
		check_middle_line(temp_stack->str, map);
		temp_stack = temp_stack->next;
	}
	check_first_last_line(ft_stcklast((*map)->stack)->str, map);
}

t_map	*check_map(char *map_name)
{
	int		fd;
	char	*line;
	t_map	*map;
	t_stack	*stack;

	fd = open(map_name, O_RDONLY);
	line = get_next_line(fd);
	map = create_map();
	map->stack = ft_stcknew(line);
	stack = map->stack;
	while (line)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		ft_stckadd_back(&stack, ft_stcknew(line));
	}
	check_lines(&map);
	if (!(map)->collectible)
		clean_and_exit("There is no collectible", &map);
	if (!(map)->exit || map->exit != 1)
		clean_and_exit("There should be one exit", &map);
	if (!(map)->start || map->start != 1)
		clean_and_exit("There should be one start position", &map);
	return (map);
}

void	check_middle_line(char *line, t_map **map)
{
	int	i;
	int	width;

	i = 0;
	width = ft_strlen((*map)->stack->str) - 1;
	if (!check_width(width, line))
		clean_and_exit("Map is not rectangular", map);
	if (line[0] != '1' || line[width - 1] != '1')
		clean_and_exit("Map should be surrounded by walls", map);
	while (i < width)
	{
		if (line[i] != '1' && line[i] != '0' && line[i] != 'C'
			&& line[i] != 'E' && line[i] != 'P' && line[i] != 'M')
			clean_and_exit("Some symbols are not allowed", map);
		if (line[i] == 'C')
			(*map)->collectible++;
		if (line[i] == 'E')
			(*map)->exit++;
		if (line[i] == 'P')
			(*map)->start++;
		i++;
	}
}

void	check_first_last_line(char *line, t_map **map)
{
	int	i;
	int	width;

	i = 0;
	if (!((*map)->stack) || !((*map)->stack->str))
		clean_and_exit("Map is empty", map);
	width = ft_strlen((*map)->stack->str) - 1;
	while (i < width)
	{
		if (line[i] != '1')
			clean_and_exit("Map should be surrounded by walls", map);
		i++;
	}
}
