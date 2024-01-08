/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlova <vkozlova@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 14:59:40 by vkozlova          #+#    #+#             */
/*   Updated: 2023/09/28 14:59:40 by vkozlova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"
#include <stdlib.h>
#include "../minilibx-linux/mlx.h"

void	clean_stack(t_stack **stack)
{
	t_stack	*temp;

	while (*stack)
	{
		temp = (*stack)->next;
		if ((*stack)->str)
			free((*stack)->str);
		free((*stack));
		*stack = temp;
	}
}

void	clean_string_array(char **array, int height)
{
	int	i;

	i = 0;
	while (i < height)
		free(array[i++]);
	free(array);
}

void	clean_map(t_map **map)
{
	clean_stack(&((*map)->stack));
	if ((*map)->path)
		clean_string_array((*map)->path, (*map)->height);
	if ((*map)->map)
		clean_string_array((*map)->map, (*map)->height);
	if ((*map)->mlx_window)
		mlx_destroy_window((*map)->mlx_ptr, (*map)->mlx_window);
	if ((*map)->img_ptr)
		mlx_destroy_image((*map)->mlx_ptr, (*map)->img_ptr);
	if ((*map)->mlx_ptr)
	{
		mlx_destroy_display((*map)->mlx_ptr);
		free((*map)->mlx_ptr);
	}
	free(*map);
}

void	clean_and_exit(char *message, t_map **map)
{
	if (*map)
		clean_map(map);
	exit_with_error(message);
}

int	clean_and_exit_no_error(t_map **map)
{
	if (*map)
		clean_map(map);
	exit(1);
}
