NAME = lib.a
CPP_FLAGS = -Wall -Wextra -Werror
CPP = c++

SRCS = # No extra srcs
OBJS = $(SRCS:.cpp=.o)

LIBFT_DIR = ./libft
PRINTF_DIR = ./ft_printf

LIBFT = $(LIBFT_DIR)/libft.a
PRINTF = $(PRINTF_DIR)/libftprintf.a

all: $(LIBFT) $(PRINTF) $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR) bonus

$(PRINTF):
	@$(MAKE) -C $(PRINTF_DIR) all

$(NAME): $(LIBFT) $(PRINTF)
	@if [ -s $(LIBFT) ] && [ -s $(PRINTF) ]; then \
		cp $(LIBFT) $(NAME); \
		ar rcs $(NAME) $(PRINTF); \
		echo "\033[1;32m ✅ [lib.a created]\033[0m"; \
	else \
		echo "\033[1;31m ⚠️  [lib.a not created: one or more libraries are empty]\033[0m"; \
	fi

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(PRINTF_DIR) clean
	@echo "\033[0;31m 🗑️  [Intermediate objects deleted]\033[0m"

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(PRINTF_DIR) fclean
	@echo "\033[0;31m 🗑️  [lib.a deleted]\033[0m"

re: fclean all

.SILENT: $(OBJS)

.PHONY: all clean fclean re
