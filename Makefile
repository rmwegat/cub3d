NAME = cub3d

CC = cc

CFLAGS = -Wall -Wextra -Werror -Ofast -o3

SRCS =	src/main.c \

OBJS_DIR = objs
OBJS = $(SRCS:src/%.c=$(OBJS_DIR)/%.o)

MLXFLAGS = -framework Cocoa -framework OpenGL -framework IOKit -lglfw
MLXINCLUDE = include/MLX42/build/libmlx42.a -Iinclude -lglfw
MLX_REPO_URL = https://github.com/codam-coding-college/MLX42.git

all: MLX42 $(NAME)

$(NAME): $(OBJS) MLX42
	@$(CC) $(OBJS) $(MLXFLAGS) $(CFLAGS) $(MLXINCLUDE) -o $(NAME)
	@echo "\033[1;32m ✅ [$(NAME) created]\033[0m"

$(OBJS_DIR)/%.o: src/%.c
	@$(CC) $(CFLAGS) -c $< -o $@

MLX42:
	@if [ ! -d "include/MLX42" ]; then \
		cd include && git clone $(MLX_REPO_URL) MLX42; \
		cd MLX42 && cmake -B build && cd build && make && cd ../..; \
		echo "\033[1;32m ✅ [MLX42 installed]\033[0m"; \
	else \
		echo "\033[1;32m ✅ [MLX42 already found]\033[0m"; \
	fi

MLXR:
	@rm -rf include/MLX42
	@echo "\033[0;31m 🗑️  [MLX42 removed]\033[0m"

clean:
	@rm -f $(OBJS)
	@echo "\033[0;31m 🗑️  [OBJS deleted]\033[0m"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[0;31m 🗑️  [$(NAME) deleted]\033[0m"

re: fclean all

.SILENT: $(OBJS)

.PHONY: all clean fclean re MLX42 MLXR
