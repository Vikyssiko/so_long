NAME		=	so_long

LIBFT		=	libft.a

LIBFT_DIR	=	libft

MLX_DIR		=	minilibx-linux

BONUS_DIR	=	src_bonus

BONUS_SRCS	=	$(BONUS_DIR)/anim_bonus.c \
				$(BONUS_DIR)/check_line_bonus.c \
				$(BONUS_DIR)/clean_bonus.c \
				$(BONUS_DIR)/anim_utils_bonus.c \
				$(BONUS_DIR)/initialize_map_bonus.c \
				$(BONUS_DIR)/main_bonus.c \
				$(BONUS_DIR)/move_bonus.c \
				$(BONUS_DIR)/print_movements_bonus.c \
				$(BONUS_DIR)/stack_bonus.c \
				$(BONUS_DIR)/valid_path_bonus.c \
				$(BONUS_DIR)/window_bonus.c

BONUS_OBJS	=	$(BONUS_SRCS:.c=.o)

SRC_DIR		=	src

SRCS		=	$(SRC_DIR)/check_line.c \
				$(SRC_DIR)/clean.c \
				$(SRC_DIR)/initialize_map.c \
				$(SRC_DIR)/main.c \
				$(SRC_DIR)/move.c \
				$(SRC_DIR)/stack.c \
				$(SRC_DIR)/valid_path.c \
				$(SRC_DIR)/window.c

OBJS		=	$(SRCS:.c=.o)

DEPS		=	header

CFLAGS		+=	-Wall \
				-Werror \
				-Wextra \
				-I$(DEPS)

MLX_FLAGS	=	-Lminilibx-linux \
				-lmlx_Linux \
				-lX11 \
				-lXext

all: $(NAME)

$(NAME): $(OBJS)
		@make -C $(LIBFT_DIR)
		@make -C $(MLX_DIR)
		@make bonus -C $(LIBFT_DIR)
		@cc $(CFLAGS) $(OBJS) $(LIBFT_DIR)/$(LIBFT) -o $(NAME) $(MLX_FLAGS)

clean:
		@make clean -C $(LIBFT_DIR)
		@make clean -C $(MLX_DIR)
		@rm -f $(OBJS)
		@rm -f $(BONUS_OBJS)

fclean: clean
		@make fclean -C $(LIBFT_DIR)
		@rm -f $(NAME)

re: fclean
		@make all

bonus: $(BONUS_OBJS)
		@make -C $(LIBFT_DIR)
		@make -C $(MLX_DIR)
		@make bonus -C $(LIBFT_DIR)
		@cc $(CFLAGS) $(BONUS_OBJS) $(LIBFT_DIR)/$(LIBFT) -o $(NAME) $(MLX_FLAGS)

.PHONY: re fclean clean all bonus


