/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkozlova <vkozlova@student.42wolfsburg.d>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 23:14:24 by vkozlova          #+#    #+#             */
/*   Updated: 2023/09/27 23:14:24 by vkozlova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/header/libft.h"

# define TEXTURE		32
# define WALL			"textures/wall32.xpm"
# define FLOOR			"textures/black32.xpm"
# define COLLECTIBLE	"textures/coin32.xpm"
# define DOOR			"textures/door32.xpm"
# define CHARACTER		"textures/chudik32.xpm"
# define ENEMY			"textures/mine32.xpm"
# define NAKED_MINE		"textures/naked_mine.xpm"
# define BOMB			"textures/bomb.xpm"
# define DEAD			"textures/dead32.xpm"

typedef struct s_stack
{
	char			*str;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

typedef struct s_enemy
{
	int	x;
	int	y;
}	t_enemy;

typedef struct s_map
{
	int				exit;
	int				start;
	int				collectible;
	int				height;
	int				width;
	struct s_stack	*stack;
	char			**map;
	char			**path;
	int				start_x;
	int				start_y;
	int				found_collectible;
	int				found_exit;

	void			*mlx_ptr;
	void			*mlx_window;
	void			*img_ptr;

	int				moves;

	t_stack			*anim;
	t_enemy			**enemy_array;
	int				dead;
}	t_map;

t_stack	*ft_stcknew(char *content);
void	ft_stckadd_front(t_stack **stck, t_stack *new);
void	ft_stckadd_back(t_stack **stack, t_stack *new);
t_stack	*ft_stcklast(t_stack *stack);
int		ft_stcksize(t_stack *stck);

void	clean_stack(t_stack **stack);
void	clean_map(t_map **map);
void	exit_with_error(char *message);
void	clean_and_exit(char *message, t_map **map);
int		clean_and_exit_no_error(t_map **map);

void	check_middle_line(char *line, t_map **map);
void	check_first_last_line(char *line, t_map **mp);
int		check_width(int width, char *line);
t_map	*check_map(char *map_name);

t_map	*create_map(void);

char	**initialize_map(t_map **map);
char	**malloc_map(t_map **map);

void	check_validity(t_map **map);

void	init_window(t_map **map);

void	draw(t_map **map);
void	check_exit(t_map **map, int y, int x);

void	up(t_map **map);
void	down(t_map **map);
void	left(t_map **map);
void	right(t_map **map);

void	print_movements(t_map **map);

int		ft_close_game(t_map **map);

int		anim(t_map **map);

void	find_enemies(t_map **map);
int		count_enemies(t_map **map);
int		rotate(t_stack **stack);
void	create_anim_stack(t_map **map);

#endif