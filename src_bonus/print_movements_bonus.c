/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_movements.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlova <vkozlova@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 18:41:14 by vkozlova          #+#    #+#             */
/*   Updated: 2023/10/19 18:41:14 by vkozlova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"
#include "../minilibx-linux/mlx.h"

char	*ft_strcat(char *dst, char *src)
{
	char	*result;
	int		i;
	int		j;

	i = 0;
	j = 0;
	result = malloc(ft_strlen(dst) + ft_strlen(src) + 1);
	if (!result)
		return (NULL);
	while (dst[j])
		result[i++] = dst[j++];
	j = 0;
	while (src[j])
		result[i++] = src[j++];
	result[i] = '\0';
	free(src);
	return (result);
}

void	print_movements(t_map **map)
{
	char	*str;
	int		x;
	int		size;

	size = TEXTURE;
	x = 3;
	while (x < ((*map)->width))
	{
		if ((*map)->img_ptr)
			mlx_destroy_image((*map)->mlx_ptr, (*map)->img_ptr);
		(*map)->img_ptr = mlx_xpm_file_to_image((*map)->mlx_ptr,
				FLOOR, &size, &size);
		mlx_put_image_to_window((*map)->mlx_ptr,
			(*map)->mlx_window, (*map)->img_ptr,
			x * TEXTURE - 10, (*map)->height * TEXTURE);
		x++;
	}
	str = ft_itoa((*map)->moves);
	mlx_string_put((*map)->mlx_ptr, (*map)->mlx_window, 90,
		(*map)->height * TEXTURE + 20, 0xd7e4fa, str);
	free(str);
}
