/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlova <vkozlova@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 12:44:34 by vkozlova          #+#    #+#             */
/*   Updated: 2023/10/20 12:44:34 by vkozlova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"
#include "../minilibx-linux/mlx.h"

#include <sys/time.h>

int	anim(t_map **map)
{
	int				size;
	struct timeval	tv;
	int				enemies;

	size = TEXTURE;
	gettimeofday(&tv, NULL);
	if ((tv.tv_sec * 1000 + (tv.tv_usec / 1000)) % 350 != 0)
		return (0);
	enemies = count_enemies(map);
	while (enemies > 0)
	{
		if ((*map)->img_ptr)
			mlx_destroy_image((*map)->mlx_ptr, (*map)->img_ptr);
		(*map)->img_ptr = mlx_xpm_file_to_image((*map)->mlx_ptr,
				((*map)->anim)->str, &size, &size);
		mlx_put_image_to_window((*map)->mlx_ptr,
			(*map)->mlx_window, (*map)->img_ptr,
			(*map)->enemy_array[enemies - 1]->x * size,
			(*map)->enemy_array[enemies - 1]->y * size);
		enemies--;
	}
	rotate(&(*map)->anim);
	return (0);
}
