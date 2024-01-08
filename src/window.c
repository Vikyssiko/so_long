/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlova <vkozlova@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 17:07:33 by vkozlova          #+#    #+#             */
/*   Updated: 2023/10/04 17:07:33 by vkozlova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"
#include "../minilibx-linux/mlx.h"
#include <X11/keysym.h>
#include <X11/X.h>

int	handle_input(int keysym, t_map **map)
{
	if (keysym == XK_Escape)
		clean_and_exit_no_error(map);
	if (!(*map)->dead)
	{
		if (keysym == XK_w)
			up(map);
		else if (keysym == XK_s)
			down(map);
		else if (keysym == XK_a)
			left(map);
		else if (keysym == XK_d)
			right(map);
	}
	return (0);
}

int	ft_close_game(t_map **map)
{
	clean_and_exit_no_error(map);
	return (0);
}

void	put_texture_to_image(t_map **map, int y, int x)
{
	int	size;

	size = TEXTURE;
	if ((*map)->img_ptr)
		mlx_destroy_image((*map)->mlx_ptr, (*map)->img_ptr);
	if ((*map)->map[y][x] == '1')
		(*map)->img_ptr = mlx_xpm_file_to_image((*map)->mlx_ptr,
				WALL, &size, &size);
	else if ((*map)->map[y][x] == 'C')
		(*map)->img_ptr = mlx_xpm_file_to_image((*map)->mlx_ptr,
				COLLECTIBLE, &size, &size);
	else if ((*map)->map[y][x] == 'P' && (*map)->dead)
		(*map)->img_ptr = mlx_xpm_file_to_image((*map)->mlx_ptr,
				DEAD, &size, &size);
	else if ((*map)->map[y][x] == 'P')
		(*map)->img_ptr = mlx_xpm_file_to_image((*map)->mlx_ptr,
				CHARACTER, &size, &size);
	else if ((*map)->map[y][x] == 'E')
		(*map)->img_ptr = mlx_xpm_file_to_image((*map)->mlx_ptr,
				DOOR, &size, &size);
	else
		(*map)->img_ptr = mlx_xpm_file_to_image((*map)->mlx_ptr,
				FLOOR, &size, &size);
	if (!(*map)->img_ptr)
		clean_and_exit("Failed to read image", map);
}

void	draw(t_map **map)
{
	int	x;
	int	y;
	int	x_size;
	int	y_size;

	y = 0;
	while (y < ((*map)->height))
	{
		x = 0;
		while (x < ((*map)->width))
		{
			x_size = (x) * TEXTURE;
			y_size = (y) * TEXTURE;
			put_texture_to_image(map, y, x);
			mlx_put_image_to_window((*map)->mlx_ptr,
				(*map)->mlx_window, (*map)->img_ptr,
				x_size, y_size);
			x++;
		}
		y++;
	}
}

void	init_window(t_map **map)
{
	(*map)->mlx_ptr = mlx_init();
	if (!(*map)->mlx_ptr)
		clean_and_exit("Error with malloc", map);
	(*map)->mlx_window = mlx_new_window((*map)->mlx_ptr,
			(*map)->width * TEXTURE, (*map)->height * TEXTURE,
			"so_long");
	if (!(*map)->mlx_window)
		clean_and_exit("Error with malloc", map);
	draw(map);
	mlx_hook((*map)->mlx_window, KeyPress, KeyPressMask, handle_input, map);
	mlx_hook((*map)->mlx_window,
		DestroyNotify, ButtonPressMask, clean_and_exit_no_error, map);
	mlx_loop((*map)->mlx_ptr);
}
