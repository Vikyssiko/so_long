/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlova <vkozlova@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 23:08:24 by vkozlova          #+#    #+#             */
/*   Updated: 2023/09/27 23:08:24 by vkozlova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/header/libft.h"
#include "../header/so_long.h"
#include <stdlib.h>
#include <stdio.h>

int	main(int args, char *argv[])
{
	t_map	*map;

	if (args != 2)
		exit_with_error("Specify one map");
	map = check_map(argv[1]);
	map->map = initialize_map(&map);
	map->path = initialize_map(&map);
	check_validity(&map);
	find_enemies(&map);
	create_anim_stack(&map);
	init_window(&map);
}
