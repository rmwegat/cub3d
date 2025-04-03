CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a
CFILES =	ft_isalnum.c ft_isprint.c ft_memcmp.c  ft_putchar_fd.c ft_split.c \
			ft_strlcat.c ft_strncmp.c ft_substr.c ft_atoi.c ft_isalpha.c \
			ft_itoa.c ft_memcpy.c  ft_putendl_fd.c ft_strchr.c  ft_strlcpy.c \
			ft_strnstr.c ft_tolower.c ft_bzero.c   ft_isascii.c ft_memcpy.c \
			ft_memmove.c ft_putnbr_fd.c  ft_strdup.c  ft_striteri.c ft_strlen.c  ft_strrchr.c \
			ft_toupper.c ft_calloc.c  ft_isdigit.c ft_memchr.c  ft_memset.c  \
			ft_putstr_fd.c  ft_strjoin.c ft_strmapi.c ft_strtrim.c \
			get_next_line.c get_next_line_utils.c
OFILES = $(CFILES:.c=.o)
BONUS =		ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c \
			ft_lstdelone.c ft_lstiter.c ft_lstlast.c \
			ft_lstmap.c ft_lstnew.c ft_lstsize.c
OBONUS = $(BONUS:.c=.o)
all: $(NAME)
$(NAME): $(OFILES)
	ar rcs $(NAME) $(OFILES)
clean:
	rm -f $(OFILES) $(OBONUS)
fclean: clean
	rm -f $(NAME)
re: fclean $(NAME)
bonus: $(OFILES) $(OBONUS)
	ar rcs $(NAME) $(OFILES) $(OBONUS)
.PHONY: all clean fclean re bonus