NAME = cub3D

CC = cc

CFLAGS = -Wall -Wextra -Werror -Ofast -o3 -fsanitize=address,undefined -g

VPATH = src:src/parsing:src/game

SRCS = map_to_array.c \
	main.c \
	get_colors.c \
	process_config.c \
	init.c \
	memory_management.c \
	textures.c \
	game.c \
	color_extractor.c \
	player_movement.c \
	ray_caster.c \

OBJS_DIR = objs
OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))

MLX_LINUX_FLAGS	= -ldl -pthread -lm
MLX_MAC_FLAGS	= -framework Cocoa -framework OpenGL -framework IOKit
MLXINCLUDE = include/MLX42/build/libmlx42.a -Iinclude -lglfw
MLX_REPO_URL = https://github.com/codam-coding-college/MLX42.git

LIBFT_DIR = include/libft
LIBFT = $(LIBFT_DIR)/libft.a

UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S), Linux)
	MLX_FLAGS := $(MLX_LINUX_FLAGS)
else ifeq ($(UNAME_S), Darwin)
	MLX_FLAGS := $(MLX_MAC_FLAGS)
else
	$(error Unsupported operating system: $(UNAME_S))
endif

all: MLX42 libft $(NAME)

$(NAME): $(OBJS) MLX42 libft
	@$(CC) $(OBJS) $(MLX_FLAGS) $(CFLAGS) $(MLXINCLUDE) $(LIBFT) -o $(NAME)
	@echo "\033[1;32m ✅ [$(NAME) created]\033[0m"

$(OBJS_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

MLX42:
	@if [ ! -d "include/MLX42" ]; then \
		cd include && git clone $(MLX_REPO_URL) MLX42; \
		cd MLX42 && cmake -B build && cd build && make && cd ../..; \
		echo "\033[1;32m ✅ [MLX42 installed]\033[0m"; \
	else \
		echo "\033[1;32m ✅ [MLX42 already found]\033[0m"; \
	fi

libft:
	@$(MAKE) -C $(LIBFT_DIR)

MLXR:
	@rm -rf include/MLX42
	@echo "\033[0;31m 🗑️  [MLX42 removed]\033[0m"

clean:
	@rm -f $(OBJS)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@echo "\033[0;31m 🗑️  [OBJS deleted]\033[0m"

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@echo "\033[0;31m 🗑️  [$(NAME) deleted]\033[0m"

re: fclean all

.SILENT: $(OBJS)

.PHONY: all clean fclean re MLX42 MLXR libft
